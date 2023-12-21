#include <bits/stdc++.h>

using namespace std;

#define border 100001
#define endl "\n"
int N;
int X;
int Arr[border];
vector<int> V;

int Cnt = 0;
void init() {
	cin >> N;

	//for (int i = 0; i < N; i++) {
	//	cin >> Arr[i];
	//}
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		V.push_back(tmp);
	}

	cin >> X;
	sort(V.begin(), V.end());
}

void solution() {
	int startIdx = 0;
	int endIdx = N - 1;

	while (startIdx < endIdx) {
		int target = V[startIdx] + V[endIdx];
		if (target > X) {
			endIdx--;
		}
		else if(target<X){
			startIdx++;
		}
		else {
			Cnt++;
			startIdx++;
			endIdx--;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	solution();
	cout << Cnt << endl;

	return 0;
}