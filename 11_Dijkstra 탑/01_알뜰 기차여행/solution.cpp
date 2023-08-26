#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
	int cost;
	int to;
	bool operator<(Edge right) const {
		// 거리가 짧은 것 우선
		if (cost < right.cost) return false; // 내 거리가 더 짧으면 내걸 먼저
		if (cost > right.cost) return true;

		return false;
	}
};

int cntNode, cntEdge;
vector<Edge> v[20001];
int dist[300001];


void dijkstra_3(int st) {
	for (int i = 0; i < cntNode; i++)
		dist[i] = 1e9;
	priority_queue<Edge> pq; // 2. queue생성 => priority queue생성
	pq.push({ 0, st }); // 3. 시작점 세팅
	dist[st] = 0;

	// 7. pq가 비워질때까지
	while (!pq.empty()) {
		Edge nowEdge = pq.top(); pq.pop(); // 4. now꺼내기
		int now = nowEdge.to;
		int nowCost = nowEdge.cost;
		if (dist[now] < nowCost)
			continue;

		// 5. now->next를 찾기
		for (int i = 0; i < v[now].size(); i++) {
			Edge nextEdge = v[now][i];
			int next = v[now][i].to;
			int nextCost = v[now][i].cost;

			if (dist[next] <= dist[now] + nextCost)
				continue;

			// 6. next를 pq에 추가
			dist[next] = dist[now] + nextCost;
			pq.push({ dist[next], next });
		}
	}

	if (dist[cntNode - 1] == 1e9) {
		cout << "impossible";
	}
	else {

		cout << dist[cntNode-1];
	}

}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> cntNode >> cntEdge;
	for (int i = 0; i < cntEdge; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ cost, to });
	} // 1. 그래프 구성
	dijkstra_3(0);
}