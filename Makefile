CC=g++
CFLAGS=
LDFLAGS= -lGL -lglfw -lrt -lm -ldl -Iincludes -Ilibs -g #-Wall -Wextra -pedantic -O2
EXEC=3D_world

all: $(EXEC)
$(EXEC): 
	@find . -name "*.h" -exec ln -s .{} -t includes/ \; 2> /dev/null #putting all headers in /includes
	@$(CC) $(CFLAGS) $(LDFLAGS) view/loop.cc view/camera/camera.cc -o $(EXEC) 

clean:
	@rm -rf *.o
	@rm -f $(EXEC)
	



