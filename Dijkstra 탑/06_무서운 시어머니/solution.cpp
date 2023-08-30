#include <iostream>
#include <queue>
#include <climits>
using namespace std;
int N;
int Y, X;
int map[1000][1000];
struct Node {
	int y, x, cost;
};
bool operator<(Node left, Node right) {
	if (left.cost > right.cost)	return true;
	if (left.cost < right.cost)	return false;
	return false;
}
priority_queue<Node> pq;
int dist[1000][1000];
int visited[1000][1000];
void djikstra() {
	pq.push({ Y,X,0});
	dist[Y][X] = map[Y][X];

	while (!pq.empty()) {
		Node Now = pq.top();
		pq.pop();

		if (visited[Now.y][Now.x] == 1) {
			continue;
		}
		visited[Now.y][Now.x] = 1;

		int dy[] = { 0,0,1, -1 };
		int dx[] = { 1, -1,0,0 };
		for (int i = 0; i < 4; i++) {
			int y = dy[i] + Now.y;
			int x = dx[i] + Now.x;

			if (y < 0 || x < 0 || x >= N || y >= N) {
				continue;
			}
			if (map[y][x] == -1) {
				continue;
			}
			if (dist[y][x] < dist[Now.y][Now.x] + map[y][x]) {
				continue;
			}
			dist[y][x] = dist[Now.y][Now.x] + map[y][x];
			pq.push({ y,x, dist[y][x]});
		}
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> Y >> X;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = INT_MAX;
		}
	}
	djikstra();
	
	int max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (max < dist[i][j]) {
				if (map[i][j] == -1) {
					continue;
				}
				max = dist[i][j];
			}
		}
	}
	cout << max;
}