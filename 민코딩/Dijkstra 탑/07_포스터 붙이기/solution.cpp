#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
/*
문제
K에서 출발해서 A ,B를 거치는 최소 거리를 구하는 문제

아이디어
1. A를 중간으로 거친다고 가정하고 A출발 기준으로의 dist[K] + dist[B] 리턴
2. B를 중간으로 거친다고 가정하고 B출발 기준으로의 dist[K] + dist[A] 리턴
3. 두 리턴 값을 비교해서 작은 값 출력
3-1. 시간 초과로 백트래킹 추가!
*/
int C, P, K, A, B;
struct Edge {
	int to, cost;
};
bool operator<(Edge left, Edge right) {
	if (left.cost > right.cost)	return true;
	if (left.cost < right.cost)	return false;
	return false;
}
vector<Edge> v[100001];
priority_queue<Edge> pq;
int dist[100001];
void djikstra(int start) {
	for (int i = 1; i <= P; i++) {
		dist[i] = INT_MAX;
	}
	pq.push({ start,0 });
	dist[start] = 0;

	while (!pq.empty()) {
		Edge Now = pq.top();
		int now = Now.to;
		int distNow = Now.cost;
		pq.pop();
		if (distNow > dist[now]) {
			// 시간 초과로 인한 백트래킹
			continue;
		}
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].to;
			int cost = v[now][i].cost;

			if (dist[next] < dist[now] + cost) {
				continue;
			}
			dist[next] = dist[now] + cost;
			pq.push({ next, dist[next] });
		}
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> C >> P >> K >> A >> B;

	for (int i = 0; i < C; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}
	int resultA = 0;
	int resultB = 0;
	djikstra(A);
	resultA = dist[B] + dist[K];
	djikstra(B);
	resultB = dist[A] + dist[K];

	if (resultA >= resultB) {
		cout << resultB;
	}
	else {
		cout << resultA;
	}
}