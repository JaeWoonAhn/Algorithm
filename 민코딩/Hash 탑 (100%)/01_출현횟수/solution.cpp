#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	unordered_map<int, int> um;

	for (int i = 0; i < N; i++) {
		int key;
		cin >> key;

		if (um.find(key) != um.end()) {
			um[key]++;
		}
		else {
			um.insert({ key, 1 });
		}
	}

	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		auto it = um.find(tmp);
		if (it != um.end()) {
			cout << (*it).second << " ";
		}
		else {
			cout << 0 << " ";
		}
	}

}