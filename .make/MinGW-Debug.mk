COMPILER:=x86_64-w64-mingw32-g++-posix
EXECUTABLE_SHELL:=powershell.exe

ROOT:=$(CURDIR)
BIN:=bin/MinGW
BUILD:=Debug
NAME_PREFIX:=
NAME_POSTFIX:=.exe
ARG:=

INCLUDE:=\
$(ROOT)/$(SRC)

LFLAG:=\
-lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf \


CFLAG:=\
-std=c++2a \
-D_DEBUG -Og -g \
-Wall -Wextra -Wpedantic -pedantic -pedantic-errors \
