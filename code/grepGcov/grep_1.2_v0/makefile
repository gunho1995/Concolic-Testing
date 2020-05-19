g: grep.o
	gcc -fprofile-arcs -ftest-coverage -o grp grep.o 
	./grp >result.txt
	gcov grep.c
	rm grep.gc*

grep.o: grep.c
		gcc -fprofile-arcs -ftest-coverage -c grep.c &> err.txt

gcovVI: grep.c.gcov
		vim grep.c.gcov

grep.c.gcov: g

vimC: 
		vim grep.c

clean: 
		rm grep.c.gcov grp grep.o

