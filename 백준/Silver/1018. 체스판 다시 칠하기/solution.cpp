#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int N, M;
char map[50][50];
int visited[50][50];
int visited1[50][50];
vector<int> res;
int main() {

	freopen_s(new FILE*, "input.txt", "r", stdin);
	// 1. init
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	// 2. 4개의 꼭지점에서 brute force
	int mini = 21e8;
	// 2-1. (0,0) 꼭지점
	for (int y = 0; y <= N - 8; y++) {
		for (int x = 0; x <= M - 8; x++) {

			memset(visited, 0, sizeof(visited));
			memset(visited1, 0, sizeof(visited1));
			int cnt = 0;
			int cnt1 = 1;

			int X, Y;

			X = x;
			Y = y;

			// is in map?
			if (x + 8 > M || y + 8 > N) {
				continue;
			}

			// first line init
			int setLine = 1;
			int setLine1 = 2;
			visited[y][x] = setLine;
			visited1[y][x] = setLine1;
			for (int line = x + 1; line < x + 8; line++) {
				if (map[y][line - 1] == map[y][line]) {
					setLine++;
					setLine1++;
				}
				else {
					setLine += 2;
					setLine1 += 2;
				}
				if (setLine % 2 == 0) {
					cnt++;
				}
				if (setLine1 % 2 == 0) {
					cnt1++;
				}

				visited[y][line] = setLine;
				visited1[y][line] = setLine1;
			}

			for (X = x; X < x + 8; X++) {
				int cntUp = visited[y][X];
				int cntUp1 = visited1[y][X];

				for (Y = y + 1; Y < y + 8; Y++) {
					if (map[Y - 1][X] == map[Y][X]) {
						cntUp++;
						cntUp1++;
					}
					else {
						cntUp += 2;
						cntUp1 += 2;
					}
					visited[Y][X] = cntUp;
					visited1[Y][X] = cntUp1;
					if (cntUp1 % 2 == 0) {
						//even
						cnt1++;
						// backtracking
						if (cnt1 >= mini) {
							continue;
						}
					}
					if (cntUp % 2 == 0) {
						//even
						cnt++;
						// backtracking
						if (cnt >= mini) {
							continue;
						}
					}
				}
			}
			int MIN = min(cnt, cnt1);

			//res.push_back(cnt); 1
			mini = min(mini, MIN);
		}
	}
	// 2-2. (M,0) 꼭지점
	for (int y = 0; y <= N - 8; y++) {
		for (int x = M - 1; x >= M - 8; x--) {

			memset(visited, 0, sizeof(visited));
			memset(visited1, 0, sizeof(visited1));
			int cnt = 0;
			int cnt1 = 1;

			int X, Y;

			X = x;
			Y = y;

			// is in map?
			if (x-7<0 || y + 8 > N) {
				continue;
			}

			// first line init
			int setLine = 1;
			int setLine1 = 2;
			visited[y][x] = setLine;
			visited1[y][x] = setLine1;
			for (int line = x - 1; line > x - 9; line--) {
				if (map[y][line + 1] == map[y][line]) {
					setLine++;
					setLine1++;
				}
				else {
					setLine += 2;
					setLine1 += 2;
				}
				if (setLine % 2 == 0) {
					cnt++;
				}
				if (setLine1 % 2 == 0) {
					cnt1++;
				}

				visited[y][line] = setLine;
				visited1[y][line] = setLine1;
			}

			for (X = x; X > x - 8; X--) {
				int cntUp = visited[y][X];
				int cntUp1 = visited1[y][X];

				for (Y = y + 1; Y < y + 8; Y++) {
					if (map[Y - 1][X] == map[Y][X]) {
						cntUp++;
						cntUp1++;
					}
					else {
						cntUp += 2;
						cntUp1 += 2;
					}
					visited[Y][X] = cntUp;
					visited1[Y][X] = cntUp;
					if (cntUp % 2 == 0) {
						//even
						cnt++;
						// backtracking
						if (cnt >= mini) {
							continue;
						}
					}
					if (cntUp1 % 2 == 0) {
						//even
						cnt1++;
						// backtracking
						if (cnt1 >= mini) {
							continue;
						}
					}
				}
			}

			int MIN = min(cnt1, cnt);
			//res.push_back(cnt); 2
			mini = min(mini, MIN);
		}
	}
	// 2-3. (M,N) 꼭지점
	for (int y = N - 1; y >= N - 8; y--) {
		for (int x = M - 1; x >= M - 8; x--) {

			memset(visited, 0, sizeof(visited));
			memset(visited1, 0, sizeof(visited1));
			int cnt = 0;
			int cnt1 = 1;

			int X, Y;

			X = x;
			Y = y;

			// is in map?
			if (x-7 < 0 || y-7 < 0) {
				continue;
			}

			// first line init
			int setLine = 1;
			int setLine1 = 2;
			visited[y][x] = setLine;
			visited1[y][x] = setLine1;
			for (int line = x - 1; line > x - 8; line--) {
				if (map[y][line + 1] == map[y][line]) {
					setLine++;
					setLine1++;
				}
				else {
					setLine += 2;
					setLine1 += 2;
				}
				if (setLine % 2 == 0) {
					cnt++;
				}
				if (setLine1 % 2 == 0) {
					cnt1++;
				}
				visited[y][line] = setLine;
				visited1[y][line] = setLine1;
			}

			for (X = x; X > x - 8; X--) {
				int cntUp = visited[y][X];
				int cntUp1 = visited1[y][X];

				for (Y = y - 1; Y > y - 8; Y--) {
					if (map[Y + 1][X] == map[Y][X]) {
						cntUp++;
						cntUp1++;
					}
					else {
						cntUp += 2;
						cntUp1 += 2;
					}
					visited[Y][X] = cntUp;
					visited1[Y][X] = cntUp1;
					if (cntUp % 2 == 0) {
						//even
						cnt++;
						// backtracking
						if (cnt >= mini) {
							continue;
						}
					}
					if (cntUp1 % 2 == 0) {
						//even
						cnt1++;
						// backtracking
						if (cnt1 >= mini) {
							continue;
						}
					}
				}
			}

			int MIN = min(cnt1, cnt);
			//res.push_back(cnt); 3
			mini = min(mini, MIN);
		}
	}

	// 2-4. (0,N) 꼭지점
	for (int y = N - 1; y >= N - 8; y--) {
		for (int x = 0; x <= M - 8; x++) {
			memset(visited, 0, sizeof(visited));
			memset(visited1, 0, sizeof(visited1));
			int cnt = 0;
			int cnt1 = 1;
			int X, Y;

			X = x;
			Y = y;

			// is in map? 4
			if (x+8 > M || y-7 < 0) {
				continue;
			}

			// first line init
			int setLine = 1;
			int setLine1 = 2;
			visited[y][x] = setLine;
			visited1[y][x] = setLine1;
			for (int line = x + 1; line < x + 8; line++) {
				if (map[y][line - 1] == map[y][line]) {
					setLine++;
					setLine1++;
				}
				else {
					setLine += 2;
					setLine1 += 2;
				}

				if (setLine1 % 2 == 0) {
					cnt1++;
				}
				if (setLine % 2 == 0) {
					cnt++;
				}
				visited[y][line] = setLine;
				visited1[y][line] = setLine1;
			}

			for (X = x; X < x + 8; X++) {
				int cntUp = visited[y][X];
				int cntUp1 = visited1[y][X];

				for (Y = y - 1; Y > y - 8; Y--) {
					if (map[Y + 1][X] == map[Y][X]) {
						cntUp++;
						cntUp1++;
					}
					else {
						cntUp += 2;
						cntUp1 += 2;
					}
					visited[Y][X] = cntUp;
					visited1[Y][X] = cntUp1;
					if (cntUp1 % 2 == 0) {
						//even
						cnt1++;
						// backtracking
						if (cnt1 >= mini) {
							continue;
						}
					}
					if (cntUp % 2 == 0) {
						//even
						cnt++;
						// backtracking
						if (cnt >= mini) {
							continue;
						}
					}
				}
			}

			int MIN = min(cnt, cnt1);
			//res.push_back(cnt); 4
			mini = min(mini, MIN);
		}
	}
	cout << mini << endl;



	return 0;
}