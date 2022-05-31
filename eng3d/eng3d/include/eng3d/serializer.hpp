// Eng3D - General purpouse game engine
// Copyright (C) 2021, Eng3D contributors
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// ----------------------------------------------------------------------------
// Name:
//      serializer.hpp
//
// Abstract:
//      Does some important stuff.
// ----------------------------------------------------------------------------

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <exception>
#include <numeric>
#include <string>
#include <vector>
#include <cstdio>
#include <type_traits>

// The purpouse of the serializer is to serialize objects onto a byte stream
// that can be transfered onto the disk or over the network.
//
// Should the object have any pointers - they would need to be converted to
// indexes accordingly for proper transmission.
class SerializerException : public std::exception {
    std::string buffer;
public:
    SerializerException(const std::string& msg) {
        buffer = msg;
    };
    virtual const char* what(void) const noexcept {
        return buffer.c_str();
    };
};

// Base class that serves as archiver, stores (in memory) the data required for
// serialization/deserialization
class Archive {
public:
    Archive() {};
    ~Archive() {};
    void copy_to(void* ptr, size_t size);
    void copy_from(const void* ptr, size_t size);
    void expand(size_t amount);
    void end_stream(void);
    void rewind(void);
    void to_file(const std::string& path);
    void from_file(const std::string& path);
    void* get_buffer(void);
    void set_buffer(void* buf, size_t size);
    size_t size(void);

    std::vector<uint8_t> buffer;
    size_t ptr = 0;
};

// A serializer (base class) which can be used to serialize objects
// and create per-object optimized classes
template<typename T>
class Serializer {
public:
    template<bool is_serialize>
    static inline void deser_dynamic(Archive&, const T*) {}
};

/// @brief Template generic (de)-serializer
/// @tparam is_serialize if true perform serialize mode, otherwise deserialize
/// @tparam T the type to (de)-serialize
template<bool is_serialize, typename T>
inline void deser_dynamic(Archive& ar, T* obj) {
    if constexpr(is_serialize) {
        Serializer<const T>::template deser_dynamic<is_serialize>(ar, obj);
    } else {
        Serializer<T>::template deser_dynamic<is_serialize>(ar, obj);
    }
}

template<typename T>
inline void serialize(Archive& ar, T* obj) {
    Serializer<const T>::template deser_dynamic<true>(ar, obj);
}

template<typename T>
inline void deserialize(Archive& ar, T* obj) {
    Serializer<T>::template deser_dynamic<false>(ar, obj);
}

// A serializer optimized to memcpy directly the element into the byte stream
// use only when the object can be copied without modification (i.e a class full of ints)
// The elements must have a fixed size for this to work.
template<typename T>
class SerializerMemcpy {
public:
    template<bool is_serialize>
    static inline void deser_dynamic(Archive& ar, T* obj) {
        if constexpr(is_serialize) {
            ar.expand(sizeof(T));
            ar.copy_from(obj, sizeof(T));
        } else {
            ar.copy_to(obj, sizeof(T));
        }
    }
};


/// @todo On some compilers a boolean can be something not a uint8_t, we should
// explicitly recast this boolean into a uint8_t to avoid problems
template<>
class Serializer<bool> : public SerializerMemcpy<bool> {};

// A class more focused on numbers :)
template<typename T>
class SerializerNumber : public SerializerMemcpy<T> {};

// Serializers for primitives only require memcpy
template<>
class Serializer<uint64_t> : public SerializerNumber<uint64_t> {};
template<>
class Serializer<uint32_t> : public SerializerNumber<uint32_t> {};
template<>
class Serializer<uint16_t> : public SerializerNumber<uint16_t> {};
template<>
class Serializer<uint8_t> : public SerializerNumber<uint8_t> {};

template<>
class Serializer<int64_t> : public SerializerNumber<int64_t> {};
template<>
class Serializer<int32_t> : public SerializerNumber<int32_t> {};
template<>
class Serializer<int16_t> : public SerializerNumber<int16_t> {};
template<>
class Serializer<int8_t> : public SerializerNumber<int8_t> {};

template<>
class Serializer<long double> : public SerializerNumber<long double> {};
template<>
class Serializer<double> : public SerializerNumber<double> {};
template<>
class Serializer<float> : public SerializerNumber<float> {};

// A serializer specialized in strings
// The serializer stores the lenght of the string and the string itself
// this is done so no errors can happen due to null stuff. (UTF-8 especially)
template<>
class Serializer<std::string> {
public:
    template<bool is_serialize>
    static inline void deser_dynamic(Archive& ar, std::string* obj) {
        if constexpr(is_serialize) {
            uint16_t len = obj->length();

            // Truncate lenght
            if(len >= 1024)
                len = 1024;

            // Put length for later deserialization (since UTF-8/UTF-16 exists)
            ::serialize(ar, &len);

            // Copy the string into the output
            if(len) {
                ar.expand(len);
                ar.copy_from(obj->c_str(), len);
            }
        } else {
            uint16_t len;

            // Obtain the lenght of the string to be read
            ::deserialize(ar, &len);
            if(len >= 1024)
                throw SerializerException("String is too lenghty");

            // Obtain the string itself
            std::unique_ptr<char[]> string = std::unique_ptr<char[]>(new char[len + 1]);
            if(len) {
                ar.copy_to(string.get(), len);
            }
            string.get()[len] = '\0';
            *obj = string.get();
        }
    }
};

