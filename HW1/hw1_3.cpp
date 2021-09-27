#include <iostream>
#include <unistd.h>
using namespace std;
#define MAX_LINE 80

int main() {
	char *arg[MAX_LINE/2+1];
	int keep_run = 1;
	
	while (keep_run) {
		cout << "OSH>";
		fflush(stdout);
		
				
		keep_run = 0;
		if (!keep_run) break;
	}
	return 0;
}
