#include <iostream>
#include <queue>
#include <string.h>

#define endl "\n"
#define boarder 51
using namespace std;

int N, M, C, R, L;
int MAP[boarder][boarder];
int visited[boarder][boarder];
struct Point {
	int y, x;
};

int pipedir[8][4] = {
	//상하좌우
	{0,0,0,0},
	{1,1,1,1},
	{1,1,0,0},
	{0,0,1,1},
	{1,0,0,1},
	{0,1,0,1},
	{0,1,1,0},
	{1,0,1,0}
};

void init() {
	memset(MAP, 0, sizeof(MAP));
	memset(visited, 0, sizeof(visited));

	cin >> N >> M >> R >> C >> L;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> MAP[y][x];
		}
	}
}

int bfs(int y, int x) {
	queue<Point> q;
	q.push({ y,x });

	int cnt = 0;
	visited[y][x] = 1;
	
	while (!q.empty()) {
		Point now = q.front();
		q.pop();

		if (visited[now.y][now.x] > L) {
			break;	
		}
		cnt++;

		int dy[] = { -1,1,0,0 };
		int dx[] = { 0,0,-1,1 };
		for (int i = 0; i < 4; i++) {
			int y = now.y + dy[i];
			int x = now.x + dx[i];

			if (y < 0 || x < 0 || y >= N || x >= M) {
				continue;
			}
			if (MAP[y][x] == 0) {
				continue;
			}
			if (visited[y][x] != 0) {
				continue;
			}
			int curpipe = MAP[now.y][now.x];
			if (pipedir[curpipe][i] == 0) {
				continue;
			}
			int nextpipe = MAP[y][x];
			int nextdir;
			if (i % 2 == 0) {
				nextdir = i + 1;
			}
			else {
				nextdir = i - 1;
			}

			if (pipedir[nextpipe][nextdir] == 0) {
				continue;
			}
			visited[y][x] = visited[now.y][now.x] + 1;

			q.push({ y,x });
		}
	}
	return cnt;
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		int ans = bfs(R, C);
		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}