#include "texture.hpp"
#include "ui.hpp"
#include "path.hpp"

extern TextureManager* g_texture_manager;
const Texture* button_pvw,* treaty_win_tex;
extern UI::Window* top_win;
extern std::pair<int, int> mouse_pos;

#include "nation.hpp"
extern Nation* curr_nation;

#include "serializer.hpp"
#include "io_impl.hpp"
#include "network.hpp"

UI::Label* recv_nation_lab;
UI::Image* recv_nation_flag;
UI::Window* select_win;
Nation* recv_nation = nullptr;

extern const Texture& get_nation_flag(Nation& nation);

enum TreatyClauseType g_clause_type;
Treaty g_treaty_draft;

void ui_treaty(void) {
	treaty_win_tex = &g_texture_manager->load_texture(Path::get("ui/debug_win.png"));
	button_pvw = &g_texture_manager->load_texture(Path::get("ui/button_pvw.png"));

	UI::Window* treaty_win = new UI::Window(0, 0, treaty_win_tex->width, treaty_win_tex->height);
	treaty_win->text("Draft Treaty");
	treaty_win->current_texture = treaty_win_tex;
	treaty_win->below_of(dynamic_cast<const UI::Widget&>(*top_win));

	UI::Button* select_receiver_btn = new UI::Button(9, 43, button_pvw->width, button_pvw->height, treaty_win);
	select_receiver_btn->current_texture = button_pvw;
	select_receiver_btn->text("Select nation");
	select_receiver_btn->on_click = [](UI::Widget&, void*) {
		select_win = new UI::Window(0, 0, treaty_win_tex->width, treaty_win_tex->height);
		select_win->text("Select nation");
		select_win->current_texture = treaty_win_tex;

		int y = 0;
		for(const auto& nation: g_world->nations) {
			UI::Button* select_receiver_btn = new UI::Button(9, y, button_pvw->width, button_pvw->height, select_win);
			select_receiver_btn->current_texture = button_pvw;
			select_receiver_btn->text(nation->name.c_str());
			select_receiver_btn->user_data = (void*)nation;
			select_receiver_btn->on_click = [](UI::Widget&, void* data) {
				recv_nation = (Nation*)data;
				delete select_win;
			};
			y += button_pvw->height + 2;
		}
	};

	recv_nation_lab = new UI::Label(64, 44, "...", treaty_win);
	recv_nation_lab->below_of(dynamic_cast<const UI::Widget&>(*select_receiver_btn));
	recv_nation_lab->on_update = [](UI::Widget& w, void*) {
		if(recv_nation == nullptr)
			return;
		w.text(recv_nation->name.c_str());
	};

	recv_nation_flag = new UI::Image(0, recv_nation_lab->y, 58, 24, nullptr, treaty_win);
	recv_nation_flag->on_update = [](UI::Widget& w, void*) {
		if(recv_nation == nullptr)
			return;
		w.current_texture = &get_nation_flag(*recv_nation);
	};

	UI::Button* new_clause = new UI::Button(9, 0, button_pvw->width, button_pvw->height, treaty_win);
	new_clause->below_of(dynamic_cast<const UI::Widget&>(*recv_nation_lab));
	new_clause->current_texture = button_pvw;
	new_clause->text("Add new clause");
	new_clause->on_click = [](UI::Widget&, void*) {
		UI::Window new_clause_win = new UI::Window(0, 0, treaty_win_tex->width, treaty_win_tex->height);
		new_clause_win->text("Add new clause");
		new_clause_win->current_texture = treaty_win_tex;

		UI::Button* list_btn;
		int y = 0;

		list_btn = new UI::Button(9, y, button_pvw->width, button_pvw->height, new_clause_win);
		list_btn->current_texture = button_pvw;
		list_btn->text("TREATY_CLAUSE_WAR_REPARATIONS");
		list_btn->on_click = [](UI::Widget&, void* data) {
			TreatyClause::BaseClause* clause;
			clause.type = TREATY_CLAUSE_WAR_REPARATIONS;
			clause.sender = curr_nation;
			clause.receiver = recv_nation;
			clause.amount = 5000.f;
			clause.days_duration = 365;

			g_treaty_draft.clauses.push_back(clause);
		};
		y += button_pvw->height + 2;

		list_btn = new UI::Button(9, y, button_pvw->width, button_pvw->height, new_clause_win);
		list_btn->current_texture = button_pvw;
		list_btn->text("TREATY_CLAUSE_HUMILIATE");
		list_btn->on_click = [](UI::Widget&, void* data) {
			
		};
		y += button_pvw->height + 2;

		list_btn = new UI::Button(9, y, button_pvw->width, button_pvw->height, new_clause_win);
		list_btn->current_texture = button_pvw;
		list_btn->text("TREATY_CLAUSE_LIBERATE_NATION");
		list_btn->on_click = [](UI::Widget&, void* data) {
			
		};
		y += button_pvw->height + 2;

		list_btn = new UI::Button(9, y, button_pvw->width, button_pvw->height, new_clause_win);
		list_btn->current_texture = button_pvw;
		list_btn->text("TREATY_CLAUSE_IMPOSE_POLICIES");
		list_btn->on_click = [](UI::Widget&, void* data) {
			
		};
		y += button_pvw->height + 2;

		list_btn = new UI::Button(9, y, button_pvw->width, button_pvw->height, new_clause_win);
		list_btn->current_texture = button_pvw;
		list_btn->text("TREATY_CLAUSE_ANEXX_PROVINCES");
		list_btn->on_click = [](UI::Widget&, void* data) {
			UI::Window per_clause_win = new UI::Window(0, 0, treaty_win_tex->width, treaty_win_tex->height);
			per_clause_win->text("Add new clause");
			per_clause_win->current_texture = treaty_win_tex;

			int another_y = 0;
			for(size_t i = 0; i < recv_nation->owned_provinces.size(); i++) {
				list_btn = new UI::Button(9, another_y, button_pvw->width, button_pvw->height, new_clause_win);
				list_btn->current_texture = button_pvw;
				list_btn->text(recv_nation->owned_provinces[i]->ref_name.c_str());
				list_btn->on_click = [](UI::Widget&, void* data) {
					
				};
			}
		};
		y += button_pvw->height + 2;

		list_btn = new UI::Button(9, y, button_pvw->width, button_pvw->height, new_clause_win);
		list_btn->current_texture = button_pvw;
		list_btn->text("TREATY_CLAUSE_CEASEFIRE");
		list_btn->on_click = [](UI::Widget&, void* data) {
			
		};
		y += button_pvw->height + 2;

		UI::CloseButton* ok_btn = new UI::CloseButton(9, y, button_pvw->width, button_pvw->height, new_clause_win);
		ok_btn->text("OK");
		ok_btn->current_texture = button_pvw;
	};

	UI::Button* ok_btn = new UI::CloseButton(9, y, button_pvw->width, button_pvw->height, new_clause_win);
	ok_btn->text("OK");
	ok_btn->current_texture = button_pvw;
	ok_btn->on_click = [](UI::Widget&, void* data) {
		// Send draft to server
		
	};
}
