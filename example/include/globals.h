#ifndef GLOBALS_H
#define GLOBALS_H

#include <wedge4/globals.h>

#define EX_GLOBALS static_cast<Globals *>(wedge::globals)

class Globals : public wedge::Globals
{
public:
	Globals();
	virtual ~Globals();

	// There's a lot here, most of it isn't used in this example... but these are pure virtual
	// so need at least a blank definition
	bool add_title_gui(bool transition);
	void do_dialogue(std::string tag, std::string text, wedge::Dialogue_Type type, wedge::Dialogue_Position position, wedge::Step *monitor);
	bool dialogue_active(wedge::Game *game, bool only_if_initialised = false, bool wait_for_fade = true);
	void add_yes_no_gui(std::string text, bool escape_cancels, bool selected, util::Callback callback = 0, void *callback_data = 0);
	bool can_walk();
	bool title_gui_is_top();
	void add_notification_gui(std::string text, util::Callback callback, void *callback_data);
	void get_joy_xy(TGUI_Event *event, float joy_axis0, float joy_axis1, int *x, int *y);
	bool should_show_back_arrow();
	//--
	
	class Instance : public wedge::Globals::Instance
	{
	public:
		Instance(util::JSON::Node *root);
		virtual ~Instance();

		int num_milestones();
	};

	audio::Sound *hit;
	audio::Sound *melee;
	audio::Sound *potion;

	gfx::Image *gui_window;

	bool started;
};

#endif // GLOBALS_H
