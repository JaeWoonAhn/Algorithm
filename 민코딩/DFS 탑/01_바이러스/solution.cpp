#include <iostream>
#include <vector>

using namespace std;

vector<int> dfs[101];
int visited[101];
int cnt = 0;
void DFS(int now) {
	for (int i = 0; i < dfs[now].size(); i++) {
		int next = dfs[now][i];

		if (visited[next] == 1) {
			continue;
		}

		visited[next] = 1;
		cnt++;
		DFS(next);
	}


}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int node;
	int edge;

	cin >> node >> edge;

	for (int i = 0; i < edge; i++) {
		int from, to;
		cin >> from >> to;

		dfs[from].push_back(to);
		dfs[to].push_back(from);
	}
	DFS(1);

	cout << cnt-1;
}