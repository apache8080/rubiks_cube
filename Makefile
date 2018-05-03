CC = clang++
CFLAGS = -std=c++11 -Wall
PROG = rubiks

SRCS = src/utils/controller.cpp src/utils/camera.cpp src/objects/cube.cpp src/main.cpp

OBJS = main.o cube.o camera.o controller.o

LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpthread -lm

ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
	LIBS = -lGLU -lGL -lglut
endif

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

clean:
	rm -f $(PROG) $(OBJS)
