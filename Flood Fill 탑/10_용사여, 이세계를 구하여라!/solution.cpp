#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Node {
	int y, x;
};
int T;
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int N, M;
		cin >> N >> M;

		char map[10][10] = { '0' };
		char map1[10][10] = { '0' };
		int visited[10][10] = { 0 };
		int visited1[10][10] = { 0 };
		Node Sstart, Tstart;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				map1[i][j] = map[i][j];
				if (map[i][j] == 'S') {
					Sstart.y = i;
					Sstart.x = j;
				}
				if (map[i][j] == 'T') {
					Tstart.y = i;
					Tstart.x = j;
				}

			}
		}
		int HP;
		cin >> HP;

		queue<Node> q;
		int cntS = INT_MAX;
		int cntT = INT_MAX;
		int flagY;
		int flagM;

		// 여기서 부터 반복

		// S start
		flagY = 0;
		flagM = 0;
		q.push({ Sstart.y,Sstart.x });
		visited[Sstart.y][Sstart.x] = 1;

		while (!q.empty()) {
			Node now = q.front();
			q.pop();

			int dy[] = { 0,0,1,-1 };
			int dx[] = { 1,-1,0,0 };
			for (int i = 0; i < 4; i++) {
				int y = now.y + dy[i];
				int x = now.x + dx[i];

				if (y < 0 || x < 0 || x >= M || y >= N) {
					// 경계를 넘어가면 패스
					continue;
				}
				if (map[y][x] == 'x') {
					// 막힌길이니까 패스
					continue;
				}
				if (visited[y][x] >= 1) {
					// 왔던 길이면 패스
					continue;
				}
				if (map[y][x] == 'Y') {
					// 용사 발견!
					flagY = visited[now.y][now.x];
				}
				if (map[y][x] == 'M') {
					// 마왕 발견!
					flagM = visited[now.y][now.x];

				}
				q.push({ y,x });
				visited[y][x] = visited[now.y][now.x] + 1;
			}

		}
		if (flagM * flagY != 0) {
			if (HP % 5 >= 1) {
				cntS = HP / 5 + 1;
			}
			else {
				cntS = HP / 5;
			}
			cntS = cntS + flagM + flagY;
		}


		// T start
		flagY = 0;
		flagM = 0;
		q.push({ Tstart.y,Tstart.x });
		visited1[Tstart.y][Tstart.x] = 1;

		while (!q.empty()) {
			Node now = q.front();
			q.pop();

			int dy[] = { 0,0,1,-1 };
			int dx[] = { 1,-1,0,0 };
			for (int i = 0; i < 4; i++) {
				int y = now.y + dy[i];
				int x = now.x + dx[i];

				if (y < 0 || x < 0 || x >= M || y >= N) {
					// 경계를 넘어가면 패스
					continue;
				}
				if (map[y][x] == 'x') {
					// 막힌길이니까 패스
					continue;
				}
				if (visited1[y][x] >= 1) {
					// 왔던 길이면 패스
					continue;
				}
				if (map[y][x] == 'Y') {
					// 용사 발견!
					flagY = visited1[now.y][now.x];
				}
				if (map[y][x] == 'M') {
					// 마왕 발견!
					flagM = visited1[now.y][now.x];

				}
				q.push({ y,x });
				visited1[y][x] = visited1[now.y][now.x] + 1;
			}

		}
		if (flagM * flagY != 0) {
			if (HP % 2 == 1) {
				cntT = HP / 2 + 1;
			}
			else {
				cntT = HP / 2;
			}
			cntT = cntT + flagM + flagY;
		}

		// cntT ,cntS 확보 -> 비교 후 작은 값 출력

		//FIXME
		if (cntT == INT_MAX && cntS == INT_MAX) {
			cout << "#" <<i<< " the world is doomed" << endl;
		}
		else{
			if (cntT < cntS) {
				cout << "#" << i << " " << cntT << endl;
			}
			else {
				cout << "#" <<i<< " " << cntS << endl;
			}
		}

	}
}