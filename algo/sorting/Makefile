all : a.out

a.out : main.o utils.o
	g++ -o a.out main.o utils.o

main.o : main.cc
	g++ -c -g main.cc

utils.o : utils.cc
	g++ -c -g utils.cc

clean :
	rm *.o
	rm a.out
