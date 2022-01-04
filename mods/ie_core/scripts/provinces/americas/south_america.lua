-- Industrial_Era_mod - Base game files for Symphony of Empires
-- Copyright (C) 2021, Symphony of Empires contributors
-- 
-- This program is free software; you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation; either version 2 of the License, or
-- (at your option) any later version.
-- 
-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License along
-- with this program; if not, write to the Free Software Foundation, Inc.,
-- 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
--
-- ----------------------------------------------------------------------------
--	Name:
--  	provinces/america/south_america.lua
--
-- 	Abstract:
--      Does important stuff
-- ----------------------------------------------------------------------------

--------------------------------------------------------------
-- Continent: Americas
-- Subcontinent: South America
-- Country: Gran Colombia

local gran_colombia_provinces_list = {
    { ref_name = "guayaquil", name = _("Guayaquil"), color = 0xFF873D },

    { ref_name = "province_40908000", name = _("Province_809040"), color = 0x809040 },
    { ref_name = "province_c6d1ff00", name = _("Province_ffd1c6"), color = 0xffd1c6 },
    { ref_name = "province_c00aa400", name = _("Province_a40ac0"), color = 0xa40ac0 },
    { ref_name = "province_c0f2cd00", name = _("Province_cdf2c0"), color = 0xcdf2c0 },
    { ref_name = "province_c08c0b00", name = _("Province_0b8cc0"), color = 0x0b8cc0 },
    { ref_name = "province_e0fd2b00", name = _("Province_2bfde0"), color = 0x2bfde0 },
    { ref_name = "province_70b000", name = _("Province_b07000"), color = 0xb07000 },
    { ref_name = "province_80f73300", name = _("Province_33f780"), color = 0x33f780 },
    { ref_name = "province_c045eb00", name = _("Province_eb45c0"), color = 0xeb45c0 },
    { ref_name = "province_c0d37b00", name = _("Province_7bd3c0"), color = 0x7bd3c0 },
    { ref_name = "province_80afad00", name = _("Province_adaf80"), color = 0xadaf80 },
    { ref_name = "province_a0d01500", name = _("Province_15d0a0"), color = 0x15d0a0 },
}
for k, v in pairs(gran_colombia_provinces_list) do
    province = Province:new(v)
    province:register()

    province:add_industry(wheat_farm, gran_colombia)
    province:add_pop(artisan, german, catholic, 5000, 0.7)
    province:add_pop(farmer, german, catholic, 5000, 0.1)
    province:add_pop(soldier, german, catholic, 5000, 0.2)
    province:add_pop(craftsmen, german, catholic, 5000, 0.2)
    province:add_pop(bureaucrat, german, catholic, 5000, 0.7)
    province:add_pop(burgeoise, german, catholic, 5000, 0.2)
    province:add_pop(clergymen, german, catholic, 5000, 0.3)
    province:add_pop(laborer, german, catholic, 5000, 0.2)
    province:add_pop(burgeoise, german, catholic, 500, 0.9)
    province:add_pop(slave, german, catholic, 500, 0.5)
    province:add_nucleus(gran_colombia)
    province:give_to(gran_colombia)
end

province = Province:new{ ref_name = "ecuador", color = 0x8C63FF }
province.name = _("Ecuador")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, german, protestant, 5000, 0.7)
province:add_pop(farmer, german, protestant, 5000, 0.1)
province:add_pop(soldier, german, protestant, 5000, 0.2)
province:add_pop(craftsmen, german, protestant, 5000, 0.2)
province:add_pop(bureaucrat, german, protestant, 5000, 0.7)
province:add_pop(burgeoise, german, protestant, 5000, 0.2)
province:add_pop(clergymen, german, protestant, 5000, 0.3)
province:add_pop(laborer, german, protestant, 5000, 0.2)
province:add_pop(burgeoise, german, protestant, 500, 0.9)
province:add_pop(slave, german, protestant, 500, 0.5)
province:add_nucleus(gran_colombia)
province:give_to(gran_colombia)

