#include <iostream>
#include <queue>

using namespace std;

int height, width;
int** map;
int Y1, X1, Y2, X2;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> height >> width;
	cin >> Y1 >> X1 >> Y2 >> X2;

	map = new int* [height];
	for (int y = 0; y < height; y++) {
		map[y] = new int[width] {0};
	}
	struct Node
	{
		int y, x;
	};
	queue<Node> q;
	q.push({ Y1,X1 });
	q.push({Y2,X2});

	map[Y1][X1] = 1;
	map[Y2][X2] = 1;
	int last = 0;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int y = now.y + dy[i];
			int x = now.x + dx[i];

			if (y < 0 || x < 0 || x >= width || y >= height) {
				continue;
			}
			if (map[y][x] >= 1) {
				continue;
			}
			q.push({ y,x });
			map[y][x] = map[now.y][now.x] + 1;
			last = map[y][x];
		}
	}
	cout << last;
}