/***************************************************************************
 *            c11-util.h
 *
 *  Thu Jan 12 21:57:34 2006
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
 
#ifndef _C11_UTIL_H
#define _C11_UTIL_H

#ifdef __cplusplus
extern "C"
{
#endif

char *c11_util_catstr(const char *str, unsigned int position, unsigned int length);
int c11_util_strcpy(char **dst, const char *src);
int c11_util_id_check(int db_id, int obj_id);
int c11_util_id_check2(int db_id);

#ifdef __cplusplus
}
#endif

#endif /* _C11_UTIL_H */
