
FLAGS = -Wall -pthread
INCLUDES = ./include

all: prob2_parallel

clean:
	rm -f prob2_parallel *~

prob2_parallel: prob2_parallel.c
	gcc -I $(INCLUDES) -o prob2_parallel prob2_parallel.c $(FLAGS)