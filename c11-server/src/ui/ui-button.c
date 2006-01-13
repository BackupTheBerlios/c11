/***************************************************************************
 *            ui-button.c
 *
 *  Thu Jan 12 20:45:45 2006
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
#include "include/ui/ui-management.h"
#include "include/c11-util.h"
#include <string.h>

int c11_ui_button_new(const unsigned int db_id, const unsigned int obj_id, const char *text, const int x, const int y, const char *callback)
{
	if(c11_util_id_check(db_id, obj_id)!=0)
		return(-1);
	
	uidb[db_id].obj[obj_id].type = OBJ_TYPE_BUTTON;
	uidb[db_id].obj[obj_id].text = strndup(text,sizeof(char)*strlen(text));
	uidb[db_id].obj[obj_id].x = x;
	uidb[db_id].obj[obj_id].y = y;
	uidb[db_id].obj[obj_id].w = strlen(text);
	uidb[db_id].obj[obj_id].h = 1;
	uidb[db_id].obj[obj_id].callback = strndup(callback,sizeof(char)*strlen(callback));
	
	uidb[db_id].obj[obj_id].has_obj=TRUE;
	
	return(0);
}
