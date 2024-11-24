# very simple makefile for my program
.POSIX:

CC = g++
CFLAGS = -lGL -lGLU -lglut
SRC = main.cpp scene.cpp sphere.cpp physics.cpp 
OBJ = Test

# this is a messy way of remove our test file

all:

clean:
	rm -f $(OBJ)

install:
	$(CC) -o $(OBJ) $(SRC) $(CFLAGS)
	@echo "Build Sucessful"

uninstall:
	rm -f $(OBJ)

.PHONY: all clean install uninstall
