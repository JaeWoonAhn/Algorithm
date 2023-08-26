#include <iostream>
#include <queue>

using namespace std;

int Width, Height;
int visited[10][10];
char map[10][10];
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> Width >> Height;

	int cnt_zom = 0;
	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			cin >> map[y][x];
			if (map[y][x] == '1') {
				cnt_zom++;
			}
		}
	}


	int X, Y;
	cin >> X >> Y;


	struct Node {
		int y, x;
	};
	queue<Node> q;
	q.push({ Y-1,X-1 });
	visited[Y-1][X-1] = 1;
	int cnt =1;
	int last = 0;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		if (last < visited[now.y][now.x]) {
			last = visited[now.y][now.x];
		}
		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int y = now.y + dy[i];
			int x = now.x + dx[i];

			if (y < 0 || x < 0 || x >= Width || y >= Height) {
				continue;
			}
			if (map[y][x] == '0') {
				continue;
			}
			if (visited[y][x] >= 1) {
				continue;
			}
			cnt++;
			q.push({ y,x });
			visited[y][x] = visited[now.y][now.x] + 1;
			last = visited[y][x];
		}
	}

	cout << last+2 << endl;
	cout << cnt_zom - cnt<< endl;

}