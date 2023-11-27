#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int len;
string str;
float bsearch() {
	if (str[0] == '_') {
		return 0;
	}
	if (str[len-1] == '#') {
		return len;
	}
	int s = 0;
	int e = len;

	while (s <= e) {
		int mid = (s + e) / 2;
		int sel = str[mid];

		if (sel == '_') {
			//lower
			e = mid - 1;
		}
		else {
			//upper
			s = mid + 1;
		}
	}
	return s;
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		// #의 개수와 str.length()를 이용해서 퍼센트 출력
		cin >> str;
		len = str.length();
		float res = float(bsearch() / len);
		int result = res * 100;
		cout << result << "%\n";
	}
}