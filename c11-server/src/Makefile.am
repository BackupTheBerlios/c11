## Process this file with automake to produce Makefile.in

## Created by Anjuta - will be overwritten
## If you don't want it to overwrite it,
## 	Please disable it in the Anjuta project configuration

INCLUDES =

AM_CFLAGS =\
	 -Wall -Wimplicit -Wreturn-type -Wunused -Wswitch -Wuninitialized -Wparentheses -Wshadow -Wpointer-arith -Wmissing-prototypes -Winline\
	 -g

bin_PROGRAMS = c11

c11_SOURCES = \
	c11-main.c\
	client/client-init.c\
	config/config-init.c\
	ui/ui-init.c\
	ui/ui-management.c\
	ui/ui-button.c\
	ui/ui-window.c\
	ui/ui-textentry.c\
	ui/ui-label.c\
	ui/ui-list.c\
	ui/ui-progressbar.c\
	ui/ui-object.c\
	c11-util.c\
	draw/draw-global.c\
	draw/draw-window.c

c11_LDFLAGS = 

c11_LDADD = \
	-lslang -lpthread -ldebug -lconfig

