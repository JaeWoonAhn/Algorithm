#include <iostream>
#include <queue>
#include <string.h>

/*
Q. 토마토
- 토마토 한판(N*M)을 수직으로 쌓아서 창고 보관
- 토마토가 익으려면 익은 토마토의 영향을 받아야됌
- 익은 토마토는 상하좌우 위아래 6방향으로 익음
- 한칸에 토마토가 있을지도 없을지도
- 토마토가 다 익으려면 최소 몇일 걸리나??

1. 아이디어
1) 
*/


#define endl "\n"
#define Boarder 101
using namespace std;

int M, N, H;
int MAP[Boarder][Boarder][Boarder];
int visited[Boarder][Boarder][Boarder];
int MAX = 1;

int cnt;
struct Edge {
	int y, x, z;
	int dist = 1;
};

queue<Edge> NotRipenTomatoes;
queue<Edge> RipenTomatoes;
queue<Edge> tempQ;


void init() {
	cin >> M >> N >> H;

	for (int z = 0; z < H; z++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				cin >> MAP[z][x][y];

				if (MAP[z][x][y] == 0) {
					Edge edge;
					edge.y = y;
					edge.x = x;
					edge.z = z;

					NotRipenTomatoes.push(edge);
				}
				else if (MAP[z][x][y] == 1) {
					Edge edge;
					edge.y = y;
					edge.x = x;
					edge.z = z;

					RipenTomatoes.push(edge);
				}
			}
		}
	}
}

void transferQ() {
	while (!RipenTomatoes.empty()) {
		Edge edge;
		edge = RipenTomatoes.front();
		RipenTomatoes.pop();
		tempQ.push(edge);
	}
	cnt++;
}

void bfs() {

	transferQ();

	while(!tempQ.empty()){
		Edge Now = tempQ.front();

		if (visited[Now.z][Now.x][Now.y] == 0) {
			visited[Now.z][Now.x][Now.y] = cnt;
			break;
		}
		else if (visited[Now.z][Now.x][Now.y] >= cnt) {
			visited[Now.z][Now.x][Now.y] = cnt;
			break;
		}
		else {
			tempQ.pop();
		}
	}


	while (!tempQ.empty()) {
		Edge Now = tempQ.front();
		tempQ.pop();

		int dy[] = { 0,0,0,0,1,-1 };
		int dx[] = { 0,0,1,-1,0,0 };
		int dz[] = { 1,-1,0,0,0,0 };

		for (int i = 0; i < 6; i++) {
			int y = Now.y + dy[i];
			int x = Now.x + dx[i];
			int z = Now.z + dz[i];

			if (x < 0 || y < 0 || z < 0 || x >= N || y >= M || z >= H) {
				continue;
			}
			if (MAP[z][x][y] == -1 || MAP[z][x][y] == 1) {
				continue;
			}
			if (visited[z][x][y] != 0) {
				if (visited[z][x][y] <= cnt+1) {
					continue;
				}
			}

			visited[z][x][y] = cnt+1;
			
			if (visited[z][x][y] > MAX) {
				MAX = visited[z][x][y];
			}

			Edge Next;
			Next.y = y;
			Next.x = x;
			Next.z = z;

			RipenTomatoes.push(Next);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	init();
	while (!RipenTomatoes.empty()) {
		bfs();
	}
	while (!NotRipenTomatoes.empty()) {
		Edge edge = NotRipenTomatoes.front();
		NotRipenTomatoes.pop();
		if (visited[edge.z][edge.x][edge.y] == 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << MAX - 1 << endl;
	return 0;
	
}