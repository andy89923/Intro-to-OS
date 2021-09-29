#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <string>
using namespace std;
typedef pid_t PID;
#define MAXARG 80

int main() {
    char* arg[MAXARG];

    string cmd;

	while (true) {
		cout << "OSH>";
        fflush(stdout);
        
        int arg_cnt = 1;
        for (int i = 0; i < MAXARG; i++) arg[i] = NULL;

        getline(cin, cmd);
        int n = (int) cmd.length(), k;

        string pro_nam = "";
        for (int i = 0; i < n; i++) {
            if (cmd[i] == ' ' or cmd[i] == '\n') break;
            
            pro_nam += cmd[i];
            k = i;
        }
        arg[0] = strdup(pro_nam.c_str());

        string now = "";
        for (int i = k + 2; i < n; i++) {
            if (cmd[i] == ' ' or cmd[i] == '\n') {
                if (now == "") continue;

                arg[arg_cnt] = strdup(now.c_str());
                arg_cnt += 1;
                
                continue;
            }
            now += cmd[i];
        }
        if (now != "") {
            arg[arg_cnt] = strdup(now.c_str());
            arg_cnt += 1;
        }
	    if (pro_nam == "exit") break;

        PID pid = fork();
        if (pid == 0) {
            execvp(pro_nam.c_str(), arg);
            return 0;
        }
        wait(NULL);
	}
	return 0;
}
