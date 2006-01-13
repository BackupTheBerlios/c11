/***************************************************************************
 *            draw-global.h
 *
 *  Thu Jan 12 17:20:55 2006
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
 
#ifndef _DRAW_GLOBAL_H
#define _DRAW_GLOBAL_H

#ifdef __cplusplus
extern "C"
{
#endif

void c11_draw_background(void);

int c11_draw_window(unsigned int db_id);

#ifdef __cplusplus
}
#endif

#endif /* _DRAW_GLOBAL_H */
