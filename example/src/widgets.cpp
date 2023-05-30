#include <wedge4/area.h>
#include <wedge4/general.h>

#include "area_game.h"
#include "battle_game.h"
#include "general.h"
#include "globals.h"
#include "gui.h"
#include "widgets.h"

void Widget::set_background_colour(SDL_Colour colour)
{
	background_colour = colour;
}

void Widget::start()
{
	background_colour.r = 0;
	background_colour.g = 0;
	background_colour.b = 0;
	background_colour.a = 0;
}

Widget::Widget(int w, int h) :
	TGUI_Widget(w, h)
{
	start();
}

Widget::Widget(float percent_w, float percent_h) :
	TGUI_Widget(percent_w, percent_h)
{
	start();
}

Widget::Widget(int w, float percent_h) :
	TGUI_Widget(w, percent_h)
{
	start();
}

Widget::Widget(float percent_w, int h) :
	TGUI_Widget(percent_w, h)
{
	start();
}

Widget::Widget(TGUI_Widget::Fit fit, int other) :
	TGUI_Widget(fit, other)
{
	start();
}

Widget::Widget(TGUI_Widget::Fit fit, float percent_other) :
	TGUI_Widget(fit, percent_other)
{
	start();
}

Widget::Widget() :
	TGUI_Widget()
{
	start();
}

Widget::~Widget()
{
}

void Widget::draw()
{
	// This is used to clear the background to a darker colour, so don't do it unless this widget is part of
	// the topmost gui because it could happen twice giving a darker colour

	if (shim::guis.size() > 0) {
		TGUI_Widget *root = shim::guis.back()->gui->get_main_widget();
		TGUI_Widget *w = this;
		TGUI_Widget *parent;
		while ((parent = w->get_parent()) != NULL) {
			w = parent;
		}
		if (root != w) {
			return;
		}
	}

	if (background_colour.a != 0) {
		// Need to clear transforms temporarily because it might be part of a transition
		glm::mat4 old_mv, old_p;
		gfx::get_matrices(old_mv, old_p);
		gfx::set_default_projection(shim::real_screen_size, shim::screen_offset, shim::scale);
		gfx::update_projection();
		gfx::draw_filled_rectangle(background_colour, util::Point<int>(calculated_x, calculated_y), util::Size<int>(calculated_w, calculated_h));
		gfx::set_matrices(old_mv, old_p);
		gfx::update_projection();
	}
}

bool Widget::is_focussed()
{
	if (shim::guis.size() == 0) {
		return false;
	}
	if (gui != shim::guis.back()->gui) {
		return false;
	}
	return gui->get_focus() == this;
}

//--

Widget_Window::Widget_Window(int w, int h) :
	Widget(w, h)
{
	start();
}

Widget_Window::Widget_Window(float percent_w, float percent_h) :
	Widget(percent_w, percent_h)
{
	start();
}

Widget_Window::Widget_Window(int w, float percent_h) :
	Widget(w, percent_h)
{
	start();
}

Widget_Window::Widget_Window(float percent_w, int h) :
	Widget(percent_w, h)
{
	start();
}

Widget_Window::Widget_Window(TGUI_Widget::Fit fit, int other) :
	Widget(fit, other)
{
	start();
}

Widget_Window::Widget_Window(TGUI_Widget::Fit fit, float percent_other) :
	Widget(fit, percent_other)
{
	start();
}

void Widget_Window::start()
{
	image = nullptr;
	alpha = 1.0f;
}

Widget_Window::~Widget_Window()
{
}

void Widget_Window::draw()
{
	gfx::Image *i;

	if (image == nullptr) {
		i = EX_GLOBALS->gui_window;
	}
	else {
		i = image;
	}

	gfx::draw_9patch_tinted(shim::white, i, util::Point<int>(calculated_x, calculated_y), util::Size<int>(calculated_w, calculated_h));
}
	
void Widget_Window::set_image(gfx::Image *image)
{
	this->image = image;
}

