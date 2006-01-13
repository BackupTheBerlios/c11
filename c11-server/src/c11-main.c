/***************************************************************************
 *            c11-main.c
 *
 *  Thu Jan 12 17:22:13 2006
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

#include "include/ui/ui-management.h"
#include "include/c11-util.h"
#include "include/config/config-management.h"
#include "include/draw/draw-global.h"
#include <stdio.h>

int main(void)
{
	int i;
	
	ui_db_size = 0;
	c11_config_init();
	c11_config_get_theme();
	c11_config_close();
	
	c11_ui_init_main();
	c11_draw_background();
	
	i=c11_ui_db_new();
	c11_ui_window_new(i,WIN_TYPE_TOPLEVEL,"Test",2,1,20,10,"no-callback");
	c11_draw_window(i);
	
	SLang_getkey();
	
	c11_ui_window_del(i);
	c11_ui_db_del(i);
	
	c11_ui_init_exit();
	return(0);
}
