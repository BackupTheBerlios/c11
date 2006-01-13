/***************************************************************************
 *            draw-window.c
 *
 *  Fri Jan 13 21:34:03 2006
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

int c11_draw_window(unsigned int db_id)
{
	int i;
	char *foo;
	
	if(c11_util_id_check2(db_id)!=0)
		return(-1);
	
	if(confdb.theme[OBJ_TYPE_I].dropshadow==TRUE)
	{
		SLtt_set_color(256,NULL,"black","black");
		SLsmg_set_color(256);
		
		for(i=1;i<=uidb[db_id].h;i++)
		{
			SLsmg_gotorc(uidb[db_id].y+i,uidb[db_id].x+1); SLsmg_draw_hline(uidb[db_id].w);
		}
	}
	
	SLtt_set_color(2,NULL,confdb.theme[OBJ_TYPE_I].fg[THEME_TYPE_FG_NORMAL],confdb.theme[OBJ_TYPE_I].bg[THEME_TYPE_BG_NORMAL]);
	SLsmg_set_color(2);
	
	SLsmg_draw_box(uidb[db_id].y, uidb[db_id].x, uidb[db_id].h, uidb[db_id].w);

	SLtt_set_color(3,NULL,confdb.theme[OBJ_TYPE_I].bg[THEME_TYPE_BG_NORMAL],confdb.theme[OBJ_TYPE_I].bg[THEME_TYPE_BG_NORMAL]);
	SLsmg_set_color(3);

	for(i=1;i<(uidb[db_id].h-1);i++)
	{
		SLsmg_gotorc(uidb[db_id].y+i,uidb[db_id].x+1); SLsmg_draw_hline(uidb[db_id].w-2);
	}

	SLtt_set_color(4,NULL,confdb.theme[OBJ_TYPE_I].bg[THEME_TYPE_BG_FOCUSED],confdb.theme[OBJ_TYPE_I].bg[THEME_TYPE_BG_FOCUSED]);
	SLsmg_set_color(4);
	
	SLsmg_gotorc(uidb[db_id].y,uidb[db_id].x);
	
	SLsmg_draw_hline(uidb[db_id].w);
	
/*	if((foo=c11_util_catstr(uidb[db_id].title,0,uidb[db_id].w))==NULL)
	{
		SLsmg_write_string(uidb[db_id].title);
	}
	else
	{
		SLsmg_write_string(foo);
	}*/
	
	SLsmg_refresh();
	return(0);
}