// Non-contigous serializer for STL containers
// This serializer class works primarly with containers whose memory is contiguous
template<typename T, typename C>
class SerializerContainer {
public:
    template<bool is_serialize>
    static inline void deser_dynamic(Archive& ar, C* obj_group) {
        if constexpr(is_serialize) {
            uint32_t len = obj_group->size();
            ::deser_dynamic<is_serialize>(ar, &len);
            for(auto& obj : *obj_group) {
                Serializer<T>::template deser_dynamic<is_serialize>(ar, &obj);
            }
        } else {
            uint32_t len;
            ::deser_dynamic<is_serialize>(ar, &len);
            obj_group->clear();
            for(size_t i = 0; i < len; i++) {
                T obj;
                Serializer<T>::template deser_dynamic<is_serialize>(ar, &obj);
                obj_group->insert(obj);
            }
        }
    }
};

// Pair serializers
template<typename T, typename U>
class Serializer<std::pair<T, U>> {
public:
    template<bool is_serialize>
    static inline void deser_dynamic(Archive& ar, std::pair<T, U>* obj) {
        ::deser_dynamic(ar, &obj->first);
        ::deser_dynamic(ar, &obj->second);
    }
};

#include "eng3d/string.hpp"
template<>
class Serializer<Eng3D::StringRef> {
public:
    template<bool is_serialize, typename T2 = Eng3D::StringRef>
    static inline void deser_dynamic(Archive& ar, T2* obj) {
        ::deser_dynamic(ar, &obj->id);
    }
};

// Contigous container serializers implementations
#include <vector>
template<typename T>
class Serializer<std::vector<T>> : public SerializerContainer<T, std::vector<T>> {
public:
    template<bool is_serialize>
    static inline void deser_dynamic(Archive& ar, std::vector<T>* obj_group) {
        if constexpr(is_serialize) {
            uint32_t len = obj_group->size();
            ::deser_dynamic<is_serialize>(ar, &len);
            for(auto& obj : *obj_group) {
                ::deser_dynamic<is_serialize>(ar, &obj);
            }
        } else {
            uint32_t len;
            ::deser_dynamic<is_serialize>(ar, &len);
            obj_group->clear();
            for(size_t i = 0; i < len; i++) {
                T obj;
                ::deser_dynamic<is_serialize>(ar, &obj);
                obj_group->push_back(obj);
            }
        }
    }
};

#include <deque>
template<typename T>
class Serializer<std::deque<T>> : public SerializerContainer<T, std::deque<T>> {
public:
    template<bool is_serialize>
    static inline void deser_dynamic(Archive& ar, std::deque<T>* obj_group) {
        if constexpr(is_serialize) {
            uint32_t len = obj_group->size();
            ::deser_dynamic<is_serialize>(ar, &len);
            for(auto& obj : *obj_group) {
                ::deser_dynamic<is_serialize>(ar, &obj);
            }
        } else {
            uint32_t len;
            ::deser_dynamic<is_serialize>(ar, &len);
            obj_group->clear();
            for(size_t i = 0; i < len; i++) {
                T obj;
                ::deser_dynamic<is_serialize>(ar, &obj);
                obj_group->push_back(obj);
            }
        }
    }
};

#include <queue>
template<typename T>
class Serializer<std::queue<T>> : public SerializerContainer<T, std::queue<T>> {};

#include <set>
template<typename T>
class Serializer<std::set<T>> : public SerializerContainer<T, std::set<T>> {};

#include <unordered_set>
template<typename T>
class Serializer<std::unordered_set<T>> : public SerializerContainer<T, std::unordered_set<T>> {};

#include <bitset>
template<typename T, int N>
class SerializerBitset {
public:
    template<bool is_serialize>
    static inline void deser_dynamic(Archive& ar, T* obj_group) {
        if constexpr(is_serialize) {
            unsigned long num = obj_group->to_ulong();
            ::deser_dynamic<is_serialize>(ar, &num);
        } else {
            unsigned long num;
            ::deser_dynamic<is_serialize>(ar, &num);
            *obj_group = T(num);
        }
    }
};

template<size_t bits>
class Serializer<std::bitset<bits>> : public SerializerBitset<std::bitset<bits>, bits> {};

// Used as a template for serializable objects (pointers mostly) which should be
// treated as a reference instead of the object itself
template<typename W, typename T>
class SerializerReference {
public:
    template<bool is_serialize>
    static inline void deser_dynamic(Archive& ar, T** obj) {
        if constexpr(is_serialize) {
            typename T::Id id = (*obj == nullptr) ? T::invalid() : W::get_instance().get_id(**obj);
            ::deser_dynamic<is_serialize>(ar, &id);
        } else {
            typename T::Id id;
            ::deser_dynamic<is_serialize>(ar, &id);
            if(id >= W::get_instance().get_list((T*)nullptr).size()) {
                *obj = nullptr;
                return;
            }
            *obj = (id != T::invalid()) ? W::get_instance().get_list((T*)nullptr)[id] : nullptr;
        }
    }
};

// Non-pointer
template<typename W, typename T>
class SerializerReferenceLocal {
public:
    template<bool is_serialize>
    static inline void deser_dynamic(Archive& ar, T** obj) {
        if constexpr(is_serialize) {
            typename T::Id id = (*obj == nullptr) ? T::invalid() : W::get_instance().get_id(**obj);
            ::deser_dynamic<is_serialize>(ar, &id);
        } else {
            typename T::Id id;
            ::deser_dynamic<is_serialize>(ar, &id);
            if(id >= W::get_instance().get_list((T*)nullptr).size()) {
                *obj = nullptr;
                return;
            }
            *obj = (id != T::invalid()) ? &(W::get_instance().get_list((T*)nullptr)[id]) : nullptr;
        }
    }
};

/// @todo Template for entities