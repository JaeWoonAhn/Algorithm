#include <iostream>

using namespace std;

int N, M;
int arr[10001];
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = 0;
	int sum = arr[0];
	int cnt = 0;

	while(right<N) {
		if (sum == M) {
			cnt++;
		}
		if (sum <= M) {
			right++;
			sum += arr[right];
		}
		else {
			sum -= arr[left];
			left++;
		}
	}
	cout << cnt;
}