#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

#define endl "\n"
#define border 1002
int N, M;
char MAP[border][border];
int visited_start[border][border];
int visited_end[border][border];
int visited[border][border];
int MIN_dist = 21e8;

struct Edge {
	int y, x;
};

queue<Edge> walls;
queue<Edge> q;

void init() {
//freopen_s(new FILE*, "input.txt", "r", stdin);
	memset(MAP, 0, sizeof(MAP));
	memset(visited_start, 0, sizeof(visited_start));
	memset(visited_end, 0, sizeof(visited_end));
	cin >> N >> M;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			cin >> MAP[y][x];

			if (MAP[y][x] == '1') {
				Edge edge;
				edge.y = y;
				edge.x = x;
				walls.push(edge);
			}
		}
	}
}

void bfs_end(Edge edge) {
	visited_end[edge.y][edge.x] = 1;
	while (!q.empty()) {
		Edge Now = q.front();
		q.pop();

		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int y = Now.y + dy[i];
			int x = Now.x + dx[i];

			if (y<1 || x<1 || y>N || x>M) {
				continue;
			}
			if (visited_end[y][x] != 0) {
				continue;
			}
			visited_end[y][x] = visited_end[Now.y][Now.x] + 1;
			if (MAP[y][x] == '1') {
				continue;
			}

			Edge Next;
			Next.y = y;
			Next.x = x;

			q.push(Next);
		}
	}
}

void bfs_first(Edge edge) {
	visited_start[edge.y][edge.x] = 1;
	while (!q.empty()) {
		Edge Now = q.front();
		q.pop();

		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int y = Now.y + dy[i];
			int x = Now.x + dx[i];

			if (y<1 || x<1 || y>N || x>M) {
				continue;
			}
			if (visited_start[y][x] != 0) {
				continue;
			}
			visited_start[y][x] = visited_start[Now.y][Now.x] + 1;
			if (MAP[y][x] == '1') {
				continue;
			}

			Edge Next;
			Next.y = y;
			Next.x = x;

			q.push(Next);
		}
	}
}

void bfs() {
	
	q.push({ 1,1 });
	visited[1][1] = 1;
	while (!q.empty()) {
		Edge Now = q.front();
		q.pop();

		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int y = Now.y + dy[i];
			int x = Now.x + dx[i];

			if (y<1 || x<1 || y>N || x>M) {
				continue;
			}
			if (MAP[y][x] == '1') {
				continue;
			}
			if (visited[y][x] != 0) {
				continue;
			}

			visited[y][x] = visited[Now.y][Now.x] + 1;

			Edge Next;
			Next.y = y;
			Next.x = x;

			q.push(Next);
		}
	}
}

int main() {

	init();
	Edge first;
	first.y = 1;
	first.x = 1;
	q.push(first);
	bfs_first(first);

	Edge end;
	end.y = N;
	end.x = M;
	q.push(end);
	bfs_end(end);


	bfs();

	if (visited[N][M] != 0) {
		MIN_dist = visited[N][M];
	}
	while (!walls.empty()) {
		Edge Now = walls.front();
		walls.pop();

		int distFromStart = visited_start[Now.y][Now.x];
		int distFromEnd = visited_end[Now.y][Now.x];
		if (distFromEnd == 0 || distFromStart == 0) {
			continue;
		}
		if (MIN_dist > distFromEnd + distFromStart -1) {
			MIN_dist = distFromEnd + distFromStart - 1;
		}
	}
	if (MIN_dist == 21e8) {
		cout << -1 << endl;
	}
	else {
		cout << MIN_dist << endl;
	}

	return 0;
}