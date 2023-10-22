#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;	

struct Edge {
	int floor, cnt = 0;
};

int res;
int visited[1000001];
queue<Edge> q;
void init() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> F >> S >> G >> U >> D;

	Edge edge;
	edge.floor = S;

	q.push(edge);
	visited[S] = 1;
}

void bfs() {	
	res = -1;
	
	while (!q.empty()) {
		Edge Now = q.front();
		q.pop();

		if (Now.floor == G) {
			res = visited[Now.floor] - 1;
			return;
		}

		int dy[] = { U, -D };
		for (int i = 0; i < 2; i++) {
			int y = Now.floor + dy[i];

			if (y<1 || y>F) {
				continue;
			}
			if (visited[y] != 0) {
				continue;
			}
			visited[y] = visited[Now.floor] + 1;

			if (y == G) {
				res = visited[y] - 1;
				return;
			}
			Edge Next;
			Next.floor = y;

			q.push(Next);
		}
	}
}
int main() {

	init();
	bfs();

	if (res == -1) {
		cout << "use the stairs" << endl;
	}
	else {
		cout << res << endl;
	}

	
	return 0;
}