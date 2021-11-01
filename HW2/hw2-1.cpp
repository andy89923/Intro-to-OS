#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
	int arv_time, cpu_time;
	int pid;
	int wait_time;
	int turn_time;

	Job(int art, int cpu, int id) {
		this -> arv_time = art;
		this -> cpu_time = cpu;
		this -> pid = id;

		wait_time = turn_time = 0;
	}

	bool operator < (const Job& rhs) const {
		return arv_time < rhs.arv_time;
	}
};

bool jobsID(Job& x, Job& y) {
	return x.pid < y.pid;
}

vector<Job> jobs;
vector<int> arvs, tims;
int n;

void init() {
	jobs.clear();
	arvs.clear(); arvs.push_back(0);
	tims.clear(); tims.push_back(0);
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		arvs.push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		tims.push_back(x);
	}
	for (int i = 1; i <= n; i++) jobs.push_back(Job(arvs[i], tims[i], i));
	sort(jobs.begin(), jobs.end());

	// FCFS
	int now_time = 0;
	for (auto& i : jobs) {
		now_time = max(now_time, i.arv_time);

		i.wait_time = now_time - i.arv_time;
		
		now_time += i.cpu_time;
		i.turn_time = now_time - i.arv_time;
	}


	sort(jobs.begin(), jobs.end(), jobsID);
	int wait_sum = 0, turn_sum = 0;
	for (auto i : jobs) {
		wait_sum += i.wait_time;
		turn_sum += i.turn_time;

		cout << i.wait_time << ' ' << i.turn_time << '\n';
	}
	cout << wait_sum << '\n';
	cout << turn_sum << '\n';

	return 0;
}
