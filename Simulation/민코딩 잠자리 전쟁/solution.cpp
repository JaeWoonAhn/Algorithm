#include <iostream>
#include <string.h>
using namespace std;

int N, M, T;	// 1~100 map size, T : dragon flies
int y[101], x[101], power[101], dist[101];
int MAP[102][102];
int curY[101], curX[101];

void init() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> y[i] >> x[i] >> power[i] >> dist[i];
		curY[i] = y[i];
		curX[i] = x[i];
	}
	// test done!
}

void move() {
	for (int i = 1; i <= T; i++) {
		if (dist[i] == 1) {
			power[i]++;
			continue;
		}
		// left top
		if (curY[i] == y[i] && curX[i] < x[i] + dist[i] - 1) {
			curX[i]++;
		}
		// right top
		else if (curX[i] == x[i] + dist[i] - 1 && curY[i] < y[i] + dist[i] - 1) {
			curY[i]++;
		}
		// bottom right
		else if (curY[i] == y[i] + dist[i] - 1 && curX[i] > x[i]) {
			curX[i]--;
		}
		// bottom left
		else if (curX[i] == x[i] && curY[i] > y[i]) {
			curY[i]--;
		}
		else {
			//out 된 녀석들
		//	cout << curY[i] << " " << curX[i];
			continue;
		}

		// FIXME
		//cout << i << ": " << curY[i] << " " << curX[i] << endl;
		if (curX[i] == x[i] && curY[i] == y[i]) {
			power[i]++;
			// FIXME
			//cout << i << "power : " << power[i] << endl;
		}

		// test 완료
	}
}

void battle(int idx1, int idx2) {
	if (power[idx1] == power[idx2]) {
		if (dist[idx1] == dist[idx2]) {
			curY[idx1] = 101;
			curX[idx1] = 101;
			curY[idx2] = 101;
			curX[idx2] = 101;
			power[idx1] = 0;
			power[idx2] = 0;
		}
		else if (dist[idx1] > dist[idx2]) {
			power[idx1] += power[idx2];
			curY[idx2] = 101;
			curX[idx2] = 101;
			power[idx2] = 0;
		}
		else {
			power[idx2] += power[idx1];
			curY[idx1] = 101;
			curX[idx1] = 101;
			power[idx1] = 0;
		}
	}
	else if (power[idx1] > power[idx2]) {
			power[idx1] += power[idx2];
			curY[idx2] = 101;
			curX[idx2] = 101;
			power[idx2] = 0;
	}
	else {
			power[idx2] += power[idx1];
			curY[idx1] = 101;
			curX[idx1] = 101;
			power[idx1] = 0;
	}
}

void findFighter() {
	for (int i = 1; i <= T; i++) {
		if (MAP[curY[i]][curX[i]] != 0) {
			battle(MAP[curY[i]][curX[i]], i);
		}
		else {
			MAP[curY[i]][curX[i]] = i;
		}
	}

	// init
	for (int i = 1; i <= 100; i++) {
		memset(MAP[i], 0, sizeof(int) * 100);
	}
}

int findStrongest() {
	int max_power = 0;
	for (int i = 1; i <= T; i++) {
		if (power[i] > max_power) {
			max_power = power[i];
		}
	}
	return max_power;
}
int main() {

	init();

	for (int time = 1; time <= 15; time++) {
		move();
		findFighter();
	}
	cout << findStrongest() << endl;

	return 0;
}