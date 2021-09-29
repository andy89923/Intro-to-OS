all: 2 3

2: hw1_2.cpp
	g++ hw1_2.cpp -o 2.out

3: hw1_3.cpp
	g++ hw1_3.cpp -o shell

test: shell 2.out
	./2.out
	./shell

clean:
	rm shell
	rm 2.out
