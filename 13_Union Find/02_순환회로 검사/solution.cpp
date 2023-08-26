#include <iostream>


using namespace std;
int N;
int map[1000][1000];
int parent[1000];
bool flag = true;
int Find(int idx) {
	if (idx == parent[idx]) {
		return idx;
	}
	int root = Find(parent[idx]);
	return root;
}

void Union(int A, int B) {
	int rootA = Find(A);
	int rootB = Find(B);

	if (rootA == rootB) {
		flag = false;
	}
	else {
		parent[rootB] = rootA;
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			flag = true;
			if (map[i][j] == 1) {
				map[j][i] = 0;
				Union(i, j);
				if (flag == false) {
					cout << "WARNING";
					return 0;
				}
			}
		}
	}
	cout << "STABLE";
	return 0;
}