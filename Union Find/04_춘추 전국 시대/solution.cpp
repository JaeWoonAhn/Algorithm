#include <iostream>
#include <string>	
using namespace std;

int N;
int population[25];
int parent[25];
int T;
string order;
char N1, N2;

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
	if (population[rootA] == -1 || population[rootB] == -1) {
		return;
	}
	parent[rootB] = rootA;
	population[rootA] +=population[rootB];
	population[rootB] = 0;
}
int war(int A, int B) {

	int rootA = Find(A);
	int rootB = Find(B);
	int flag = 0;
	int cnt = 0;
	if (population[rootA] == -1 || population[rootB] == -1) {
		return 0;
	}
	if (population[rootA] == population[rootB]) {
		population[rootA] = -1;
		population[rootB] = -1;
		return 0;
	}
	else if (population[rootA] > population[rootB]) {
		flag = rootB;
		population[flag] = -1;	// 전멸
	}
	else {
		flag = rootA;
		population[flag] = -1;	// 전멸
	}

	for (int i = 0; i < N; i++) {
		if (parent[i] == flag) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> population[i];
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> order >> N1 >> N2;
		int a, b;
		a = int(N1 - 'A');
		b = int(N2 - 'A');

		if (order == "alliance") {
			// Union
			Union(a, b);
		}
		else {
			// war
			sum += war(a, b);
		}
	}
	cout << N - sum;
	return 0;
}
