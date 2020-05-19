splayTree: splayTree SplayTree.c
	gcc -fprofile-arcs -ftest-coverage SplayTree.c		
	./a.out
	gcov SplayTree.c
	rm SplayTree.gc*

gcovVI: SplayTree.c.gcov
		vim SplayTree.c.gcov

SplayTree.c.gcov: splayTree

vimC: 
		vim SplayTree.c

clean: 
		rm SplayTree.c.gcov a.out
