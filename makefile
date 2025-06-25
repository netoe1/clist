all:
	gcc -o main ./src/main.c ./clist.c
clean:
	rm -f *.exe