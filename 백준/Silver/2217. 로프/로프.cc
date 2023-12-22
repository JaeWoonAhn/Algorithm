#include <bits/stdc++.h>

using namespace std;

#define border 100
#define endl "\n"

int N;
vector<int> v;
int Max = 0;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
}

void solution() {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum = v[i] * (N - i);
		if (Max < sum) {
			Max =  sum;
		}
	}
}

int main() {

	init();
	solution();
	cout << Max << endl;

	return 0;
}