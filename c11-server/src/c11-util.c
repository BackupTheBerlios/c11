/***************************************************************************
 *            c11-util.c
 *
 *  Thu Jan 12 21:44:47 2006
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

char *c11_util_catstr(const char *str, unsigned int position, unsigned int length)
{
	char *foo;
	
	if(str==NULL || length==0 || position>strlen(str) || (position+length)>strlen(str))
		return(NULL);
	
	if((foo=malloc(sizeof(char)*(length+1)))==NULL)
		return(NULL);
	
	strncpy(foo,&str[position],length);
	
	return(foo);
}

int c11_util_strcpy(char **dst, const char *src)
{
	char *foo=NULL;
	
	if((foo=realloc(*dst,sizeof(char)*strlen(src)))==NULL)
		return(-1);

	strncpy(foo,src,strlen(src));
	*dst=foo;
	
	return(0);
}

int c11_util_id_check(int db_id, int obj_id)
{
	if((db_id > ui_db_size || &uidb[db_id] == NULL) || (uidb[db_id].has_win==FALSE) || (obj_id > uidb[db_id].obj_db_size || &uidb[db_id].obj[obj_id] == NULL) || (uidb[db_id].obj[obj_id].has_obj==FALSE))
		return(-1);
	else
		return(0);
}

int c11_util_id_check2(int db_id)
{
	if((db_id > ui_db_size || &uidb[db_id] == NULL) || (uidb[db_id].has_win==FALSE))
		return(-1);
	else
		return(0);
}
