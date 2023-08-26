#include <iostream>
#include <vector>
using namespace std;

int visited[10001];
int map[10001][10001];
int N;
int start, finish;
int MAX = 0;
int MIN = 1e9;
int weight = 0;
vector<int> path;
void DFS(int now) {
	int next;
	// underlying conditions
	path.push_back(now);
	if (now == finish) {
		if (weight > MAX) {
			MAX = weight;
		}
		if (weight < MIN) {
			MIN = weight;
		}
		//DFS(start);
	}
	for (int i = 0; i < N; i++) {
		next = i;

		if (visited[next] >= 1) {
			continue;
		}
		if (map[now][i] == 0) {
			continue;
		}
		visited[next] = visited[now] + map[now][i];
		weight = visited[next] - 1;
		DFS(next);

		visited[next] = 0;
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	cin >> start >> finish;

	visited[start] = 1;
	DFS(start);

	cout << MIN << "\n" << MAX;
}