void Widget_Window::set_alpha(float alpha)
{
	this->alpha = alpha;
}

//--

Widget_Button::Widget_Button(int w, int h) :
	Widget(w, h)
{
	start();
}

Widget_Button::Widget_Button(float w, float h) :
	Widget(w, h)
{
	start();
}

Widget_Button::Widget_Button(int w, float h) :
	Widget(w, h)
{
	start();
}

Widget_Button::Widget_Button(float w, int h) :
	Widget(w, h)
{
	start();
}

void Widget_Button::start()
{
	_pressed = false;
	_released = false;
	_hover = false;
	gotten = true;
	sound_enabled = true;
	accepts_focus = true;
	mouse_only = false;
}

Widget_Button::~Widget_Button()
{
}

void Widget_Button::handle_event(TGUI_Event *event)
{
	if (mouse_only && (event->type == TGUI_KEY_DOWN || event->type == TGUI_KEY_UP || event->type == TGUI_JOY_DOWN || event->type == TGUI_JOY_UP)) {
		return;
	}

	int x, y;

	if (use_relative_position) {
		x = relative_x;
		y = relative_y;
	}
	else {
		x = calculated_x;
		y = calculated_y;
	}

	if (event->type == TGUI_MOUSE_AXIS) {
		if (event->mouse.x >= x && event->mouse.x < x+calculated_w && event->mouse.y >= y && event->mouse.y < y+calculated_h) {
			_hover = true;
		}
		else {
			_hover = false;
		}
	}
	if (accepts_focus && gui->get_event_owner(event) == this) {
		if (event->type == TGUI_KEY_DOWN && event->keyboard.is_repeat == false) {
			if (event->keyboard.code == /*GLOBALS->key_b1*/GLOBALS->key_action) {
				if (gotten) {
					_pressed = true;
					_hover = true;
				}
			}
			else {
				_pressed = false;
				_hover = false;
			}
		}
		else if (event->type == TGUI_JOY_DOWN && event->joystick.is_repeat == false) {
			if (event->joystick.button == GLOBALS->joy_action) {
				if (gotten) {
					_pressed = true;
					_hover = true;
				}
			}
			else {
				_pressed = false;
				_hover = false;
			}
		}
		else if (event->type == TGUI_MOUSE_DOWN && event->mouse.is_repeat == false) {
			if (event->mouse.button == 1) {
				if (gotten) {
					_pressed = true;
				}
			}
			else {
				_pressed = false;
			}
			_hover = true;
		}
		else if (event->type == TGUI_KEY_UP && event->keyboard.is_repeat == false) {
			if (_pressed && event->keyboard.code == /*GLOBALS->key_b1*/GLOBALS->key_action) {
				if (gotten) {
					gotten = false;
					_released = true;
					_hover = false;
					if (sound_enabled) {
						if (GLOBALS->button != 0) {
							GLOBALS->button->play(false);
						}
					}
				}
			}
			else {
				_pressed = false;
				_hover = false;
			}
		}
		else if (event->type == TGUI_JOY_UP && event->joystick.is_repeat == false) {
			if (_pressed && (event->joystick.button == GLOBALS->joy_action)) {
				if (gotten) {
					gotten = false;
					_released = true;
					_hover = false;
					if (sound_enabled) {
						if (GLOBALS->button != 0) {
							GLOBALS->button->play(false);
						}
					}
				}
			}
			else {
				_pressed = false;
				_hover = false;
			}
		}
		else if (event->type == TGUI_MOUSE_UP && event->mouse.is_repeat == false) {
			if (_pressed && (event->mouse.button == 1)) {
				if (gotten) {
					gotten = false;
					_released = true;
					if (sound_enabled) {
						if (GLOBALS->button != 0) {
							GLOBALS->button->play(false);
						}
					}
				}
			}
			else {
				_pressed = false;
			}
		}
	}
	else {
		if (event->type == TGUI_KEY_UP) {
			_pressed = false;
			_hover = false;
		}
		else if (event->type == TGUI_JOY_UP) {
			_pressed = false;
			_hover = false;
		}
		else if (event->type == TGUI_MOUSE_UP && event->mouse.is_repeat == false) {
			_pressed = false;
			_hover = false;
		}
		else if ((event->type == TGUI_MOUSE_DOWN || event->type == TGUI_MOUSE_AXIS) && event->mouse.is_repeat == false) {
			_hover = false;
		}
	}
}