province = Province:new{ ref_name = "galapagos", color = 0xf1c9ff }
province.name = _("Galápagos")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, german, protestant, 5000, 0.7)
province:add_pop(farmer, german, protestant, 5000, 0.1)
province:add_pop(soldier, german, protestant, 5000, 0.2)
province:add_pop(craftsmen, german, protestant, 5000, 0.2)
province:add_pop(bureaucrat, german, protestant, 5000, 0.7)
province:add_pop(burgeoise, german, protestant, 5000, 0.2)
province:add_pop(clergymen, german, protestant, 5000, 0.3)
province:add_pop(laborer, german, protestant, 5000, 0.2)
province:add_pop(burgeoise, german, protestant, 500, 0.9)
province:add_pop(slave, german, protestant, 500, 0.5)
province:add_nucleus(gran_colombia)
province:give_to(gran_colombia)

province = Province:new{ ref_name = "cauca", color = 0x6DFF8F }
province.name = _("Cauca")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, german, protestant, 5000, 0.7)
province:add_pop(farmer, german, protestant, 5000, 0.1)
province:add_pop(soldier, german, protestant, 5000, 0.2)
province:add_pop(craftsmen, german, protestant, 5000, 0.2)
province:add_pop(bureaucrat, german, protestant, 5000, 0.7)
province:add_pop(burgeoise, german, protestant, 5000, 0.2)
province:add_pop(clergymen, german, protestant, 5000, 0.3)
province:add_pop(laborer, german, protestant, 5000, 0.2)
province:add_pop(burgeoise, german, protestant, 500, 0.9)
province:add_pop(slave, german, protestant, 500, 0.5)
province:add_nucleus(gran_colombia)
province:give_to(gran_colombia)

province = Province:new{ ref_name = "istmo", color = 0xFF795B }
province.name = _("Istmo")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, german, protestant, 5000, 0.7)
province:add_pop(farmer, german, protestant, 5000, 0.1)
province:add_pop(soldier, german, protestant, 5000, 0.2)
province:add_pop(craftsmen, german, protestant, 5000, 0.2)
province:add_pop(bureaucrat, german, protestant, 5000, 0.7)
province:add_pop(burgeoise, german, protestant, 5000, 0.2)
province:add_pop(clergymen, german, protestant, 5000, 0.3)
province:add_pop(laborer, german, protestant, 5000, 0.2)
province:add_pop(burgeoise, german, protestant, 500, 0.9)
province:add_pop(slave, german, protestant, 500, 0.5)
province:add_nucleus(gran_colombia)
province:give_to(gran_colombia)

province = Province:new{ ref_name = "magdalena", color = 0x63A4FF }
province.name = _("Magdalena")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, german, protestant, 5000, 0.7)
province:add_pop(farmer, german, protestant, 5000, 0.1)
province:add_pop(soldier, german, protestant, 5000, 0.2)
province:add_pop(craftsmen, german, protestant, 5000, 0.2)
province:add_pop(bureaucrat, german, protestant, 5000, 0.7)
province:add_pop(burgeoise, german, protestant, 5000, 0.2)
province:add_pop(clergymen, german, protestant, 5000, 0.3)
province:add_pop(laborer, german, protestant, 5000, 0.2)
province:add_pop(burgeoise, german, protestant, 500, 0.9)
province:add_pop(slave, german, protestant, 500, 0.5)
province:add_nucleus(gran_colombia)
province:give_to(gran_colombia)

province = Province:new{ ref_name = "cundinamarca", color = 0xe1ff91 }
province.name = _("Cundinamarca")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, german, protestant, 5000, 0.7)
province:add_pop(farmer, german, protestant, 5000, 0.1)
province:add_pop(soldier, german, protestant, 5000, 0.2)
province:add_pop(craftsmen, german, protestant, 5000, 0.2)
province:add_pop(bureaucrat, german, protestant, 5000, 0.7)
province:add_pop(burgeoise, german, protestant, 5000, 0.2)
province:add_pop(clergymen, german, protestant, 5000, 0.3)
province:add_pop(laborer, german, protestant, 5000, 0.2)
province:add_pop(burgeoise, german, protestant, 500, 0.9)
province:add_pop(slave, german, protestant, 500, 0.5)
province:add_nucleus(gran_colombia)
province:give_to(gran_colombia)
gran_colombia:set_capital(province)

