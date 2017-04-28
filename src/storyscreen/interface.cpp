/*
   Copyright (C) 2009 - 2017 by Ignacio R. Morelle <shadowm2006@gmail.com>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

/**
 * @file
 * Storyscreen controller (wrapper interface).
 */

#include "variable.hpp"

#include "storyscreen/interface.hpp"
#include "storyscreen/controller.hpp"

#include "gui/dialogs/story_viewer.hpp"

void show_story(CVideo& video, const std::string &scenario_name,
	const config::const_child_itors &story)
{
	// Combine all the [story] tags into a single config
	config cfg;
	for(const auto& iter : story) {
		cfg.append_children(iter);
	}

	if(cfg.empty()) {
		return;
	}

	storyscreen::controller controller(vconfig(cfg, true), scenario_name);

	gui2::dialogs::story_viewer::display(controller, video);
}
