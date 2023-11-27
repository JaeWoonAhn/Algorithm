#include <iostream>
#include <queue>

char map[201][201];
int N, M;

using namespace std;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int cntA = 0;
	int cntB = 0;
	int flagA = 0;
	int flagB = 0;
	int cnt = 0;
	int max = 0;

	struct Node {
		int y, x;
	};
	queue<Node> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cnt = 0;
			if (map[i][j] == 'A') {
				q.push({ i,j });
				cnt++;
				map[i][j] = '_';

				while (!q.empty()) {
					Node now = q.front();
					q.pop();

					int dy[] = { 0,0,1,-1 };
					int dx[] = { 1,-1,0,0 };
					for (int i = 0; i < 4; i++) {
						int y = now.y + dy[i];
						int x = now.x + dx[i];

						if (y < 0 || x < 0 || y >= N || x >= M) {
							continue;
						}
						if (map[y][x] != 'A') {
							continue;
						}
						q.push({ y,x });
						map[y][x] = '_';
						cnt++;
					}
				}
				cntA++;
				if (max < cnt) {
					max = cnt;
				}
			}
			cnt = 0;
			if (map[i][j] == 'B') {
				q.push({ i,j });
				cnt++;
				map[i][j] = '_';

				while (!q.empty()) {
					Node now = q.front();
					q.pop();

					int dy[] = { 0,0,1,-1 };
					int dx[] = { 1,-1,0,0 };
					for (int i = 0; i < 4; i++) {
						int y = now.y + dy[i];
						int x = now.x + dx[i];

						if (y < 0 || x < 0 || y >= N || x >= M) {
							continue;
						}
						if (map[y][x] != 'B') {
							continue;
						}
						q.push({ y,x });
						map[y][x] = '_';
						cnt++;
					}
				}
				cntB++;
				if (max < cnt) {
					max = cnt;
				}
			}
		}
	}
	cout << cntA << " " << cntB << endl;
	cout << max;
}