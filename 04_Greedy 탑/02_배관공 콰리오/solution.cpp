#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, L;
	cin >> N >> L;
	int cnt = 1;

	vector<int> v;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		q.push(temp);
	}

	int now = q.top();
	q.pop();

	while (!q.empty()) {

		int next = q.top();
		if (next >= now + L) {
			cnt++;
			now = next;
		}
		else {
			q.pop();
		}
	}
	cout << cnt;
}