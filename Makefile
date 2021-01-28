all: car perf

car: car.cpp
	g++ -o car car.cpp -Wall -std=c++11

perf: perf.cpp
	g++ -o records records.cpp -Wall -std=c++11











