/***************************************************************************
 *            config-management.h
 *
 *  Thu Jan 12 17:15:44 2006
 *  Copyright  2006  Marius M. M.
 *  0x0090@gmail.com
 ****************************************************************************/

/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
#ifndef _CONFIG_MANAGEMENT_H
#define _CONFIG_MANAGEMENT_H

#include "include/ui/ui-management.h"

#define CONFIG_NAME "c11.conf"
#define CONFIG_ROOT "/etc/"CONFIG_NAME

#ifdef __cplusplus
extern "C"
{
#endif

enum THEME_TYPE_BG
{
	THEME_TYPE_BG_NORMAL,
	THEME_TYPE_BG_FOCUSED,
	THEME_TYPE_BG_UNFOCUSED,
	THEME_TYPE_BG_I
};

static char bg_types[THEME_TYPE_BG_I][32] = {
	{"bg_normal"},{"bg_focused"},{"bg_unfocused"}
};

enum THEME_TYPE_F
{
	THEME_TYPE_FG_NORMAL,
	THEME_TYPE_FG_FOCUSED,
	THEME_TYPE_FG_UNFOCUSED,
	THEME_TYPE_FG_I
};

static char fg_types[THEME_TYPE_FG_I][32] = {
	{"fg_normal"},{"fg_focused"},{"fg_unfocused"}
};


struct CONFIGDB
{
	char *background;
	struct THEMEDB
	{
		char *bg[THEME_TYPE_BG_I];
		char *fg[THEME_TYPE_FG_I];
		bool dropshadow;
	}theme[OBJ_TYPE_I+1];
}confdb;

int c11_config_init(void);
void c11_config_close(void);

int c11_config_get_theme(void);

/*unsigned long c11_config_color_lookup(const char *color);*/

#ifdef __cplusplus
}
#endif

#endif /* _CONFIG_MANAGEMENT_H */
