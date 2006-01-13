/***************************************************************************
 *            ui-window.c
 *
 *  Thu Jan 12 20:51:30 2006
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

int c11_ui_window_new(const unsigned int db_id, const unsigned short type, const char *title, const int x, const int y, const unsigned int w, const unsigned int h, const char *callback)
{	
	if(&uidb[db_id]==NULL || uidb[db_id].has_win==TRUE)
		return(-1);

	if(type!=WIN_TYPE_TOPLEVEL && type!=WIN_TYPE_DOCK)
		return(-1);

	uidb[db_id].type = type;
	uidb[db_id].title = strndup(title,sizeof(char)*strlen(title));
	uidb[db_id].x = x;
	uidb[db_id].y = y;
	uidb[db_id].w = w;
	uidb[db_id].h = h;
	uidb[db_id].callback = strndup(callback,sizeof(char)*strlen(callback));
	
	uidb[db_id].has_win=TRUE;
	
	return(0);
}

int c11_ui_window_del(const unsigned int db_id)
{
	int i;
	
	if(&uidb[db_id]==NULL || uidb[db_id].has_win==FALSE)
		return(-1);;
	
	free(uidb[db_id].title);
	free(uidb[db_id].callback);
	
	for(i=0;i<=uidb[db_id].obj_db_size;i++)
	{
		c11_ui_object_del(db_id, i);
	}
	
	uidb[db_id].has_win=FALSE;
	
	return(0);
}

int c11_ui_window_set_title(const unsigned int db_id, const char *title)
{
	if(&uidb[db_id]==NULL || uidb[db_id].has_win==FALSE)
		return(-1);

	return(c11_util_strcpy(&uidb[db_id].title,title));
}

int c11_ui_window_set_callback(const unsigned int db_id, const char *callback)
{
	if(&uidb[db_id]==NULL || uidb[db_id].has_win==FALSE)
		return(-1);

	return(c11_util_strcpy(&uidb[db_id].callback,callback));
}

int c11_ui_window_move(const unsigned int db_id, const unsigned int x, const unsigned int y)
{
	if(&uidb[db_id]==NULL || uidb[db_id].has_win==FALSE)
		return(-1);
	
	uidb[db_id].x=x;
	uidb[db_id].y=y;
	
	return(0);
}

int c11_ui_window_resize(const unsigned int db_id, const unsigned int w, const unsigned int h)
{
	if(&uidb[db_id]==NULL || uidb[db_id].has_win==FALSE)
		return(-1);
	
	uidb[db_id].w=w;
	uidb[db_id].h=h;
	
	return(0);
}
