CC = g++
CFLAGS = -Wall
PROG = basicshapes

SRCS = main.cpp

ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
	LIBS = -lGLU -lGL -lglut
endif

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG)
