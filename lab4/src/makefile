CC=gcc
CFLAGS=-I.

all : parallel_min_max zombie_making process_memory parallel_sum

parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c $(CFLAGS)

zombie_making: zombie_making.c
	@$(CC) -o zombie_making zombie_making.c $(CFLAGS)
	@chmod u+rwx ./zombie_making

process_memory : process_memory.c
	@$(CC) process_memory.c -o process_memory $(CFLAGS)

parallel_sum: parallel_sum.c sum.o utils.o
	@$(CC) -o parallel_sum utils.o sum.o parallel_sum.c -lpthread $(CFLAGS)

find_min_max.o : utils.o find_min_max.h find_min_max.c
	@$(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)

utils.o : utils.h utils.c
	@$(CC) -o utils.o -c utils.c $(CFLAGS)

sum.o : sum.h sum.c
	$(CC) -o sum.o -c sum.c $(CFLAGS)

clean :
	rm utils.o find_min_max.o parallel_min_max zombie_making process_memory