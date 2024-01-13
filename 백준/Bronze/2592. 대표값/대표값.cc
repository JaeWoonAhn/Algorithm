#include <bits/stdc++.h>

using namespace std;

int Dat[1000];
vector<pair<int, int>> V;

bool comapre1(pair<int, int> a, pair<int, int>b) {
	return a.second < b.second;
}

int main() {

	int sum = 0;
	int maxNum = 0;
	int res = 0;
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		sum += num;

		int tmp = ++Dat[num];
		if (tmp > maxNum) {
			maxNum = tmp;
			res = num;
		}
	}

	cout << sum / 10 << endl;
	cout << res << endl;

}