CXX = g++

#compile Targets

all:
	$(CXX) main.cpp wordCount.cpp wordHash.cpp -o wordHashTest
