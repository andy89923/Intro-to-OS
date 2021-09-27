#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
typedef pid_t PID; 

void printInfo(int num, pid_t nowPID, pid_t parPID) {
	cout << "Fork " << num << ". ";
	cout << "I'm the child " << nowPID << ", ";
	cout << "my parent is " << parPID << ".\n";
}

int main() {
	PID pid = getpid();
	cout << "Main Process ID : " << pid << "\n\n"; 

	PID pid_1 = fork();
	if (pid_1 == 0) {
		printInfo(1, getpid(), getppid());
		
		PID pid_4 = fork();
		if (pid_4 == 0) {
			printInfo(4, getpid(), getppid());
			
			PID pid_5 = fork();
			if (pid_5 == 0) {
				printInfo(5, getpid(), getppid());
				return 0;
			}
			wait(NULL);
			return 0;
		}
		wait(NULL);
		return 0;
	}
	wait(NULL);

	PID pid_2 = fork();
	if (pid_2 == 0) {
		printInfo(2, getpid(), getppid());
	}
	if (pid_2 != 0) wait(NULL);

	PID pid_3 = fork();
	if (pid_3 == 0) {	
		printInfo(3, getpid(), getppid());
	}
	if (pid_3 != 0) wait(NULL);
	
	return 0;
}
