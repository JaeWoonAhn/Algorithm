#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int height, width;
int map[1000][1000];
int N;
int target[100001];

struct Coordi {
	int y, x;
};
unordered_map<int, vector<Coordi>> um;
void input() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> height >> width;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> map[y][x];
			int key = map[y][x];

			um[key].push_back({y, x});
		}
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> target[i];
	}
}

void solution() {
	// target[i]에 있는 값이 어디어디에 있는지 i별로 출력하고 없는건 none출력
	for (int i = 0; i < N; i++) {
		int tgt = target[i];
		
		auto find_tgt = um.find(tgt);
		if (find_tgt != um.end()) {
			// exist
			for (int j = 0; j < um[tgt].size(); j++) {
				cout << "(" << um[tgt][j].y << "," << um[tgt][j].x << ") ";
			}
		}
		else {
			cout << "none";
		}
		cout << "\n";

	}
}
int main() {
	input();

	solution();

	return 0;
}