bool Widget_Button::pressed()
{
	bool r = _released;
	if (_released) {
		_pressed = _released = false;
	}
	gotten = true;
	return r;
}

void Widget_Button::set_sound_enabled(bool enabled)
{
	sound_enabled = enabled;
}

void Widget_Button::set_pressed(bool pressed)
{
	this->_pressed = this->_released = pressed;
}

void Widget_Button::set_mouse_only(bool mouse_only)
{
	this->mouse_only = mouse_only;
}

//--

Widget_Text_Button::Widget_Text_Button(std::string text) :
	Widget_Button(0, 0),
	text(text)
{
	enabled = true;
	set_size();

	disabled_text_colour.r = 64;
	disabled_text_colour.g = 64;
	disabled_text_colour.b = 64;
	disabled_text_colour.a = 255;
	normal_text_colour.r = 192;
	normal_text_colour.g = 192;
	normal_text_colour.b = 192;
	normal_text_colour.a = 255;
}

Widget_Text_Button::~Widget_Text_Button()
{
}

void Widget_Text_Button::draw()
{
	bool focussed = is_focussed();

	int x, y;

	if (use_relative_position) {
		x = relative_x;
		y = relative_y;
	}
	else {
		x = calculated_x;
		y = calculated_y;
	}

	SDL_Colour colour;

	if (enabled == false) {
		colour = disabled_text_colour;
	}
	else {
		if (focussed) {
			colour = shim::white;
		}
		else {
			colour = normal_text_colour;
		}
		/*
		if (focussed) {
			SDL_Colour c1 = shim::white;
			SDL_Colour c2 = normal_text_colour;
			int dr = int(c2.r) - int(c1.r);
			int dg = int(c2.g) - int(c1.g);
			int db = int(c2.b) - int(c1.b);
			int da = int(c2.a) - int(c1.a);
			Uint32 t = GET_TICKS() % 1000;
			float p;
			if (t < 500) {
				p = t / 500.0f;
			}
			else {
				p = 1.0f - ((t - 500) / 500.0f);
			}
			p = sin(p * M_PI / 2.0f);
			colour.r = c1.r + dr * p;
			colour.g = c1.g + dg * p;
			colour.b = c1.b + db * p;
			colour.a = c1.a + da * p;
		}
		else{
			colour = normal_text_colour;
		}
		*/
	}

	shim::font->draw(colour, text, util::Point<float>(x, y) + (_pressed && _hover ? util::Point<int>(1, 1) : util::Point<int>(0, 0)));

	if (focussed && gui == shim::guis.back()->gui) {
		gfx::Image *img = GLOBALS->cursor->get_current_image();
		img->draw(util::Point<float>(x-img->size.w-1, y+h/2-img->size.h/2-1));
	}
}

void Widget_Text_Button::set_size()
{
	w = shim::font->get_text_width(text);
	h = shim::font->get_height();
}

void Widget_Text_Button::set_enabled(bool enabled)
{
	this->enabled = enabled;
	if (enabled == true) {
		accepts_focus = true;
	}
	else {
		accepts_focus = false;
	}
}

bool Widget_Text_Button::is_enabled()
{
	return enabled;
}

void Widget_Text_Button::set_text(std::string text)
{
	this->text = text;
	set_size();
}

void Widget_Text_Button::set_disabled_text_colour(SDL_Colour colour)
{
	disabled_text_colour = colour;
}
