ml_solve: main.o \
	ml_hypothesis.o \
	ml_hypothesis_brute.o \
	ml_hypothesis_gradient.o
	g++ -o ml_solve main.o ml_hypothesis.o ml_hypothesis_brute.o \
	ml_hypothesis_gradient.o

main.o: main.cpp
	g++ -g -c main.cpp

ml_hypothesis.o: ml_hypothesis.cpp ml_hypothesis.hpp
	g++ -g -c ml_hypothesis.cpp

ml_hypothesis_brute.o: ml_hypothesis_brute.cpp ml_hypothesis_brute.hpp
	g++ -g -c ml_hypothesis_brute.cpp

ml_hypothesis_gradient.o: ml_hypothesis_gradient.cpp ml_hypothesis_gradient.hpp
	g++ -g -c ml_hypothesis_gradient.cpp

clean:
	rm ml_solve main.o ml_hypothesis.o ml_hypothesis_brute.o \
        ml_hypothesis_gradient.o
