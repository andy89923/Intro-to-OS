CXX := g++
THREAD := -lpthread

1: 1_1.cpp
	$(CXX) 1_1.cpp -o hw4_1_1.o $(THREAD)
	./hw4_1_1.o < ./testcase/12000-1.txt


2: 1_2.cpp
	$(CXX) 1_2.cpp -o hw4_1_2.o $(THREAD)
	./hw4_1_2.o < ./testcase/12000-2.txt

pi: pi.cpp
	$(CXX) pi.cpp -o pi.o $(THREAD)
	./pi.o < ./testcase/2.input

test: pi 1 2
	./hw4_1_1.o < ./testcase/12000-1.txt
	./hw4_1_2.o < ./testcase/12000-2.txt
	./pi.o < ./testcase/2.input

zip: 
	cp 1_1.cpp hw4_1_1.cpp
	cp 1_2.cpp hw4_1_2.cpp
	cp pi.cpp hw4_2.cpp
	cp report.pdf hw4_report.pdf
	zip 0816153_OS_hw4.zip hw4_1_1.cpp hw4_1_2.cpp hw4_2.cpp hw4_report.pdf
	rm -f hw4_1_1.cpp hw4_1_2.cpp hw4_2.cpp hw4_report.pdf

clean:
	rm -f hw4_1_1.cpp hw4_1_2.cpp hw4_2.cpp
	rm -f *.o
