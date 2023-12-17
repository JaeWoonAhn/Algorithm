#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define endl "\n"
#define border 50
int N;

vector<int> vA;
vector<int> vB;
int Min = 21e8;
int DAT[border];
int Sum = 0;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		vA.push_back(input);
	}
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		vB.push_back(input);
	}

	sort(vA.begin(), vA.end());
	sort(vB.begin(), vB.end(), greater<int>());
}

int solution() {
	int sum = 0;
	for (int i = 0; i < vB.size(); i++) {
		sum += vA[i] * vB[i];
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	

	cout << solution() << endl;
	return 0;
}