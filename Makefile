CC = g++
CFLAGS = -std=c++17
EXEC = main
LINUXLIBS = -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor
MACLIBS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo 
SRCS = main.cpp ground.cpp trees.cpp wall.cpp sven.cpp watersheep.cpp torch.cpp utils/textureloader.cpp utils/stb_image.c
GLAD = glad.c

all: $(EXEC)

$(EXEC): $(SRCS) $(GLAD)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRCS) $(GLAD) $(MACLIBS)

run:
	./$(EXEC)

clean:
	rm -f $(EXEC)
	rm -f %.o

