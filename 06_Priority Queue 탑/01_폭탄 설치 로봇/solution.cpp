#include <iostream>	
#include <queue>

using namespace std;
struct Node {
	int id;
	int y, x;
	bool operator<(Node right) const {
		// id가 낮은 것 우선
		if (id < right.id)	return false;	// 작으면 왼쪽먼저
		if (id > right.id)	return true;

		return false;

	}
};
priority_queue<Node> pq;

int visited[1000][1000] = { 0 };
int N, M;

int explode() {

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		if (visited[now.y][now.x] == -1) {
			// 이미 터져있어서 고장난거면 다음 폭탄 확인
			continue;
		}
		else {
			// 터지면 상하좌우로 -1 visited에 넣어주기

			int dy[] = { 0,0,0,1,-1 };
			int dx[] = { 1,-1,0,0,0 };

			for (int i = 0; i < 5; i++) {
				int y = now.y + dy[i];
				int x = now.x + dx[i];

				if (x < 0 || y < 0 || x >= 1000 || y >= 1000) {
					continue;
				}
				visited[y][x] = -1;
			}
			return now.id;
		}
	}
	return -1;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M;


	for (int i = 0; i < N + M; i++) {
		int a;
		cin >> a;
		if (a != 0) {
			int A, B;
			cin >> A >> B;
			pq.push({a,A,B});
		}
		else {
			// 0 이 나와서 폭탄을 터뜨려야하는 경우
			cout << explode() << endl;
		}
	}
}