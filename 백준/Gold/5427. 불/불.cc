#include <iostream>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

#define endl "\n"
#define BORADER 1001

int w, h;	// 1~1000
char MAP[BORADER][BORADER];

struct Edge {
	int y, x;
	int dist = 213456789;
};
queue<Edge> qF;
queue<Edge> qP;
int res = -1;

void init() {
	memset(MAP, 0, sizeof(MAP));

	cin >> w >> h;

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			cin >> MAP[y][x];

			Edge edge;
			if (MAP[y][x] == '*') {
				edge.y = y;
				edge.x = x;
				qF.push(edge);
			}
			else if (MAP[y][x] == '@') {
				edge.y = y;
				edge.x = x;
				edge.dist = 0;
				qP.push(edge);
			}
		}
	}
}

void bfs() {
	queue<Edge> tmpQfire;
	queue<Edge> tmpQperson;

	res = -1;
	while (1) {
		while (!qP.empty()) {
			Edge edge = qP.front();
			qP.pop();
			tmpQperson.push(edge);
		}
		while (!tmpQperson.empty()) {
			Edge Now = tmpQperson.front();
			tmpQperson.pop();

			if (MAP[Now.y][Now.x] != '@') {
				continue;
			}
			int dy[] = { 0,0,1,-1 };
			int dx[] = { 1,-1,0,0 };

			for (int i = 0; i < 4; i++) {
				int y = Now.y + dy[i];
				int x = Now.x + dx[i];

				if (y < 0 || x < 0 || x >= w || y >= h) {
					res = Now.dist + 1;
					while (!qF.empty()) {
						qF.pop();
					}
					return;
				}
				if (MAP[y][x] != '.') {
					continue;
				}
				MAP[y][x] = '@';

				Edge Next;
				Next.y = y;
				Next.x = x;
				Next.dist = Now.dist + 1;

				qP.push(Next);
			}
		}
		if (qP.empty()) {
			res = -1;
			while (!qF.empty()) {
				qF.pop();
			}
			return;
		}

		while (!qF.empty()) {
			Edge edge = qF.front();
			qF.pop();
			tmpQfire.push(edge);
		}
		while (!tmpQfire.empty()) {
			Edge Now = tmpQfire.front();
			tmpQfire.pop();

			int dy[] = { 0,0,1,-1 };
			int dx[] = { 1,-1,0,0 };

			for (int i = 0; i < 4; i++) {
				int y = Now.y + dy[i];
				int x = Now.x + dx[i];

				if (y < 0 || x < 0 || x >= w || y >= h) {
					continue;
				}
				if (MAP[y][x] == '#') {
					continue;
				}
				if (MAP[y][x] == '*') {
					continue;
				}
				MAP[y][x] = '*';

				Edge Next;
				Next.y = y;
				Next.x = x;

				qF.push(Next);
			}
		}
	}
}

int main() {
	int test;
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> test;

	for (int tc = 1; tc <= test; tc++) {
		init();
		bfs();
		if (res == -1) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << res << endl;
		}
	}
	return 0;
}