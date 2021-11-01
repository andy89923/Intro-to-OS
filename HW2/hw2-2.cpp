#include <iostream>
#include <vector>
#include <queue>
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
	
	// SJF
	bool operator < (const Job& rhs) const {
		if (cpu_time != rhs.cpu_time)
            return cpu_time > rhs.cpu_time;
        else
            return arv_time > rhs.arv_time;
	}
};

bool jobsID(Job& x, Job& y) {
	return x.pid < y.pid;
}

bool jobsArt(Job& x, Job& y) {
	return x.arv_time < y.arv_time;
}

vector<Job> jobs, ans;
vector<int> arvs, tims;
int n;

void init() {
	ans.clear();
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
	sort(jobs.begin(), jobs.end(), jobsArt);

	// SJF
	priority_queue<Job> pr;
	while (pr.size()) pr.pop();
	
	pr.push(jobs[0]);

	int now_time = 0, p = 1;
	for (int i = 1; i <= n; i++) {
		auto now = pr.top(); pr.pop();

		now_time = max(now_time, now.arv_time);
		now.wait_time = now_time - now.arv_time;
		now_time = now_time + now.cpu_time;
		now.turn_time = now_time - now.arv_time;	
		ans.push_back(now);

		while (p < n && jobs[p].arv_time <= now_time) {
			pr.push(jobs[p]);
			p += 1;
		}
		if (pr.size() == 0 && p < n) pr.push(jobs[p++]);
	}
	jobs = ans;

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
