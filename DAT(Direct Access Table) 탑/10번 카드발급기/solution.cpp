#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int _i = 0; _i < T; _i++) {
		int N;
		cin >> N;

		// init
		vector<pair<int, int>> inputs;
		for (int i = 0; i < N; i++) {
			int height;
			cin >> height;
			inputs.push_back({ height, 0 });
		}
		for (int i = 0; i < N; i++) {
			int card_num;
			cin >> card_num;
			inputs[i].second = card_num;
		}

		// sort
		sort(inputs.begin(), inputs.end(), [](const auto& a, const auto& b) {
			if (a.first == b.first) {
				return a.second > b.second;
			}
			return a.first < b.first;
			});

		int cnt = N;
		for (int i = 0; i < N; i++) {
			if (inputs[i].second == cnt) {
				cnt--;
				if (cnt == 0) {
					cout << "YES" << endl;
					break;
				}
				continue;
			}
			else {
				cout << "NO" << endl;
				break;
			}
		}

	}
	return 0;
}