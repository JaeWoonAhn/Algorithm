#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;
struct Node {
	int to;
	int cost;
};
bool operator<(Node left, Node right) {
	if (left.cost < right.cost)	return false;
	if (left.cost > right.cost)	return true;
	if (left.to < right.to)	return false;
	if (left.to > right.to)	return true;
	return false;

}
priority_queue<Node> pq;
vector<Node> v[1001];
int visited[1001] = { 0 };
int dist[1001];
int inc[11] = { 0 };
int N, M, K;
int A, B;
int k = 0;
int sum(int cnt) {
	int sum = 0;
	for (int i = 0; i <= k; i++) {
		sum += inc[i];
	}
	return sum;

}
void djikstra() {
	for (int i = 1; i <= N; i++) {
		dist[i] = INT_MAX;
	}
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
	pq.push({ A,0 });
	dist[A] = 0;

	while (!pq.empty()) {
		Node nowNode = pq.top();
		pq.pop();
		int now= nowNode.to;
		int nowCost = nowNode.cost;
 

		if (visited[now] == 1) {
			continue;
		}
		visited[now] = 1;
		for (int i = 0; i < v[now].size(); i++) {
			Node nextNode = v[now][i];
			int next = nextNode.to;
			int Cost = nextNode.cost + sum(k);

			if (dist[next] < dist[now] + Cost) {
				continue;
			}
			dist[next] = dist[now] + Cost;
			pq.push({ next, dist[next]});
		}
	}
	cout << dist[B] << endl;
	k++;
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> K;
	cin >> A >> B;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}

	djikstra();
	for (int i = 1; i <= K; i++) {
		int k;
		cin >> k;
		inc[i] = k;
		djikstra();
	}
}