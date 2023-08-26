#include <iostream>

using namespace std;
int N, M, P;
//int DAT[]
int arr[100000];
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> P;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	if (N == M) {
		cout << 1;
		return 0;
	}

	int cnt = 0;
	int left = 0;
	int right = 0;
	int sum = arr[0];
	int condition = right - left;
	while (right < N - 1) {
		// normal
		if (right - left < M - 1) {
			right++;
			sum += arr[right];
		}
		else {
			sum -= arr[left];
			left++;
		}
		if (right - left == M - 1) {
			if (sum < P) {
				cnt++;
			}
		}
	}
	right = N - M + 1;
	left = N - M + 1;
	sum = arr[N - M + 1];
	condition = 0;
	while (left < N) {
		// like linked list
		if (condition < M) {
			condition++;
			right++;
			if (right > N - 1) {
				right = 0;
			}
			sum += arr[right];
		}
		if (condition == M-1) {
			condition--;
			if (sum < P) {
				cnt++;
			}
			sum -= arr[left];
			left++;
		}

	}
	cout << cnt;

	return 0;
}
