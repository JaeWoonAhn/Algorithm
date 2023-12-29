#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

void init() {
	cin >> N;
}

int solution() {
	int res = 1;

	while (res > 0) {
		int tmp = res;
		v.clear();
		while (tmp > 0) {
			v.push_back(tmp % 10);
			tmp /= 10;
		}

		int sum = res;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}
		if (sum == N) {
			return res;
		}
		res++;

		if (res > N) {
			return 0;
		}
	}

}

int main() {
	init();

	cout << solution() << endl;
	return 0;
}