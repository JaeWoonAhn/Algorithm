#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct score {
	int ct, cs;
};
vector<score> v;
int N;
bool cmp_score_ct(score left, score right) {

	if (left.ct < right.ct) return true;
	if (left.ct > right.ct) return false;
	
	return false;
}
bool cmp_score_cs(score left, score right) {

	if (left.cs < right.cs) return true;
	if (left.cs > right.cs) return false;
	
	return false;
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int ct, cs;
		cin >> ct >> cs;

		v.push_back({ ct,cs });
	}
	int v_size = v.size();
	sort(v.begin(), v.end(), cmp_score_ct);

	int cnt = 1;
	int target = v[0].cs;
	for (int i = 1; i < N; i++) {

		if (target > v[i].cs) {
			cnt++;
			target = v[i].cs;
		}
	}
	cout << cnt;
}