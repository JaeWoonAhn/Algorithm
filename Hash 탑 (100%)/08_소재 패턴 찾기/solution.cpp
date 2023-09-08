#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	int y, x;
};

unordered_map<string, vector<Node>> um;
char bigMap[1100][1100];
char target[22][22];
int h, w;
int n;

void input() {
	cin >> h >> w;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			cin >> bigMap[y][x];
		}
	}

	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> target[y][x];
		}
	}
}

string getKey(int dy, int dx) {
	string key;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			key += bigMap[dy + y][dx + x];
		}
	}
	return key;
}

void init() {

	for (int y = 0; y <= h - n; y++) { 
		for (int x = 0; x <= w - n; x++) { //1000 ^2 반복

			
			string key = getKey(y, x); //9회
			um[key].push_back({ y, x });

		}
	}

}

bool isRealSame(int dy, int dx) {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (bigMap[dy + y][dx + x] != target[y][x]) return false;
		}
	}
	return true;
}

int main()
{	
	//freopen("input.txt", "r", stdin);
	input();

	//Hash 등록
	init(); 

	//search 하기 위해 target Key 만듦
	//400회 반복
	string key;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			key += target[y][x];
		}
	}

	//um[key]는 정답 후보들이 있음
	for (auto i : um[key]) {
		if (isRealSame(i.y, i.x)) {
			cout << i.y << "," << i.x << "\n";
		}
	}

	return 0;
}