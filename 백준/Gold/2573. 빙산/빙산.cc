#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define border 301
int N, M;
int Map[border][border];
int Visited[border][border];
struct Edge {
	int y;
	int x;
};
vector<Edge> V;
int Max = 0;

void init() {
	cin >> N >> M;
	memset(Map, 0, sizeof(Map));
	memset(Visited, 0, sizeof(Map));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> Map[y][x];
			Edge now = { y,x};
			if (Map[y][x] >= 1) {
				V.push_back(now);
			}
		}
	}
}
int Cnt = 0;
int Flag = 0;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

void bfs(Edge now, int map[border][border]) {
	int cpMap[border][border];	// copy Map
	memcpy(cpMap, Map, sizeof(Map));
	// 호출 시 now 기준으로 한 바퀴 돌림
	if (Visited[now.y][now.x] == 1) {
		return;
	}
	if (map[now.y][now.x] == 0) {
		return;
	}
	Visited[now.y][now.x] = 1;
	int cnt1 = 0;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + now.y;
		int nx = dx[i] + now.x;

		if (map[ny][nx] == 0) {
			cnt1++;
		}
	}
	cpMap[now.y][now.x] -= cnt1;
	if (cpMap[now.y][now.x] < 0) {
		cpMap[now.y][now.x] = 0;
	}

	queue<Edge> q;
	q.push(now);
	while (!q.empty()) {
		Edge now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + now.y;
			int nx = dx[i] + now.x;

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
				continue;
			}
			if (Visited[ny][nx] == 1) {
				continue;
			}
			if (map[ny][nx] == 0) {
				continue;
			}
			Visited[ny][nx] = 1;

			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				int nny = dy[j] + ny;
				int nnx = dx[j] + nx;
				if (nny < 0 || nnx < 0 || nny >= N || nnx >= M) {
					continue;
				}
				if (map[nny][nnx] == 0) {
					cnt++;
				}
			}
			cpMap[ny][nx] = Map[ny][nx] - cnt;
			if (cpMap[ny][nx] < 0) {
				cpMap[ny][nx] = 0;
			}

			Edge next = { ny,nx };
			q.push(next);

		}
	}
	
	// map update
	memcpy(Map, cpMap, sizeof(Map));
}

int solution() {

	int time = 0;
	while (1) {
		// end condition
		if (V.size() <= 1) {
			return 0;
		}

		
		int cnt = 0;
		time++;
		for (int i = 0; i < V.size(); i++) {
			Edge now = V[i];
			if (Map[now.y][now.x] == 0) {
				V.erase(V.begin() + i);
				i--;
				continue;
			}
			if (Visited[now.y][now.x] == 1) {
				continue;
			}
			cnt++;
			if (cnt >= 2) {
				return time-1; 
			}
			bfs(now, Map);
		}
		// Visited 초기화
		memset(Visited, 0, sizeof(Visited));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cnt = 0;
	int time = 0;
	init();
	cout << solution() << endl;

	
	return 0;
}