#include <iostream>
#include <queue>

using namespace std;

int N, M;
char** map;
int** visited;
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int sX, sY;
	int dX, dY;
	int cX, cY;

	cin >> N >> M;
	map = new char* [N];
	visited = new int* [N];
	for (int y = 0; y < N; y++) {
		map[y] = new char[M] {0};
		visited[y] = new int[M] {0};
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'S') {
				sY = y;
				sX = x;
			}
			if (map[y][x] == 'D') {
				dY = y;
				dX = x;
			}
			if (map[y][x] == 'C') {
				cY = y;
				cX = x;
			}
		}
	}

	struct Node
	{
		int y, x;
	};
	queue<Node> q;
	int distS = 0; 
	int distD = 0;
	q.push({ cY,cX });
	visited[cY][cX] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		
		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1,0,0 };

		for (int i = 0; i < 4; i++) {
			int y = now.y + dy[i];
			int x = now.x + dx[i];

			if (x < 0 || y < 0 || x >= M || y >= N) {
				continue;
			}
			if (map[y][x] == 'x') {
				continue;
			}
			if (visited[y][x] >= 1) {
				continue;
			}
			q.push({ y,x });
			visited[y][x] = visited[now.y][now.x] +1;

			if (y == dY && x == dX) {
				distD = visited[y][x] - 1;
			}
			if (y == sY && x == sX) {
				distS = visited[y][x] - 1;
			}
		}
	}
	cout << distD + distS;
}