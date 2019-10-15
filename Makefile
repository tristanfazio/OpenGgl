CC = g++
CFLAGS = -Wall 
EXEC = main
LIBS = -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor
SRCS = main.cpp
GLAD = glad.c

all: $(EXEC)

$(EXEC): $(SRCS) $(GLAD)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRCS) $(GLAD) $(LIBS)

run:
	./$(EXEC)

clean:
	rm -f $(EXEC)
	rm -f %.o

