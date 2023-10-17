/*
*/

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N;
char MAP[101][101];
char MAP1[101][101];
char visited[101][101];
char visited1[101][101];
queue<pair<int, int>> q;
queue<pair<int, int>> q1;

void init() {

	cin >> N;
	memset(visited, 48, sizeof(visited));
	memset(visited1, 48, sizeof(visited1));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> MAP[y][x];

			if (MAP[y][x] == 'G') {
				MAP1[y][x] = 'R';
			}
			else {
				MAP1[y][x] = MAP[y][x];
			}
		}
	}
}

void bfs1(int y, int x) {
	// 적록 색약

	pair<int, int> Now;
	Now.first = y;
	Now.second = x;
	q1.push(Now);

	pair<int, int> Next;

	while (!q1.empty()) {
		Now = q1.front();
		q1.pop();

		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int y = Now.first + dy[i];
			int x = Now.second + dx[i];

			if (y < 0 || x < 0 || x >= N || y >= N) {
				continue;
			}
			if (MAP1[y][x] != MAP1[Now.first][Now.second]) {
				continue;
			}
			if (visited1[y][x] != '0') {
				continue;
			}
			visited1[y][x] = '1';

			Next.first = y;
			Next.second = x;
			q1.push(Next);
		}
	}
}

void bfs(int y, int x) {

	pair<int, int> Now;
	Now.first = y;
	Now.second = x;
	q.push(Now);

	pair<int, int> Next;

	while (!q.empty()) {
		Now = q.front();
		q.pop();

		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int y = Now.first + dy[i];
			int x = Now.second + dx[i];

			if (y < 0 || x < 0 || x >= N || y >= N) {
				continue;
			}
			if (MAP[y][x] != MAP[Now.first][Now.second]) {
				continue;
			}
			if (visited[y][x] != '0') {
				continue;
			}
			visited[y][x] = '1';

			Next.first = y;
			Next.second = x;
			q.push(Next);
		}
	}
}

int main() {

	pair<int, int> Now;
	pair<int, int> Next;

	int cnt = 0;
	int cnt1 = 0;

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	init();
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] == '0') {
				visited[y][x] = '1';
				bfs(y, x);
				cnt++;
			}
			else {
				continue;
			}
		}
	}
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited1[y][x] == '0') {
				visited1[y][x] = '1';
				bfs1(y, x);
				cnt1++;
			}
			else {
				continue;
			}
		}
	}

	cout << cnt << " " << cnt1 << endl;

	return 0;
}