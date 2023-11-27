#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int H, W;	// 장기판의 크기 3이상 100이하
int R, C;	// 장기판 내 붉은 상의 위치
int Y, X;	// 장기판 내 파란 차의 위치
int N;		// N개의 쫄 (입력 후 쫄의 위치 y,x순)

int visited[101][101] = { 0 };
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> H >> W >> R >> C >> Y >> X >> N;
	visited[R][C] = 1;
	visited[Y][X] = -1;

	struct Node {
		int y, x;
	};
	
	vector<Node> pawns;
	for (int i = 0; i < N; i++) {
		int y, x;
		cin >> y >> x;
		pawns.push_back({ y,x });
		visited[y][x] = 1;
	}

	queue<Node> q;
	q.push({ R,C });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		int dy[] = { 2,-2,2,-2,3,3,-3,-3 };
		int dx[] = { 3,3,-3,-3,2,-2,2,-2 };

		for (int i = 0; i < 8; i++) {
			int y = now.y + dy[i];
			int x = now.x + dx[i];

			if (y < 0 || x < 0 || y >= H || x >= W) {
				continue;
			}
			if (visited[y][x] == -1) {
				cout << visited[now.y][now.x];
				return 0;
			}
			else if (visited[y][x] >= 1) {
				continue;
			}
			q.push({ y,x });
			visited[y][x] = visited[now.y][now.x] + 1;
		}
	}
	cout << -1;

}