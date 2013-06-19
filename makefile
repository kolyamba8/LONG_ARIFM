all:
	gcc -c -fPIC first.c -o first.o
	gcc -shared -o libfirst.so first.o
	g++ -c -fPIC second.cpp -o second.o
	g++ -shared -L. -lfirst -o libsecond.so second.o
	swig -c++ -python -o third_wrap.cpp third.i
	gcc -fPIC -c third_wrap.cpp -o third_wrap.o -I/usr/include/python2.7
	g++ -shared third_wrap.o -L. -lsecond -lfirst -o _third.so
	g++ -c second_test.cpp
	g++ second_test.o -L. -lfirst -o RES
