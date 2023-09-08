#include <iostream>
#include <vector>
// 2개 조합까지만 재귀함수 돌리고, 그 조합마다
// 2개 조합은 중복처리 어떻게해?
using namespace std;

int DAT[100001] = { 0, };
int path[2];
int cnt = 0;
int N, K;
vector<int> arr;

void recursive(int level, int next) {
	if (level == 2) {
		int sum = 0;
		sum = path[0] + path[1];

		if (K-sum > 0 && K-sum <= 100000) {
			if (DAT[K - sum] == 1 ) {
				cnt++;
			//	cout <<cnt<<" : "<< path[0] << " " << path[1] << " : " << K - sum << endl;
			}
		}
		return;
	}

	for (int i = next; i < arr.size(); i++) {
		path[level] = arr[i];
		next = i + 1;
		DAT[arr[i]] = 0;

		recursive(level + 1, next);
		path[level] = 0;
		DAT[arr[i]] = 1;
	}
	if (next == arr.size() - 1) {
		return;
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 0; i < arr.size(); i++) {
		DAT[arr[i]] = 1;
	}

	recursive(0, 0);

	cout << cnt / 3;
}