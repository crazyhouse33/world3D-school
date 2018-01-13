CC=g++
CFLAGS=
LDFLAGS= 
EXEC=is_k_HAC

all: $(EXEC)
$(EXEC): main.o
	@$(CC) $(CFLAGS) -O3 $(LDFLAGS) -o $(EXEC) main.o


debug: mainDebug.o
	@$(CC) $(CFLAGS) -g $(LDFLAGS) -o $(EXEC) mainDebug.o

mainDebug.o: main.cc graph.h graph.cc
	@$(CC) $(CFLAGS) -g -DDEBUG -o mainDebug.o -c main.cc

main.o: main.cc graph.h graph.cc
	@$(CC) $(CFLAGS) -O3 -o main.o -c main.cc

reboot:
	@rm -rf *.o
	@rm $(EXEC)
	@rm -rf *.txt
	@rm -rf *.dot
	@rm -rf *.svg
clean:
	@rm -rf *.o
	@rm -rf *.txt
	@rm -rf *.dot
	@rm -rf *.svg


