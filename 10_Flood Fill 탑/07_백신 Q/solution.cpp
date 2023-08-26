#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[151][151] = { 0, };
int N, M;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
	struct Node {
		int y, x;
	};
	queue<Node> q;
	int Q = 0;
	int flag = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			flag = 0;
			if (map[i][j] >= 1) {
				q.push({ i,j });
				if (map[i][j] == 2) {
					flag = 1;
				}
				map[i][j] = 0;

				while (!q.empty()) {
					Node now = q.front();
					q.pop();

					int dy[] = { 0,0,-1,1 };
					int dx[] = { -1,1,0,0 };
					for (int i = 0; i < 4; i++) {
						int y = now.y + dy[i];
						int x = now.x + dx[i];

						if (y < 0 || x < 0 || y >= N || x >= M) {
							continue;
						}
						if (map[y][x] == 0) {
							continue;
						}
						if (map[y][x] == 2) {
							flag = 1;
						}
						q.push({ y,x });
						map[y][x] = 0;
					}
				}
				if (flag == 1) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}