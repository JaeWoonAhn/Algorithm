#include <iostream>
#include <cstring>
using namespace std;

int T;
int N, R;
int arr[1000001];
int DAT[201];		// FIXME201  init
int slide_window(int left,int right) {
	//init
	for (int init = left; init < N; init++) {
		DAT[arr[init]] += 1;
		if (DAT[arr[init]] >= 3) {
			return -1;
		}
	}

	// run slide window
	while (right < N-1) {
		DAT[arr[left]] -= 1;
		left++;
		if (left > N - 1) {
			left = 0;
		}

		right++;
		DAT[arr[right]] += 1;
		if (DAT[arr[right]] >= 3) {
			return -1;
		}
	}
	return 1;


}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> R;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		int left = N - 2*R -1;
		int right = -1;
		memset(DAT, 0, sizeof(DAT));
		if (slide_window(left, right) == -1) {
			cout << "#" << t << " NO\n";
		}
		else {
			cout << "#" << t << " YES\n";
		}
	}
}