/***************************************************************************
 *            ui-init.c
 *
 *  Thu Jan 12 17:25:07 2006
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

#include "include/ui/ui-management.h"

int c11_ui_init_main(void)
{
	SLtt_get_terminfo();
	SLang_init_tty(-1,0,0);
	SLsmg_init_smg();
	SLsmg_cls();
	SLsmg_refresh();
	
	return(0);
}

void c11_ui_init_exit(void)
{
	SLsmg_cls();
	SLsmg_refresh();
	SLsmg_reset_smg();
	SLang_reset_tty();
	return;
}
