all: 1 2 3 4
	echo "Make All Finished"

1: hw2-1.cpp
	g++ hw2-1.cpp -o hw2-1 -std=c++11

2: hw2-2.cpp
	g++ hw2-2.cpp -o hw2-2 -std=c++11

3: hw2-3.cpp
	g++ hw2-3.cpp -o hw2-3 -std=c++11

4: hw2-4.cpp
	g++ hw2-4.cpp -o hw2-4 -std=c++11

test: 1 2 3 4
	for i in 1 2 3 4; do echo Test $${i}; ./hw2-$${i} < ./Test_cases/Q$${i}.txt; echo "\n\n"; done

clean:
	rm -f hw2-1 hw2-2 hw2-3 hw2-4
