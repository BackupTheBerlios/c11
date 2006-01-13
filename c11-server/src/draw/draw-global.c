/***************************************************************************
 *            draw-global.c
 *
 *  Fri Jan 13 21:08:34 2006
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
 
#include "include/c11-defines.h"
#include "include/c11-util.h"
#include "include/ui/ui-management.h"
#include "include/config/config-management.h"
#include "include/draw/draw-global.h"
#include <slang.h>

void c11_draw_background(void)
{
	SLtt_set_color(255,NULL,confdb.background,confdb.background);
	SLsmg_set_color(255);
	SLsmg_gotorc(0,0);
	SLsmg_erase_eos();
	SLsmg_refresh();
	
	return;
}
