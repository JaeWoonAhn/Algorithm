#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int K;
vector<int> v;
queue<int> q;
char binary_search(int start , int end, int target) {
	int mid = (start + end) / 2;
	//cout << mid << endl;
	if (start > end) {
		return 'X';
	}

	if (v[mid] == target) {
		return 'O';
	}
	else if (v[mid] > target) {
		binary_search(start, mid - 1, target);
	}
	else {
		binary_search(mid+1, end, target);
	}
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
	cin >> K;
	for (int i = 0; i < K; i++) {
		int target;
		cin >> target;
		cout << binary_search(0, v.size() - 1, target);
	}
}