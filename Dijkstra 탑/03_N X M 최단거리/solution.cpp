#include <iostream>
#include <queue>
#include <vector>	
#include <climits>
using namespace std;

int N, M;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };
int dist[101][101] = { 0 };
struct Edge {
	int Y;
	int X;
	int Cost;
};
bool operator<(Edge left, Edge right) {
	if (left.Cost > right.Cost)	return true;
	if (left.Cost < right.Cost)	return false;

	return false;
}
priority_queue<Edge> pq;

void dijkstra() {
	pq.push({1,1, map[1][1]});
	dist[1][1] = map[1][1];
	while (!pq.empty()) {
		Edge now = pq.top();
		int nowY = now.Y;
		int nowX = now.X;
		int cost = now.Cost;
		pq.pop();

		if (visited[nowY][nowX] == 1) {
			continue;
		}
		visited[nowY][nowX] = 1;

		int dy[] = { 0,0,-1,1 };
		int dx[] = { -1,1,0,0 };
		for (int i = 0; i < 4; i++) {

			int y = nowY + dy[i];
			int x = nowX + dx[i];

			if (x<1 || y<1 || y>N || x>M) {
				continue;
			}
			if (dist[y][x] < dist[nowY][nowX] + cost) {
				continue;
			}
			dist[y][x] = dist[nowY][nowX] + map[y][x];
			pq.push({ y,x, dist[y][x] });
		}
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			dist[i][j] = INT_MAX;
		}
	}

	dijkstra();
	cout << dist[N][M] << endl;

	return 0;
}