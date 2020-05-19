g: grep grep.c
	gcc -fprofile-arcs -Wall -ftest-coverage grep.c &>warning.txt
	./a.out
	gcov grep.c
	rm grep.gc*

gcovVI: grep.c.gcov
		vim grep.c.gcov

grep.c.gcov: g

vimC: 
		vim grep.c

clean: 
		rm grep.c.gcov a.out

