#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
/*
문제 :단방향 엣지들을 주어지고 왔다 돌아가는 경우가 가장 큰 경우를 찾는 경우였다

아이디어
1. P마을을 기준으로 다익스트라 시작!
1-1. 돌아가는 기준 가장 큰 거리를 알 수 있다.

2. 단방향 엣지를 반대로 입력한 v_reverse를 통해서 가는 것 기준 다익스트라를 쓸 수 있다.
2-1. P마을까지 가는 것 기준으로 다익스트라 시작!
2-2. 2개의 다익스트라를 통해 얻은 dist_go, dist_come을 각각 더해 최대값 반환
*/
struct Edge {
	int to;
	int cost;
};
bool operator<(Edge left, Edge right) {
	if (left.cost > right.cost)	return true;
	if (left.cost < right.cost)	return false;

	return false;
}
int N, M, P;
vector<Edge> v[1001];
vector<Edge> v_reverse[1001];
priority_queue<Edge> pq;
int dist_go[1001] = { 0 };
int dist_come[1001] = { 0 };
int visited[1001] = { 0 };
int visited_reverse[1001] = { 0 };
void djikstra() {
	pq.push({ P, 0 });
	dist_go[P] = 0;

	while (!pq.empty()) {
		Edge nowEdge = pq.top();
		pq.pop();
		int now = nowEdge.to;

		if (visited[now] == 1) {
			continue;
		}
		visited[now] = 1;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].to;
			int nextCost = v[now][i].cost;

			if (dist_go[next] <= dist_go[now] + nextCost) {
				continue;
			}
			dist_go[next] = dist_go[now] + nextCost;
			pq.push({ next, dist_go[next] });
		}
	}
}
void djikstra_reverse() {
	pq.push({ P, 0 });
	dist_come[P] = 0;

	while (!pq.empty()) {
		Edge nowEdge = pq.top();
		pq.pop();
		int now = nowEdge.to;

		if (visited_reverse[now] == 1) {
			continue;
		}
		visited_reverse[now] = 1;
		for (int i = 0; i < v_reverse[now].size(); i++) {
			int next = v_reverse[now][i].to;
			int nextCost = v_reverse[now][i].cost;

			if (dist_come[next] <= dist_come[now] + nextCost) {
				continue;
			}
			dist_come[next] = dist_come[now] + nextCost;
			pq.push({ next, dist_come[next] });
		}
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> P;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v_reverse[to].push_back({ from, cost });
	}
	for (int i = 1; i <= N; i++) {
		dist_go[i] = INT_MAX;
		dist_come[i] = INT_MAX;
	}
	djikstra();
	djikstra_reverse();
	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < dist_go[i] + dist_come[i]) {
			max = dist_go[i] + dist_come[i];
		}
	}
	cout << max;
	return 0;
}