/***************************************************************************
 *            ui-list.c
 *
 *  Thu Jan 12 20:59:37 2006
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

int c11_ui_list_new(const unsigned int db_id, const unsigned int obj_id, const unsigned short type, const int x, const int y, const unsigned int w, const unsigned int h, const char *callback)
{
	if(c11_util_id_check(db_id, obj_id)!=0)
		return(-1);
	
	if(type!=OBJ_TYPE_CHECKLIST || type!=OBJ_TYPE_SELECTIONLIST)
		return(-1);
	
	uidb[db_id].obj[obj_id].type = type;
	uidb[db_id].obj[obj_id].text = NULL;
	uidb[db_id].obj[obj_id].x = x;
	uidb[db_id].obj[obj_id].y = y;
	uidb[db_id].obj[obj_id].w = w;
	uidb[db_id].obj[obj_id].h = h;
	uidb[db_id].obj[obj_id].callback = strndup(callback,sizeof(char)*strlen(callback));
	uidb[db_id].obj[obj_id].list_db_size=-1;	
	
	uidb[db_id].obj[obj_id].has_obj=TRUE;
	
	return(0);
}

int c11_ui_list_add(const unsigned int db_id, const unsigned int obj_id, const char *text, const bool selected)
{
	void *foo=NULL;

	if(c11_util_id_check(db_id, obj_id)!=0)
		return(-1);
	
	uidb[db_id].obj[obj_id].list_db_size++;

	if((foo = realloc(uidb[db_id].obj[obj_id].list, sizeof(struct UI_DATABASE) * uidb[db_id].obj[obj_id].list_db_size)) == NULL)
	{
		return(-1);
	}
	uidb[db_id].obj[obj_id].list = foo;
	
	uidb[db_id].obj[obj_id].list[(uidb[db_id].obj[obj_id].list_db_size-1)].text = strndup(text,sizeof(char)*strlen(text));
	uidb[db_id].obj[obj_id].list[(uidb[db_id].obj[obj_id].list_db_size-1)].selected=selected;
		
	return(0);
}

int c11_ui_list_clear(const unsigned int db_id, const unsigned int obj_id)
{
	unsigned int i;
	
	if(c11_util_id_check(db_id, obj_id)!=0)
		return(-1);
	
	for(i=0;i<=uidb[db_id].obj[obj_id].list_db_size;i++)
	{
		free(uidb[db_id].obj[obj_id].list[i].text);
		uidb[db_id].obj[obj_id].list[i].selected=FALSE;
	}
	free(uidb[db_id].obj[obj_id].list);
	uidb[db_id].obj[obj_id].list_db_size=-1;	

	return(0);
}
