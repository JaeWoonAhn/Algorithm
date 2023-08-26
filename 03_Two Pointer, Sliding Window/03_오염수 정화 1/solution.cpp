#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
int abs(int num) {
	if (num >= 0) {
		return num;
	}
	return -num;
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int left = 0;
	int right = v.size() - 1;
	int sum;
	int zero=9999999;
	int idx_left;
	int idx_right;
	while (left < right) {
		sum = v[left] + v[right];
		if (zero > abs(sum)) {
			zero = abs(sum);
			idx_left = left;
			idx_right = right;
		}

		if (sum > 0) {
			right--;
		}
		else {
			left++;
		}
	}
	
	cout << v[idx_left] << " " << v[idx_right];
	return 0;
}
