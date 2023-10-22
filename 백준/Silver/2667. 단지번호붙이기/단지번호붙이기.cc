#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>	

using namespace std;

#define endl "\n"
#define BOARDER 26

int visited[BOARDER][BOARDER];
char MAP[BOARDER][BOARDER];
int N;
vector<int> res;
struct Edge {
	int y, x;
};
queue<Edge> q;

void init() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> MAP[y][x];
		}
	}
}

void bfs(int y, int x) {
	Edge Now;
	Now.y = y;
	Now.x = x;
	visited[y][x] = 1;
	q.push(Now);

	int cnt = 1;
	
	while (!q.empty()) {
		Now = q.front();
		q.pop();

		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int y = Now.y + dy[i];
			int x = Now.x + dx[i];

			if (y < 0 || x < 0 || x >= N || y >= N) {
				continue;
			}
			if (MAP[y][x] == '0') {
				continue;
			}
			MAP[y][x] = '0';
			if (visited[y][x] == 1) {
				continue;
			}
			visited[y][x] = 1;
			cnt++;

			Edge Next;
			Next.y = y;
			Next.x = x;

			q.push(Next);
		}
	}
	res.push_back(cnt);
}
int main() {

	int cnt = 0;
	init();
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (MAP[y][x] == '1') {
				bfs(y, x);
				cnt++;
			}
		}
	}
	sort(res.begin(), res.end());

	cout << cnt << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	
	return 0;
}