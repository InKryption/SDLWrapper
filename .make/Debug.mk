COMPILER:=x86_64-w64-mingw32-g++-posix
ROOT:=$(CURDIR)
BIN:=bin
SRC:=src
BUILD:=Debug
NAME:=PROJECT
ARG:=

INCLUDE:=\
$(ROOT)/$(SRC)

LIBRARY:=
LIBNAME:=

LFLAG:=

CFLAG:=\
-D_DEBUG -g -Og \
-std=c++17 \
-Wall -Wextra -Wpedantic -ansi -pedantic -pedantic-errors

