#include <iostream>
#include <queue>

using namespace std;

struct spool {
	int start_time;
	int turnaround_time;
	int priority;
};

struct cmp_startTime {
	bool operator()(spool left, spool right) {
		if (left.start_time > right.start_time)	return true;
		if (left.start_time < right.start_time)	return false;

		return false;
	}
};

struct cmp_priority {
	bool operator()(spool left, spool right) {
		if (left.priority > right.priority)	return true;
		if (left.priority < right.priority)	return false;

		return false;
	}
};
int N;
priority_queue<spool, vector<spool>, cmp_startTime> pq_startTime;
priority_queue<spool, vector<spool>, cmp_priority> pq_priority;
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int startTime;
		int turnaroundTime;
		spool list;

		cin >> startTime >> turnaroundTime;

		list.priority = i;
		list.start_time = startTime;
		list.turnaround_time = turnaroundTime;

		pq_startTime.push(list);
	}

	int max = 0;
	int now = 0;
	now = pq_startTime.top().start_time + pq_startTime.top().turnaround_time;
	pq_startTime.pop();

	while (!pq_startTime.empty()) {
		if (now >= pq_startTime.top().start_time) {
			pq_priority.push(pq_startTime.top());
			pq_startTime.pop();
		}
		else {
			if (!pq_priority.empty()) {
				if (max < now - pq_priority.top().start_time) {
					max = now - pq_priority.top().start_time;
				}
				now += pq_priority.top().turnaround_time;
				pq_priority.pop();
			}
			else {
				// pq_priority를 다 pop했는데 더 들어온 녀석이 없으면
				// Pq_startTIme에서 새로운 now로 초기화
				now = pq_startTime.top().start_time + pq_startTime.top().turnaround_time;
				pq_startTime.pop();
			}
		}
	}
	
	while (!pq_priority.empty()) {
		
		if (max < now - pq_priority.top().start_time) {
			max = now - pq_priority.top().start_time;
		}
		now += pq_priority.top().turnaround_time;
		pq_priority.pop();
	}

	cout << max;

}