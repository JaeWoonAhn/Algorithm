#include <iostream>
#include <queue>

using namespace std;

int M, N;		// width, length
int MAP[1001][1001];
int visited[1001][1001];

struct Edge {
	int y, x;
};
queue<Edge> q;

void init() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> M >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> MAP[y][x];
			if (MAP[y][x] == 1) {
				Edge push;
				push.y = y;
				push.x = x;
				q.push(push);
				visited[push.y][push.x] = 1;
			}
		}
	}
}

void bfs() {

	while (!q.empty()) {
		Edge Now = q.front();
		q.pop();

		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1, 0,0 };
		for (int i = 0; i < 4; i++) {
			int y = Now.y + dy[i];
			int x = Now.x + dx[i];

			if (y < 0 || x < 0 || y >= N || x >= M) {
				continue;
			}
			if (visited[y][x] != 0) {
				continue;
			}
			if (MAP[y][x] == -1) {
				continue;
			}
			visited[y][x] = visited[Now.y][Now.x] + 1;
			MAP[y][x] = 1;

			Edge Next;
			Next.y = y;
			Next.x = x;

			q.push(Next);
		}
	}
}

int isRipened() {
	int max = 0;


	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (MAP[y][x] == 0) {
				return -1;
			}
			if (visited[y][x] > max) {
				max = visited[y][x];
			}
		}
	}
	return max - 1;
}

int main() {
	init();
	bfs();
	cout << isRipened() << endl;
	return 0;
}