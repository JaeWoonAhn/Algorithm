#include <iostream>
#include <queue>
#include <string.h>	
using namespace std;
int L, R, C;	// level, y,x
char MAP[31][31][31];
int visited[31][31][31];
int res = 0;

#define endl "\n"
struct Edge {
	int z,y, x;
};
queue<Edge> q;
void init() {
	memset(visited, 0, sizeof(visited));
	memset(MAP, 46, sizeof(MAP));

	for (int i = 0; i < L; i++) {
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				cin >> MAP[i][y][x];

				if (MAP[i][y][x] == 'S') {
					Edge edge;
					edge.z = i;
					edge.y = y;
					edge.x = x;
					q.push(edge);
					visited[i][y][x] = 1;
				}
			}
		}
	}
}

void bfs() {
	res = 0;
	while (!q.empty()) {
		Edge Now = q.front();
		q.pop();

		int dz[] = { 1,-1,0,0,0,0 };
		int dy[] = { 0,0,1,-1,0,0};
		int dx[] = { 0,0,0,0,1,-1 };
		for (int i = 0; i < 6; i++) {
			int z = Now.z + dz[i];
			int y = Now.y + dy[i];
			int x = Now.x + dx[i];
			if (z < 0 || z >= L || y < 0 || y >= R || x < 0 || x >= C) {
				continue;
			}
			if (visited[z][y][x] != 0) {
				continue;
			}
			if (MAP[z][y][x] == '#') {
				continue;
			}
			visited[z][y][x] = visited[Now.z][Now.y][Now.x] + 1;

			
			if (MAP[z][y][x] == 'E') {
				res = visited[z][y][x] - 1;
				while (!q.empty()) {
					q.pop();
				}
				return;
			}
			
			Edge Next;
			Next.z = z;
			Next.y = y;
			Next.x = x;

			q.push(Next);

		}

	}
}
int main() {
	
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	while (1) {
		
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) {
			return 0;
		}
	
		init();
		bfs();
		if (res == 0) {
			cout << "Trapped!" << endl;
		}
		else {
			cout << "Escaped in " << res << " minute(s)." << endl;
		}



	}

	return 0;
}