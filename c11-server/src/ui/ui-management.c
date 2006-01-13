/***************************************************************************
 *            ui-management.c
 *
 *  Thu Jan 12 17:56:36 2006
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
#include <stdlib.h>

int c11_ui_db_new(void)
{
	void *foo=NULL;
	int i, ret;
	
	if((i=c11_ui_db_findfree())==-1)
	{
		ui_db_size++;

		if((foo = realloc(uidb, sizeof(struct UI_DATABASE) * ui_db_size)) == NULL)
		{
			return(-1);
		}
		uidb = foo;
		
		ret = ui_db_size-1;
	}
	else
	{
		ret = i;
	}
	
	uidb[ret].title=NULL;
	uidb[ret].callback=NULL;
	uidb[ret].in_use=TRUE;
	uidb[ret].has_win=FALSE;
	uidb[ret].obj_db_size = 0;
	
	return(ret);
}

void c11_ui_db_del(const int db_id)
{
	if(db_id > ui_db_size || &uidb[db_id] == NULL)
		return;
	
	uidb[db_id].in_use=FALSE;
	return;
}

int c11_ui_db_findfree(void)
{
	int i;
	
	if(ui_db_size == -1)
		return(-1);
	
	for(i=0; i<=ui_db_size; i++)
	{
		if(&uidb[i]!=NULL && uidb[i].in_use==FALSE)
			return(i);
	}
	
	return(-1);
}

int c11_ui_db_obj_new(const int db_id)
{
	void *foo=NULL;
	int i,ret;
	
	if(db_id > ui_db_size || &uidb[db_id] == NULL)
		return(-1);

	if((i=c11_ui_db_obj_findfree(db_id))==-1)
	{
		uidb[db_id].obj_db_size++;
	
		if((foo = realloc(uidb[db_id].obj, sizeof(struct OBJ_DATABASE) * uidb[db_id].obj_db_size)) == NULL)
		{
			return(-1);
		}
	
		uidb[db_id].obj = foo;
		ret = uidb[db_id].obj_db_size-1;
	}
	else
	{
		ret = i;
	}
	
	uidb[db_id].obj[ret].text=NULL;
	uidb[db_id].obj[ret].callback=NULL;
	uidb[db_id].obj[ret].in_use=TRUE;
	uidb[db_id].obj[ret].has_obj=FALSE;
	
	return(ret);
}

void c11_ui_db_obj_del(const int db_id, const int obj_id)
{
	if((db_id > ui_db_size || &uidb[db_id] == NULL) || (obj_id > uidb[db_id].obj_db_size || &uidb[db_id].obj[obj_id] == NULL))
		return;
	
	uidb[db_id].obj[obj_id].in_use=FALSE;
	return;
}

int c11_ui_db_obj_findfree(const int db_id)
{
	int i;

	if(db_id > ui_db_size || &uidb[db_id] == NULL || db_id < 0)
		return(-1);
	
	if(uidb[db_id].obj_db_size == -1)
		return(-1);

	for(i=0; i<=uidb[db_id].obj_db_size; i++)
	{
		if(&uidb[db_id].obj[i]!=NULL && uidb[db_id].obj[i].in_use!=TRUE)
			return(i);
	}
	
	return(-1);
}
