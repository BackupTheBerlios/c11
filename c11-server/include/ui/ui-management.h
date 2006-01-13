/***************************************************************************
 *            ui-management.h
 *
 *  Thu Jan 12 17:10:58 2006
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
 
#ifndef _UI_MANAGEMENT_H
#define _UI_MANAGEMENT_H

#include <slang.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

enum WIN_TYPES
{
	WIN_TYPE_TOPLEVEL,
	WIN_TYPE_DOCK,
	WIN_TYPE_I
};
	
enum OBJ_TYPES
{
	OBJ_TYPE_BUTTON,
	OBJ_TYPE_TEXTENTRY,
	OBJ_TYPE_LABEL,
	OBJ_TYPE_SELECTIONLIST,
	OBJ_TYPE_CHECKLIST,
	OBJ_TYPE_PROGRESSBAR,
	OBJ_TYPE_I
};

int ui_db_size;

struct UI_DATABASE
{
	bool in_use;
	bool has_win;
	unsigned short type;
	unsigned short clientid;
	int x, y;
	unsigned int w, h;
	int obj_focused, obj_db_size;
	char *title;
	char *callback;
	
	struct OBJ_DATABASE
	{
		bool in_use;
		bool has_obj;
		unsigned short type;
		int x, y;
		unsigned int w, h;
		unsigned short value;
		char *text;
		char *callback;
		int list_db_size;
		struct LIST_DATABASE
		{
			bool selected;
			char *text;
		}*list;
	}*obj;	
}*uidb;

int c11_ui_init_main(void);
void c11_ui_init_exit(void);

int c11_ui_db_new(void);
void c11_ui_db_del(const int db_id);
int c11_ui_db_findfree(void);

int c11_ui_db_obj_new(const int db_id);
void c11_ui_db_obj_del(const int db_id, const int obj_id);
int c11_ui_db_obj_findfree(const int db_id);

int c11_ui_window_new(const unsigned int db_id, const unsigned short type, const char *title, const int x, const int y, const unsigned int w, const unsigned int h, const char *callback);
int c11_ui_window_del(const unsigned int db_id);
int c11_ui_window_set_title(const unsigned int db_id, const char *title);
int c11_ui_window_set_callback(const unsigned int db_id, const char *callback);
int c11_ui_window_move(const unsigned int db_id, const unsigned int x, const unsigned int y);
int c11_ui_window_resize(const unsigned int db_id, const unsigned int w, const unsigned int h);

int c11_ui_object_del(const unsigned int db_id, const unsigned int obj_id);
int c11_ui_object_set_text(const unsigned int db_id, const unsigned int obj_id, const char *text);
int c11_ui_object_set_callback(const unsigned int db_id, const unsigned int obj_id, const char *callback);
int c11_ui_object_move(const unsigned int db_id, const unsigned int obj_id, const unsigned int x, const unsigned int y);

int c11_ui_button_new(const unsigned int db_id, const unsigned int obj_id, const char *text, const int x, const int y, const char *callback);

int c11_ui_label_new(const unsigned int db_id, const unsigned int obj_id, const char *text, const int x, const int y);

int c11_ui_progressbar_new(const unsigned int db_id, const unsigned int obj_id, const unsigned short value, const int x, const int y, const unsigned int w);

int c11_ui_textentry_new(const unsigned int db_id, const unsigned int obj_id, const char *text, const int x, const int y, const unsigned int w, const char *callback);

int c11_ui_list_new(const unsigned int db_id, const unsigned int obj_id, const unsigned short type, const int x, const int y, const unsigned int w, const unsigned int h, const char *callback);
int c11_ui_list_add(const unsigned int db_id, const unsigned int obj_id, const char *text, const bool selected);
int c11_ui_list_clear(const unsigned int db_id, const unsigned int obj_id);

#ifdef __cplusplus
}
#endif

#endif /* _UI_MANAGEMENT_H */
