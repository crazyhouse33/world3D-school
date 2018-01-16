CC=g++
CFLAGS=
LDFLAGS= -lGL -lglfw -lrt -lm -ldl -Iincludes -Ilibs -g -Wall -Wextra -pedantic -O2


EXEC=3D_world

all: $(EXEC)
$(EXEC): 
	@$(CC) $(CFLAGS) $(LDFLAGS) view/loop.cc -o $(EXEC) 

clean:
	@rm -rf *.o
	@rm -f $(EXEC)
	



