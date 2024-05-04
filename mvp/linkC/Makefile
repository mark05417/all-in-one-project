
# build a.cpp b.cpp to x.out
x.out: a.cpp b.cpp
	g++ -o x.out a.cpp b.cpp


a.o: a.cpp
	g++ -c a.cpp

b.o: b.cpp
	g++ -c b.cpp

# build a.o b.o to y.out
y.out: a.o b.o
	g++ -o y.out a.o b.o

# clean
clean:
	rm -f a.o b.o x.out y.out

