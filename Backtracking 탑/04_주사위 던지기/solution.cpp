#include <iostream>
#include<cstdio>
using namespace std;

int target;
int range[6] = { 1,2,3,4,5,6 };
int cnt = 0;
int flag = 0;
int path[3];
int DAT[7];
int N;
int iter = 0;

void recursive1(int level) {
	if (level == N) {
		for (int i = 0; i < level; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < 6; i++) {
		path[level] = range[i];
		recursive1(level + 1);
		path[level] = 0;
	}
}

void recursive2(int level) {
	// 1. 재귀 기저 조건
	if (level == N) {
		for (int i = 0; i < level; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < 6; i++) {
		if (level >= 1) {
			if (range[i] < path[level - 1]) {
				continue;
			}
		}

		path[level] = range[i];
		recursive2(level + 1);
		path[level] = 0;
	}
}

void recursive3(int level) {
	if (level == N) {
		for (int i = 0; i < level; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < 6; i++) {
		// 1~6 주사위 굴리기
		if (DAT[range[i]] == 1) {
			// 이전에 나왔던 수면 다음 수로 pass
			continue;
		}
		DAT[range[i]] = 1;
		path[level] = range[i];
		// 다음 주사위를 굴려라
		recursive3(level + 1);
		// 복귀 조건
		DAT[range[i]] = 0;
		path[level] = 0;
	}
}

int main() {
	//freopen_s(new FILE*, "./input.txt", "r", stdin);
//	freopen_s(new FILE*, "./output.txt", "w", stdout);
	cin >> N;
	cin >> flag;

	if (flag == 1) {
		recursive1(0);
	}
	else if (flag == 2) {
		recursive2(0);
	}
	else if (flag == 3) {
		recursive3(0);
	}

}