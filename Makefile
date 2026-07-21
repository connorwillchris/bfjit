all:
	gcc bf.c -c bf.o
	gcc bfjit.c bf.o -o bfjit

clean:
	rm -rf bf.o
	rm -rf bfjit
