
CFLAGS=-Wall -g

all: bin_search_stl bin_search_recursive bin_search_iterative

bin_search_recursive:
	g++ $(CFLAGS) bin_search_recursive.cpp -o bin_search_recursive.exe

bin_search_iterative:
	g++ $(CFLAGS) bin_search_iterative.cpp -o bin_search_iterative.exe

bin_search_stl:
	g++ $(CFLAGS) bin_search_stl.cpp -o bin_search_stl.exe

clean:
	rm *.exe

