#!/bin/bash

#TODO: multiple grep test case

function make_compile(){
	
	gcc -fprofile-arcs -ftest-coverage -c grep.c &> err.txt
	gcc -fprofile-arcs -ftest-coverage -o $1 grep.o 

	echo -e "compile!\n"

}

function make_gcov(){

	gcov -f grep.c

}

function make_clean(){

	cat grep.c.gcov | grep "#####" > grepS.txt
	rm grep.gc* fgrep grep egrep grep.o

}

make_compile grep
make_compile egrep
make_compile fgrep

echo -e "case 0000\n"

./grep -f | ./grep Error > result.txt

#make_gcov

echo -e "case 0001\n"

./grep -A 10 -B 3 -CVcbhilnqsvwx "*exdir" * >> result.txt

#make_gcov

echo -e "case 0010\n"

./egrep -G -f pattern.txt yesterday.txt |./egrep -E -v  -e 'foo' -e '(no)+' >> result.txt

#make_gcov

echo -e "case 0011\n"

./fgrep -F '-self.+' * | ./grep -E '^\(?[0-9]{3}\)? [:xdigit:]{3}-[0-9]{4}$' >> result.txt

#make_gcov

echo -e "case 0100 \n"

./grep "asdfkjasl;fkjawoiejfoijfknxvm.x,cmvcmvknjafjsdlfkalkdfjowiejfdfhjashglsdajfcpoi  pqokmldknvjnvjbjjfdslkjksdfjklasdjfadofjekmfldkafmjlksadjfkdjfkjfkdjkfsjflsiewnc vbzc,xnvcnvz.cxvjpwejlkmvkdnkjlhgdskfmds.,mfndkflafjlsdfasmfkjdkfjijqnjnbcnv,mxvc,mvnz,.mvkjsdijfijweoif,m.akd;fkdfkpdfnbcxnvm,mccccccccccccccccckkkkkkkkkkkkkwwwwwwwwwwwwwwwwwwwwwwwwwoooooooozzzzzzzzzzzzzzzzzzzppppppppppppppppppppppppppppppqwe.fmdsmfdsjvnjbvnxmclfksadf --adsfkljaskfjlk2349787t90281-9e0e-wif0di0-i-0ijajds;flksjflkjklfjk1jkl2jkjfijdsoijfajflkdsjfkjkaldjflkdjfljvic9vi9++++++++++++++++++asdfkjasl;fkjawoiejfoijfknxvm.x,cmvcmvknjafjsdlfkalkdfjowiejfdfhjashglsdajfpoi  pqokmldknvjnvjbjjfdslkjksdfjklasdjfadofjekmfldkafmjlksadjfkdjfkjfkdjkfsjflsiewnc vbzc,xnvcnvz.cxvjpwejlkmvkdnkjlhgdskfmds.,mfndkflafjlsdfasmfkjdkfjijqnjnbcnv,mxvc,mvnz,.mvkjsdijfijweoif,m.akd;fkdfkpdfnbcxnvm,mccccccccccccccccckkkkkkkkkkkkkwwwwwwwwwwwwwwwwwwwwwwwwwoooooooozzzzzzzzzzzzzzzzzzzppppppppppppppppppppppppppppppqwe.fmdsmfdsjvnjbvnxmclfksadf --adsfkljaskfjlk2349787t90281-9e0e-wif0di0-i-0ijajds;flksjflkjklfjk1jkl2jkjfijdsoijfajflkdsjfkjkaldjflkdjfljvic9vi9++++++++++++++++++i" * >> result.txt

make_gcov

echo -e "case 0101\n"

echo -e "case 0110\n"

echo -e "case 0111\n"

echo -e "case 1000\n"

echo -e "case 1001\n"

make_clean