province = Province:new{ ref_name = "boyaca", color = 0xFFFF91 }
province.name = _("Boyacá")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, german, protestant, 5000, 0.7)
province:add_pop(farmer, german, protestant, 5000, 0.1)
province:add_pop(soldier, german, protestant, 5000, 0.2)
province:add_pop(craftsmen, german, protestant, 5000, 0.2)
province:add_pop(bureaucrat, german, protestant, 5000, 0.7)
province:add_pop(burgeoise, german, protestant, 5000, 0.2)
province:add_pop(clergymen, german, protestant, 5000, 0.3)
province:add_pop(laborer, german, protestant, 5000, 0.2)
province:add_pop(burgeoise, german, protestant, 500, 0.9)
province:add_pop(slave, german, protestant, 500, 0.5)
province:add_nucleus(gran_colombia)
province:give_to(gran_colombia)

province = Province:new{ ref_name = "zulia", color = 0x9EFFA7 }
province.name = _("Zulia")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, german, protestant, 5000, 0.7)
province:add_pop(farmer, german, protestant, 5000, 0.1)
province:add_pop(soldier, german, protestant, 5000, 0.2)
province:add_pop(craftsmen, german, protestant, 5000, 0.2)
province:add_pop(bureaucrat, german, protestant, 5000, 0.7)
province:add_pop(burgeoise, german, protestant, 5000, 0.2)
province:add_pop(clergymen, german, protestant, 5000, 0.3)
province:add_pop(laborer, german, protestant, 5000, 0.2)
province:add_pop(burgeoise, german, protestant, 500, 0.9)
province:add_pop(slave, german, protestant, 500, 0.5)
province:add_nucleus(gran_colombia)
province:give_to(gran_colombia)

province = Province:new{ ref_name = "venezuela", color = 0x0083FF }
province.name = _("Venezuela")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, german, protestant, 5000, 0.7)
province:add_pop(farmer, german, protestant, 5000, 0.1)
province:add_pop(soldier, german, protestant, 5000, 0.2)
province:add_pop(craftsmen, german, protestant, 5000, 0.2)
province:add_pop(bureaucrat, german, protestant, 5000, 0.7)
province:add_pop(burgeoise, german, protestant, 5000, 0.2)
province:add_pop(clergymen, german, protestant, 5000, 0.3)
province:add_pop(laborer, german, protestant, 5000, 0.2)
province:add_pop(burgeoise, german, protestant, 500, 0.9)
province:add_pop(slave, german, protestant, 500, 0.5)
province:add_nucleus(gran_colombia)
province:give_to(gran_colombia)

province = Province:new{ ref_name = "cumana", color = 0xFF8EEE }
province.name = _("Cumaná")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, german, protestant, 5000, 0.7)
province:add_pop(farmer, german, protestant, 5000, 0.1)
province:add_pop(soldier, german, protestant, 5000, 0.2)
province:add_pop(craftsmen, german, protestant, 5000, 0.2)
province:add_pop(bureaucrat, german, protestant, 5000, 0.7)
province:add_pop(burgeoise, german, protestant, 5000, 0.2)
province:add_pop(clergymen, german, protestant, 5000, 0.3)
province:add_pop(laborer, german, protestant, 5000, 0.2)
province:add_pop(burgeoise, german, protestant, 500, 0.9)
province:add_pop(slave, german, protestant, 500, 0.5)
province:add_nucleus(gran_colombia)
province:give_to(gran_colombia)

province = Province:new{ ref_name = "orinoco", color = 0x96A9FF }
province.name = _("Orinoco")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, german, protestant, 5000, 0.7)
province:add_pop(farmer, german, protestant, 5000, 0.1)
province:add_pop(soldier, german, protestant, 5000, 0.2)
province:add_pop(craftsmen, german, protestant, 5000, 0.2)
province:add_pop(bureaucrat, german, protestant, 5000, 0.7)
province:add_pop(burgeoise, german, protestant, 5000, 0.2)
province:add_pop(clergymen, german, protestant, 5000, 0.3)
province:add_pop(laborer, german, protestant, 5000, 0.2)
province:add_pop(burgeoise, german, protestant, 500, 0.9)
province:add_pop(slave, german, protestant, 500, 0.5)
province:add_nucleus(gran_colombia)
province:give_to(gran_colombia)

