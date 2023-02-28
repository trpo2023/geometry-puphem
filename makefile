hello: main.o file1.o file2.o
	gcc main.o file1.o file2.o
main.c:
	gcc -c main.c
file1.o:
	gcc -c file1.c
file2.o:
	gcc -c file2.c
