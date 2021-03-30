COMPILER:=x86_64-w64-mingw32-g++-posix
EXECUTABLE_SHELL:=powershell.exe

ROOT:=$(CURDIR)
BIN:=bin/MinGW
BUILD:=Release
NAME_PREFIX:=
NAME_POSTFIX:=.exe
ARG:=

INCLUDE:=\
$(ROOT)/$(SRC)

LFLAG:=\
-lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -mwindows \


CFLAG:=\
-std=c++2a \
-DNDEBUG -O3 \
