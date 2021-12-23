11: 1_1.cpp
	g++ -o hw4_1_1 1_1.cpp –lpthread
	./hw4_1_1 < ./testcase/12000-1.txt


12: 1_2.cpp
	g++ -o hw4_1_2 1_2.cpp –lpthread
	./hw4_1_2 < ./testcase/12000-2.txt

2: pi.cpp
	g++ -o hw4_2 1_1.cpp –lpthread
	./hw4_2 < ./testcase/2.input

zip: 
	cp 1_1.cpp hw4_1_1.cpp
	cp 1_2.cpp hw4_1_2.cpp
	cp pi.cpp hw4_2.cpp
	zip 0816153_OS_hw4.zip hw4_1_1.cpp hw4_1_2.cpp hw4_2.cpp hw4_report.pdf
	rm -f hw4_1_1.cpp hw4_1_2.cpp hw4_2.cpp

clean:
	rm -f hw4_1_1.cpp hw4_1_2.cpp hw4_2.cpp
	rm -f hw4_1_1 hw4_1_2 hw4_2