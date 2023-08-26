#include <iostream>
#include <vector>	
#include <algorithm>

using namespace std;
int N, Q;
vector<int> v;
int Min, Max;
int bsearch_low() {
	int s = 0;
	int e = v.size() - 1;

	while (s <= e) {
		int mid = (s + e) / 2;
		int sel = v[mid];

		if (sel >= Min) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return s;
}
int bsearch_upper() {
	int s = 0;
	int e = v.size() - 1;

	while (s <= e) {
		int mid = (s + e) / 2;
		int sel = v[mid];

		if (sel <= Max) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	return e;
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> Q;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < Q; i++) {
		cin >> Min >> Max;

		// lower bound
		int idx_low = bsearch_low();
		// upper bound
		int idx_up = bsearch_upper();
		cout << idx_up - idx_low + 1 << "\n";
	}
	return 0;
}