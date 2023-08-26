#include <iostream>

using namespace std;

int N, Q;
int K, A, B;
int parent[1001];

int Find(int idx) {
	if (parent[idx] == idx) {
		return idx;
	}
	return parent[idx] = Find(parent[idx]);
}

void Union(int A, int B) {
	int rootA = Find(A);
	int rootB = Find(B);

	if (rootA == rootB) {
		return;
	}
	else {
		parent[rootB] = rootA;
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < Q; i++) {
		cin >> K >> A >> B;
		if (K == 0) {
			if (Find(A) == Find(B)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else if (K == 1) {
			Union(A, B);
		}
	}


}