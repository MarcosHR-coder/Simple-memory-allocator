CFLAGS = -Wall -Wextra -std=c11 -pedantic

run: program
	./bin/program

program: test.o allocator.o
	gcc -o ./bin/program ./bin/test.o ./bin/allocator.o

test.o:
	gcc $(CFLAGS) -c -o ./bin/test.o ./src/test.c

allocator.o:
	gcc $(CFLAGS) -c -o ./bin/allocator.o ./src/allocator.c

debug:
	gcc $(CFLAGS) -o ./bin/program ./src/test.c ./src/allocator.c -ggdb
	gdb ./bin/program

help:
	@echo "Make project's configuration usage:"
	@echo "- Command 'make' compiles and executes the program"
	@echo "- Command 'make program' only compiles the program"
	@echo "- Command 'make debug' compiles for debug and debugs program with gdb"
