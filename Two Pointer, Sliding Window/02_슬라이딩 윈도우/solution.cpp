#include <iostream>
#include <climits>
using namespace std;

int T;
int N, W;
int arr[100001];
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> W;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		int left = 0;
		int right = -1;
		int max_left = 0;
		int max_right = 0;
		int sum = 0;
		int max = INT_MIN;
		while (left < N-1 && right < N-1) {
			if (right - left < W-1) {
				right++;
				sum += arr[right];
			}
			else {
				sum -= arr[left];
				left++;
			}
			if (right - left == W-1) {
				if (max < sum) {
					max = sum;
					max_left = left;
					max_right = right;
				}
			}
		}
		cout << "#" << t << " "<< max_left << " " << max_right << " " << max << "\n";
	}

}