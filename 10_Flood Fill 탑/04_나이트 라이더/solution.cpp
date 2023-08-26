#include <iostream>
#include <queue>

using namespace std;

int Height, Width;
int stY, stX, endY, endX;
int visited[101][101];
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> Height >> Width >> stY >> stX >> endY >> endX;

	visited[stY][stX] = 1;
	visited[endY][endX] = -1;

	struct Node
	{
		int y, x;
	};

	queue<Node> q;
	q.push({ stY, stX });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		int dy[] = { 1,-1,1,-1,2,-2,2,-2 };
		int dx[] = { 2,2,-2,-2,1,1,-1,-1 };
		for (int i = 0; i < 8; i++) {
			int y = now.y + dy[i];
			int x = now.x + dx[i];

			if (x < 0 || y < 0 || x >= Width || y >= Height) {
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


}