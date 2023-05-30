#include <wedge4/globals.h>

#include "area_game.h"
#include "globals.h"
#include "gui.h"
#include "inventory.h"
#include "widgets.h"

Menu_GUI::Menu_GUI(bool transition)
{
	if (transition) {
		this->transition = true;
		transition_is_slide_vertical = true;
	}
	else {
		this->transition = false;
	}

	TGUI_Widget *modal_main_widget = new TGUI_Widget(1.0f, 1.0f);

	TGUI_Widget *window = new Widget_Window(0.8f, 4*shim::font->get_height());
	window->set_centre_x(true);
	window->set_centre_y(true);
	window->set_parent(modal_main_widget);

	potion_button = new Widget_Text_Button(GLOBALS->game_t->translate(1)/* Originally: Potion */);
	int index = INSTANCE->inventory.find(OBJECT->make_object(wedge::OBJECT_ITEM, ITEM_POTION, 1));
	potion_button->set_enabled(index >= 0);
	potion_button->set_centre_x(true);
	potion_button->set_padding_top(16);
	potion_button->set_parent(window);

	return_button = new Widget_Text_Button(GLOBALS->game_t->translate(2)/* Originally: Return */);
	return_button->set_break_line(true);
	return_button->set_centre_x(true);
	return_button->set_clear_float_x(true);
	return_button->set_parent(window);
	
	gui = new TGUI(modal_main_widget, shim::screen_size.w, shim::screen_size.h);

	if (index >= 0) {
		gui->set_focus(potion_button);
	}
	else {
		gui->set_focus(return_button);
	}
}

Menu_GUI::~Menu_GUI()
{
}

void Menu_GUI::draw_fore()
{
	std::string text = util::string_printf("HP: %d/100", INSTANCE->stats[0].base.hp);
	int w = shim::font->get_text_width(text);
	shim::font->draw(shim::white, text, util::Point<float>(shim::screen_size.w/2.0f-w/2, shim::screen_size.h/2.0f-20));
	GUI::draw_fore();
}

void Menu_GUI::update()
{
	gui::GUI::update();

	if (potion_button->pressed()) {
		EX_GLOBALS->potion->play(false);
		int index = INSTANCE->inventory.find(OBJECT->make_object(wedge::OBJECT_ITEM, ITEM_POTION, 1));
		INSTANCE->inventory.use(index, &INSTANCE->stats[0].base);	
		INSTANCE->inventory.remove(index, 1);
		index = INSTANCE->inventory.find(OBJECT->make_object(wedge::OBJECT_ITEM, ITEM_POTION, 1));
		if (index < 0) {
			potion_button->set_enabled(false);
			gui->set_focus(return_button);
		}
	}
	else if (return_button->pressed()) {
		AREA->end_menu();
		exit();
	}
}

void Menu_GUI::resize(util::Size<int> new_size)
{
	gui->layout();
}

void Menu_GUI::handle_event(TGUI_Event *event)
{
	if ((event->type == TGUI_KEY_DOWN && event->keyboard.code == GLOBALS->key_back) || (event->type == TGUI_JOY_DOWN && event->joystick.button == GLOBALS->joy_back)) {
		AREA->end_menu();
		exit();
	}

	gui::GUI::handle_event(event);
}
