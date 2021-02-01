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
-D_DEBUG \
-std=c++17 \
-g -Og \
-Wall -Werror -Wpedantic \
-Wno-error=pedantic \
-Wno-error=unknown-pragmas \
-Wno-error=unused-variable \
-Wno-error=unused-but-set-variable
