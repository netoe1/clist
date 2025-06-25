all:
	gcc -o main ./src/main.c ./slist.c
clean:
	rm -f *.exe