#include <iostream>
#include <vector>
using namespace std;

int visited[13] = { 0, };
int map[13][13] = { 0, };
int N;	
int MIN = 1e9;
vector<int> path;
int last = 0;

void DFS(int level, int now) {
	int next;
	if (level == N) {
		// underlying conditions
		if (map[now][1] == 0) {
			return;
		}
		else {
			last += map[now][1];
		}
		if (MIN > last -1) {
			MIN = last - 1;
		}
		return;
	} 

	for (int i = 1; i <= N; i++) {
		next = i;
		if (map[now][next] == 0) {
			continue;
		}
		if (visited[next] >= 1) {
			continue;
		}
	
		visited[next] = visited[now] + map[now][next];
		last = visited[next];
		
		if (last - 1 > MIN) {
			visited[next] = 0;
			continue;
		}
		path.push_back(next);
		DFS(level + 1, next);
		visited[next] = 0;
		path.pop_back();
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	visited[1] = 1;
	path.push_back(1);
	DFS(1,1);
	cout << MIN;
}