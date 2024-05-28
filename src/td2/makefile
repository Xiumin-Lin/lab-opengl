BIN = OpenGL_101
CC = g++
FLAGS = -std=c++11 -Wall -pedantic -mmacosx-version-min=10.9 -arch arm64 -fmessage-length=0
INC = -I/opt/homebrew/opt/glew/include -I/opt/homebrew/opt/glfw/include
LOC_LIB = -L/opt/homebrew/opt/glew/lib -L/opt/homebrew/opt/glfw/lib -lGLEW -lglfw
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit
SRC = main.cpp ../common/GLShader.cpp

all:
	${CC} ${FLAGS} ${FRAMEWORKS} -o ${BIN} ${SRC} ${INC} ${LOC_LIB}

clean:
	rm -f ${BIN}