province = Province:new{ ref_name = "apure", color = 0xFFA8B2 }
province.name = _("Apure")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, german, protestant, 5000, 0.7)
province:add_pop(farmer, german, protestant, 5000, 0.1)
province:add_pop(soldier, german, protestant, 5000, 0.2)
province:add_pop(craftsmen, german, protestant, 5000, 0.2)
province:add_pop(bureaucrat, german, protestant, 5000, 0.7)
province:add_pop(burgeoise, german, protestant, 5000, 0.2)
province:add_pop(clergymen, german, protestant, 5000, 0.3)
province:add_pop(laborer, german, protestant, 5000, 0.2)
province:add_pop(burgeoise, german, protestant, 500, 0.9)
province:add_pop(slave, german, protestant, 500, 0.5)
province:add_nucleus(gran_colombia)
province:give_to(gran_colombia)

--------------------------------------------------------------
-- Continent: Americas
-- Subcontinent: South America
-- Country: Peru

local peru_provinces_list = {
    { ref_name = "province_a024fc00", name = _("Province_fc24a0"), color = 0xfc24a0 },
    { ref_name = "province_409d7800", name = _("Province_789d40"), color = 0x789d40 },
    { ref_name = "province_a04fef00", name = _("Province_ef4fa0"), color = 0xef4fa0 },
    { ref_name = "province_e0594c00", name = _("Province_4c59e0"), color = 0x4c59e0 },
    { ref_name = "province_a036d800", name = _("Province_d836a0"), color = 0xd836a0 },
    { ref_name = "province_60e01c00", name = _("Province_1ce060"), color = 0x1ce060 },
    { ref_name = "province_20010000", name = _("Province_000120"), color = 0x000120 },
    { ref_name = "province_6011fe00", name = _("Province_fe1160"), color = 0xfe1160 },
}
for k, v in pairs(peru_provinces_list) do
    province = Province:new(v)
    province:register()

    province:add_industry(wheat_farm, peru)
    province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
    province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
    province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
    province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
    province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
    province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
    province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
    province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
    province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
    province:add_nucleus(peru)
    province:give_to(peru)
end

province = Province:new{ ref_name = "arica", color = 0xe75935 }
province.name = _("Arica")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)

province = Province:new{ ref_name = "arequipa", color = 0x9277FF }
province.name = _("Arequipa")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)

province = Province:new{ ref_name = "lima", color = 0x2d0cff }
province.name = _("Lima")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)

province = Province:new{ ref_name = "huaraz", color = 0xFF816B }
province.name = _("Huaraz")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)

province = Province:new{ ref_name = "trujillo", color = 0xFFC43D }
province.name = _("Trujillo")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)

province = Province:new{ ref_name = "zarumilla", color = 0xFF9F96 }
province.name = _("Zarumilla")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)

province = Province:new{ ref_name = "maynas", color = 0x47E6FF }
province.name = _("Maynas")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)

province = Province:new{ ref_name = "huanuco", color = 0x82FFD1 }
province.name = _("Huánuco")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)

province = Province:new{ ref_name = "junin", color = 0x49FF56 }
province.name = _("Junín")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)

province = Province:new{ ref_name = "ucayali", color = 0x734CFF }
province.name = _("Ucayali")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)

province = Province:new{ ref_name = "puno", color = 0x3FFF49 }
province.name = _("Puno")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)

province = Province:new{ ref_name = "xapuri", color = 0xFCFF7C }
province.name = _("Xapuri")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)

province = Province:new{ ref_name = "acre", color = 0xB2FFA8 }
province.name = _("Acre")
province:register()
province:add_industry(wheat_farm, russia)
province:add_pop(artisan, peruvian, catholic, 5000, 0.8)
province:add_pop(farmer, peruvian, catholic, 5000, 0.3)
province:add_pop(soldier, peruvian, catholic, 5000, 0.6)
province:add_pop(craftsmen, peruvian, catholic, 5000, 0.4)
province:add_pop(bureaucrat, peruvian, catholic, 5000, 0.5)
province:add_pop(burgeoise, peruvian, catholic, 5000, 0.9)
province:add_pop(clergymen, peruvian, catholic, 5000, 0.7)
province:add_pop(laborer, peruvian, catholic, 5000, 0.4)
province:add_pop(burgeoise, peruvian, catholic, 500, 0.9)
province:add_nucleus(peru)
province:give_to(peru)
