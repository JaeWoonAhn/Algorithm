#include <iostream>
#include <queue>

using namespace std;

int N, M;
int** map;
int** visited;
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;

	map = new int* [N];
	visited = new int* [N];
	for (int y = 0; y < N; y++) {
		map[y] = new int[M] {0};
		visited[y] = new int[M] {0};
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}

	struct Node
	{
		int y, x;
	};
	queue<Node> q;
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 1 ) {
				// 섬이면서 방문하지 않은 땅
				q.push({ y,x });
				while (!q.empty()) {
					Node now = q.front();
					q.pop();

					int dy[] = { 0,0,1,-1 };
					int dx[] = { 1,-1,0,0 };

					for (int i = 0; i < 4; i++) {
						int next_y = now.y + dy[i];
						int next_x = now.x + dx[i];
						if (next_x < 0 || next_y < 0 || next_x >= M || next_y >=N) {
							continue;
						}
						if (map[next_y][next_x] == 0) {
							continue;
						}
						q.push({ next_y,next_x });
						map[next_y][next_x] = 0;
					}
				}
				cnt++;
			}
		}
	}
	cout << cnt;
}