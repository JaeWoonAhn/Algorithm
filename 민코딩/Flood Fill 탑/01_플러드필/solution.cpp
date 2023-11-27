#include <iostream>
#include <queue>

using namespace std;

int main() {
	int map[5][5] = { 0 };

	int Y, X;
	cin >> Y >> X;

	struct Node
	{
		int y, x;
	};
	queue<Node> q;

	q.push({ Y,X });
	map[Y][X] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1,0,0 };

		for (int i = 0; i < 4; i++) {
			int y = now.y + dy[i];
			int x = now.x + dx[i];

			if (x < 0 || y < 0 || x >= 5 || y >= 5) {
				continue;
			}
			if (map[y][x] >= 1) {
				continue;
			}
			q.push({ y,x });
			map[y][x] = map[now.y][now.x] + 1;
		}
	}

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			cout << map[y][x] << " ";
		}
		cout << endl;
	}
}
