#include <iostream>

using namespace std;

int N;
int parent[26];
int team_member[26];
int Find(int idx) {
	if (parent[idx] == idx) 
		return idx;
	return parent[idx] = Find(parent[idx]);
}

void Union(int A, int B) {
	int rootA = Find(A);
	int rootB = Find(B);
	
	parent[rootB] = rootA;
	//if(team_member[rootA] == 0) {

	//	team_member[Find(rootA)] += team_member[rootB];
	//	team_member[rootB] = 0;
	//}
	//else {
	if (rootA != rootB) {
		team_member[rootA] += team_member[rootB];
		team_member[rootB] = 0;
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;

	// init
	for (int i = 0; i < 26; i++) {
		parent[i] = i;
		team_member[i] = 1;
	}

	// N orders
	for (int i = 0; i < N; i++) {
		char a, b;
		int fromA, fromB;
		cin >> a >> b;
		fromA = int(a - 'A');
		fromB = int(b - 'A');

		Union(fromA, fromB);
	}

	int num_team = 0;
	int num_solo = 0;
	for (int i = 0; i < 26; i++) {
		if (team_member[i] == 0) {
			continue;
		}
		else if(team_member[i] >= 2) {
			num_team++;
		}
		else {
			num_solo++;
		}
	}
	cout << num_team << "\n" << num_solo;

	return 0;
}