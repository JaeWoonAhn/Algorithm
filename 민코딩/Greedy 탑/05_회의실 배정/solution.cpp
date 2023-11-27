#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct reservation {
	int start, end;
};
vector<reservation> v;

int N;

bool cmp(reservation left, reservation right) {
	if (left.end < right.end)	return true;
	if (left.end > right.end)	return false;

	if (left.start > right.start)	return true;
	if (left.start < right.start)	return false;

	return false;
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start>> end;

		v.push_back({ start, end });
	}

	sort(v.begin(), v.end(), cmp);

	int cnt = 1;
	int target = v[0].end;
	for (int i = 1; i < N; i++) {
		if (target <= v[i].start) {
			target = v[i].end;
			cnt++;
		}
	}
	cout << cnt;
	
}