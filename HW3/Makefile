st: 0816153_ST.cpp
	g++-7 -o st 0816153_ST.cpp -O3
	./st < ./Testcase/input1.txt > output.txt && diff -w --suppress-common-lines ./Testcase/answer1.txt output.txt && rm -f output.txt | wc -l
	./st < ./Testcase/input2.txt > output.txt && diff -w --suppress-common-lines ./Testcase/answer2.txt output.txt && rm -f output.txt | wc -l

mt: 0816153_MT_best.cpp
	g++-7 -o mt 0816153_MT_best.cpp -O3 -lpthread
	./mt < ./Testcase/test.in 

test_mt: mt
	./mt < ./Testcase/input1.txt > output.txt && diff -w --suppress-common-lines ./Testcase/answer1.txt output.txt && rm -f output.txt | wc -l
	./mt < ./Testcase/input2.txt > output.txt && diff -w --suppress-common-lines ./Testcase/answer2.txt output.txt && rm -f output.txt | wc -l


clean:
	rm -f st 