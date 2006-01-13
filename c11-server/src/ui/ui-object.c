/***************************************************************************
 *            ui-object.c
 *
 *  Thu Jan 12 21:24:04 2006
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
#include <stdlib.h>

int c11_ui_object_del(const unsigned int db_id, const unsigned int obj_id)
{
	if(c11_util_id_check(db_id, obj_id)!=0)
		return(-1);

	free(uidb[db_id].obj[obj_id].text);
	free(uidb[db_id].obj[obj_id].callback);
	uidb[db_id].obj[obj_id].has_obj=FALSE;
	
	return(0);
}

int c11_ui_object_set_text(const unsigned int db_id, const unsigned int obj_id, const char *text)
{
	if(c11_util_id_check(db_id, obj_id)!=0)
		return(-1);
	
	return(c11_util_strcpy(&uidb[db_id].obj[obj_id].text,text));
}

int c11_ui_object_set_callback(const unsigned int db_id, const unsigned int obj_id, const char *callback)
{
	if(c11_util_id_check(db_id, obj_id)!=0)
		return(-1);
	
	return(c11_util_strcpy(&uidb[db_id].obj[obj_id].callback,callback));
}

int c11_ui_object_move(const unsigned int db_id, const unsigned int obj_id, const unsigned int x, const unsigned int y)
{
	if(c11_util_id_check(db_id, obj_id)!=0)
		return(-1);
	
	uidb[db_id].obj[obj_id].x=x;
	uidb[db_id].obj[obj_id].y=y;
	
	return(0);
}
