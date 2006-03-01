/***************************************************************************
 *            config-init.c
 *
 *  Thu Jan 12 17:24:33 2006
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
#include "include/config/config-management.h"
#include <debug/memory.h>
#include <debug/log.h>
#include <config/config.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <slang.h>


/*
 *The cfgfile should first be tried to be fetched from the user's home directory
 *then in the environment variable C11CFG and finally
 *"/etc"
 */

int c11_config_init(void)
{      // char *source_etc=NULL;

        int ret;
	char *cfgfile=NULL;
	void *foo=NULL;
	const char *usrhome=getenv("HOME");

	char *source_home=strcat(usrhome,"/.c11.conf");

	//	fprintf(stderr, "source_home : %s\n", source_home);

	if(!access(source_home, R_OK))
          setenv("C11CFG", source_home, 1);
	
       
	   else if(!access("/etc/c11.conf", R_OK))
	   setenv("C11CFG", "/etc/c11.conf", 1); 

	cfgfile=getenv("C11CFG");

	if(cfgfile==NULL){
	  fprintf(stderr, "C11CFG not set correctly! Perhaps you would like to create a c11.conf file first! Copy the c11.conf from data directory of c11-server root to your home directory and save it as .c11.conf. Alternatively just copy it to your /etc directory (must be root) or atleast set the variable C11CFG to point to your c11.conf location :)\n");
	  exit(0);
	}
	
/*
	if((cfgfile=getenv("C11CFG"))==NULL)
	{
		if((cfgfile=malloc(sizeof(char)*(strlen(usrhome)+strlen(CONFIG_NAME)+2)))==NULL)
		{
			return(-1);
		}
		else
		{
			snprintf(cfgfile,(strlen(usrhome)+strlen(CONFIG_NAME)+2),"%s/.%s",usrhome,CONFIG_NAME);
			if(!cfg_open(cfgfile))
			{
				if((foo=realloc(cfgfile,sizeof(char)*strlen(CONFIG_ROOT)))==NULL)
				{
					return(-1);
				}
				else
				{
					strncpy(cfgfile,CONFIG_ROOT,strlen(CONFIG_ROOT));
					if(!cfg_open(cfgfile))
						return(-1);
					else
						return(0);
				}
			}
			else
			{
				return(0);
			}
		}
		}*/
       
	
		if(!cfg_open(cfgfile))
			return(-1);
		else
			return(0);
	

	return(-1);
}

void c11_config_close(void)
{
	cfg_close();
}

int c11_config_get_theme(void)
{
	int i,j;
	char *cat=NULL;
	char pth[128];

	cfg_get_enum(&confdb.background,"theme.background");

	for(i=0;i<=OBJ_TYPE_I;i++)
	{
		switch(i)
		{
			case OBJ_TYPE_BUTTON: cat="button"; break;
			case OBJ_TYPE_TEXTENTRY: cat="textentry"; break;
			case OBJ_TYPE_LABEL: cat="label"; break;
			case OBJ_TYPE_SELECTIONLIST: cat="selectionlist"; break;
			case OBJ_TYPE_CHECKLIST: cat="checklist"; break;
			case OBJ_TYPE_PROGRESSBAR: cat="progressbar"; break;
			case OBJ_TYPE_I: cat="window"; break;
		}
		
		for(j=0;j<THEME_TYPE_BG_I;j++)
		{
			sprintf(pth,"theme.%s.%s",cat,bg_types[j]);
			cfg_get_enum(&confdb.theme[i].bg[j],pth);
		}
		for(j=0;j<THEME_TYPE_FG_I;j++)
		{
			sprintf(pth,"theme.%s.%s",cat,fg_types[j]);
			cfg_get_enum(&confdb.theme[i].fg[j],pth);
		}		
		sprintf(pth,"theme.%s.dropshadow",cat);
		cfg_get_bool(&confdb.theme[i].dropshadow,pth);
	}
	return(0);	
}

/*unsigned long c11_config_color_lookup(const char *color)
{
	if(color==NULL)
		return(0x000000);
	
	if(strcmp(color,"black")==0)
		return(SLSMG_COLOR_BLACK);
	else if(strcmp(color,"red")==0)
		return(SLSMG_COLOR_RED);
	else if(strcmp(color,"green")==0)
		return(SLSMG_COLOR_GREEN);
	else if(strcmp(color,"brown")==0)
		return(SLSMG_COLOR_BROWN);
	else if(strcmp(color,"blue")==0)
		return(SLSMG_COLOR_BLUE);
	else if(strcmp(color,"magenta")==0)
		return(SLSMG_COLOR_MAGENTA);
	else if(strcmp(color,"cyan")==0)
		return(SLSMG_COLOR_CYAN);
	else if(strcmp(color,"lightgray")==0)
		return(SLSMG_COLOR_LGRAY);
	else if(strcmp(color,"gray")==0)
		return(SLSMG_COLOR_GRAY);
	else if(strcmp(color,"brightred")==0)
		return(SLSMG_COLOR_BRIGHT_RED);
	else if(strcmp(color,"brightgreen")==0)
		return(SLSMG_COLOR_BRIGHT_GREEN);
	else if(strcmp(color,"brightbrown")==0)
		return(SLSMG_COLOR_BRIGHT_BROWN);
	else if(strcmp(color,"brightblue")==0)
		return(SLSMG_COLOR_BRIGHT_BLUE);
	else if(strcmp(color,"brightcyan")==0)
		return(SLSMG_COLOR_BRIGHT_CYAN);
	else if(strcmp(color,"brightmagenta")==0)
		return(SLSMG_COLOR_BRIGHT_MAGENTA);
	else if(strcmp(color,"brightwhite")==0)
		return(SLSMG_COLOR_BRIGHT_WHITE);
	else
		return(0x000000);
}*/
