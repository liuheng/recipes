all : a.out

a.out : main.o graph.o
	g++ -o a.out main.o graph.o

main.o : main.cc
	g++ -c -g main.cc

graph.o : graph.cc
	g++ -c -g graph.cc

clean :
	rm *.o
	rm a.out
