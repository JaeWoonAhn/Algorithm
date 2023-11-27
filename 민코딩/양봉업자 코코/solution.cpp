#include <iostream>	
#include <vector>
#include <string.h>	
#include <algorithm>

using namespace std;

#define border 50
#define endl "\n"

int Res;
int BeeHouse[border][border];

// 벌집 모양 6방향 탐색
int dy[] = { -2,2,-1,-1,1,1 };
int dx[] = { 0,0,-1,1,1 ,-1};

int N, M;
int visited[border][border];

// Y 모양에 대한 stamp -> 방향배열
int Ystamp[4][2] = {
	{0,0},
	{-1,-1},
	{-1,1},
	{2,0}
};

// ReverseY모양에 대한 stamp 
int ReverseYstamp[4][2] = {
	{0,0},
	{-2,0},
	{1,-1},
	{1,1}
};

void dfs(int y, int x, int cnt, int sum) {
	// underlying condition
	if (cnt == 4) {
		Res = max(sum, Res);
		return;
	}

	// Recursive construct
	for (int i = 0; i < 6; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		// backtracking
		if (ny < 0 || nx < 0 || ny >= N * 2 || nx >= M) {
			continue;
		}
		if (visited[ny][nx] == 1) {
			continue;
		}

		visited[ny][nx] = 1;
		dfs(ny, nx, cnt + 1, sum + BeeHouse[ny][nx]);
		visited[ny][nx] = 0;
	}
}

void stamp(int y, int x, int dirs[4][2]) {
	// 주어진 4개만 합쳐보면 된다.
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dirs[i][0];
		int nx = x + dirs[i][1];
		if (ny < 0 || nx < 0 || ny >= N * 2 || nx >= M) {
			return;
		}
		if (BeeHouse[ny][nx] == 0) {
			return;
		}
		sum += BeeHouse[ny][nx];
	}
	Res = max(sum, Res);
}

int main() {

//	freopen_s(new FILE*, "input.txt", "r", stdin);

	int tc;
	cin >> tc;
	for (int test = 1; test <= tc; test++) {
		//init
		memset(BeeHouse, 0, sizeof(BeeHouse));
		memset(visited, 0, sizeof(BeeHouse));
		Res = -21e8;

		// input
		cin >> N >> M;

		for (int i = 0; i < N * 2; i += 2) {
			for (int j = 0; j < M; j++) {
				int temp;
				cin >> temp;
				if (j % 2 == 0) {
					BeeHouse[i][j] = temp;
				}
				else {
					BeeHouse[i + 1][j] = temp;
				}
			}
		}


		for (int i = 0; i < N * 2; i++) {
			for (int j = 0; j < M; j++) {
				if (BeeHouse[i][j] > 0) {
					visited[i][j] = 1;
					dfs(i, j, 1, BeeHouse[i][j]);
					visited[i][j] = 0;

					stamp(i, j, Ystamp);
					stamp(i, j, ReverseYstamp);
				}
			}
		}
		cout << "#" << test << " " << Res << endl;
	}
}