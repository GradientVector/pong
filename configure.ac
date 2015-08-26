dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(pong, 1.0)
AC_CONFIG_MACRO_DIRS([m4])


AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

AC_PROG_CC
SDL_VERSION=2.0.0
AM_PATH_SDL2($SDL_VERSION,
             :,
             AC_MSG_ERROR([*** SDL version $SDL_VERSION not found!])
)
CFLAGS="$CFLAGS $SDL_CFLAGS"
LIBS="$LIBS $SDL_LIBS"

AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT

