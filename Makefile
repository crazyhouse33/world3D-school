CC=g++
CFLAGS=
LDFLAGS= -lGLEW -lGLU -lGL -lglfw -lrt -lm -ldl -Iincludes -Ilibs -g #-Wall -Wextra -pedantic -O2
EXEC=3D_world

all: $(EXEC)

$(EXEC): clean 
	@find . -name "*.h" -exec ln -s .{} -t includes/ \; 2> /dev/null #putting all headers in /includes
	@$(CC) $(CFLAGS) $(LDFLAGS) main.cc view/camera/camera.cc view/interface/inputmanager.cc view/interface/interface.cc view/drawer/gpu/Shader.cpp view/drawer/gpu/gpu.cc -o $(EXEC) 


.PHONY: clean debug
clean:
	@rm -rf *.o
	@rm -f $(EXEC)
	
debug: LDFLAGS += -DDEBUG
debug: $(EXEC) 




