CXX := g++-7

st: ST.cpp
	$(CXX) -std=c++11 -o st ST.cpp -O3
	./st < ./Testcase/test.in

ac_st: st
	./st < ./Testcase/input1.txt > output.txt && diff -w --suppress-common-lines ./Testcase/answer1.txt output.txt | wc -l && rm -f output.txt
	./st < ./Testcase/input2.txt > output.txt && diff -w --suppress-common-lines ./Testcase/answer2.txt output.txt | wc -l && rm -f output.txt

mt: MT_best.cpp MT_worst.cpp
	$(CXX) -std=c++11 -o mt_best  MT_best.cpp -O3 -lpthread
	$(CXX) -std=c++11 -o mt_worst MT_worst.cpp -O3 -lpthread
	./mt_best < ./Testcase/test.in 
	./mt_worst < ./Testcase/test.in

ac_mt: mt
	./mt_best < ./Testcase/input1.txt > output.txt && diff -w --suppress-common-lines ./Testcase/answer1.txt output.txt | wc -l && rm -f output.txt
	./mt_best < ./Testcase/input2.txt > output.txt && diff -w --suppress-common-lines ./Testcase/answer2.txt output.txt | wc -l && rm -f output.txt
	./mt_worst < ./Testcase/input2.txt > output.txt && diff -w --suppress-common-lines ./Testcase/answer2.txt output.txt | wc -l && rm -f output.txt
	./mt_worst < ./Testcase/input2.txt > output.txt && diff -w --suppress-common-lines ./Testcase/answer2.txt output.txt | wc -l && rm -f output.txt

test: st mt
	time (./st  < ./Testcase/input2.txt > output.txt)
	time (./mt_worst < ./Testcase/input2.txt > output.txt)
	time (./mt_best  < ./Testcase/input2.txt > output.txt)

clean:
	rm -f st mt* output.txt 
