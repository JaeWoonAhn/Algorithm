#include <iostream>
#include <queue>
#include <vector>
#include <climits>;	
using namespace std;

/*
Mission Objective
바로 가는 경우 vs 동료 태워서 가는 경우
둘의 경우가 같은 경우면 cout << "OKAY", 동료 때매 늦어지는 경우는 cout << "SORRY"

아이디어
1. 바로가는 경우 (1 -> N : 집에서 회사까지 바로)
2. 동료가 있는 기준으로 다익스트라로 구한 거리로 바로가는 경우와 비교
    (동료의 집 -> 1 : 내 출발지, 동료의 집 -> N : 회사까지)

3. 1번의 경우 2번의 경우 비교 후 값 리턴
*/

struct Edge
{
	int to;
	int cost;
};
bool operator<(Edge left, Edge right) {
	if (left.cost > right.cost)	return true;
	if (left.cost < right.cost)	return false;
	return false;
}

vector<Edge> v[5001];
priority_queue<Edge> pq;
int dist_straight[5001];
int dist_via[5001];
int visited_straight[5001];
int visited_via[5001];
int V, E, P;
void djikstra() {
	pq.push({ 1,0 });
	dist_straight[1] = 0;

	while (!pq.empty()) {
		Edge nowEdge = pq.top();
		pq.pop();

		int now = nowEdge.to;
		if (visited_straight[now] == 1) {
			continue;
		}
		visited_straight[now] = 1;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].to;
			int cost = v[now][i].cost;

			if (dist_straight[next] < dist_straight[now] + cost) {
				continue;
			}
			dist_straight[next] = dist_straight[now] + cost;
			pq.push({ next, dist_straight[next] });
		}
	}
}

void djikstra_via() {
	pq.push({ P,0 });
	dist_via[P] = 0;

	while (!pq.empty()) {
		Edge nowEdge = pq.top();
		pq.pop();

		int now = nowEdge.to;
		if (visited_via[now] == 1) {
			continue;
		}
		visited_via[now] = 1;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].to;
			int cost = v[now][i].cost;

			if (dist_via[next] < dist_via[now] + cost) {
				continue;
			}
			dist_via[next] = dist_via[now] + cost;
			pq.push({ next, dist_via[next] });
		}
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> V >> E >> P;

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}
	for (int i = 1; i <= V; i++) {
		dist_straight[i] = INT_MAX;
		dist_via[i] = INT_MAX;
	}
	djikstra();
	djikstra_via();

	if (dist_straight[V] == (dist_via[1] + dist_via[V])) {
		cout << "OKAY";
	}
	else {
		cout << "SORRY";
	}
}