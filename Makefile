CXX = g++
CXXFLAGS = -g -Wall

Graph.o: Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp -o Graph.o

main: Main.cpp Graph.o
	$(CXX) $(CXXFLAGS) Main.cpp Graph.o -o main
