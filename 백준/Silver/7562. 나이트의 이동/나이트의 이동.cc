#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"
#define Boarder 101

/*
Q. there is a Knight on Chessboard
How many time move a Knight from start to target coordinate?

1. Idea
use BFS
int dy = {2,2,1,1,-1,-1,-2,-2};
int dx = {1,-1,2,-2,2,-2,1,-1};
instead of
int dy = {0,0,1,-1};
int dx = {1,-1,0,0};

2. Time Complexity

3. Space Complexity


*/
int I;	// 4~300 chessboard size == I*I
int start_y, start_x;
int final_y, final_x;

int visited[301][301];
int res;

struct Edge {
	int y, x;
};
queue<Edge> q;

void init() {
	cin >> I;
	cin >> start_y >> start_x;
	cin >> final_y >> final_x;

	Edge start;
	start.y = start_y;
	start.x = start_x;
	if (start.y == final_y && start.x == final_x) {
		cout << 0 << endl;
	}

	else {
		q.push(start);
	}

	memset(visited, 0, sizeof(visited));
}

void bfs() {

	if (!q.empty()) {
		Edge Start = q.front();
		visited[Start.y][Start.x] = 1;
	}

	while (!q.empty()) {
		Edge Now = q.front();
		q.pop();

		int dy[] = {2,2,1,1,-1,-1,-2,-2};
		int dx[] = {1,-1,2,-2,2,-2,1,-1};

		for (int i = 0; i < 8; i++) {
			int y = Now.y + dy[i];
			int x = Now.x + dx[i];

			if (y < 0 || x < 0 || y >= I || x >= I) {
				continue;
			}
			if (visited[y][x] != 0) {
				continue;
			}
			visited[y][x] = visited[Now.y][Now.x] + 1;

			if (y == final_y && x == final_x) {
				res = visited[y][x]-1;
				cout << res << endl;
				while (!q.empty()) {
					q.pop();
				}
				return;
			}

			Edge Next;
			Next.y = y;
			Next.x = x;

			q.push(Next);
		}
	}
}

int main() {

	int T;
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		bfs();
	}
	return 0;
}