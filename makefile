bin/main: main.o random.o file.o
	gcc main.o random.o file.o -o bin/main
	
main.o: src/main.c inc/random.h inc/file.h
	gcc -I inc -c src/main.c

random.o: src/random.c inc/random.h
	gcc -I inc -c src/random.c

file.o: src/file.c inc/file.h inc/random.h
	gcc -I inc -c src/file.c
