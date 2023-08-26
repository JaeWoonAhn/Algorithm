#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dfs[101];
int visited[101];
int cnt = 0;
void postorder(int now) {
	for (int i = 0; i < dfs[now].size(); i++) {
		int next = dfs[now][i];

		if (visited[next] == 1) {
			continue;
		}

		visited[next] = 1;
		postorder(next);
		cout << next << " ";
	}
}
void preorder(int now) {
	for (int i = 0; i < dfs[now].size(); i++) {
		int next = dfs[now][i];

		if (visited[next] == 1) {
			continue;
		}

		visited[next] = 1;
		cout << next << " ";
		preorder(next);
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int node;
	int edge;

	int start;

	cin >> node >> edge >> start;

	for (int i = 0; i < edge; i++) {
		int from, to;
		cin >> from >> to;

		dfs[from].push_back(to);
	}

	for (int i = 1; i < node+1; i++) {
		sort( dfs[i].begin(),dfs[i].end(), greater<int>());
	}
	visited[start] = 1;
	cout << start << " ";
	preorder(start);
	for (int i = 1; i <= node; i++) {
		visited[i] = 0;
	}
	visited[start] = 1;
	cout << endl;
	postorder(start);
	cout << start << " ";

}