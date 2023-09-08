#include <iostream>
#include <vector>

using namespace std;

int a[1000];
int b[1000];
int c[1000];
int d[1000];
int an;
int bn;
int cn;
int dn;
int DAT1_P[4000];	//
int DAT2_P[4000];	//
int DAT2_N[4000];
int DAT1_N[4000];

vector<int> v1;
vector<int> v2;
void input() {
	// input 4 briges size
	cin >> an;
	cin >> bn;
	cin >> cn;
	cin >> dn;

	// input each brige's value
	for (int i = 0; i < an; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < bn; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < cn; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < dn; i++) {
		cin >> d[i];
	}

	for (int i = 0; i < an; i++) {
		for (int j = 0; j < bn; j++) {
			int sum = a[i] + b[j];

			if (sum >= 0) {
				DAT1_P[sum] += 1;
			}
			else {
				DAT1_N[-sum] += 1;
			}
		}
	}

	for (int i = 0; i < cn; i++) {
		for (int j = 0; j < dn; j++) {
			int sum = c[i] + d[j];

			if (sum > 0) {
				DAT2_P[sum] += 1;
			}
			else {
				DAT2_N[-sum] += 1;
			}
		}
	}
}

int solution() {
	int cnt = 0;
	// 2 briges(a,b) vs 2 briges(c,d)
	//init

	for (int i = 0; i < 4000; i++) {
		if (DAT1_P[i] >= 1) {
			if (DAT2_N[i] >= 1) {
				cnt += DAT1_P[i] * DAT2_N[i];
			}
		}
	}
	for (int i = 0; i < 4000; i++) {
		if (DAT1_N[i] >= 1) {
			if (DAT2_P[i] >= 1) {
				cnt += DAT1_N[i] * DAT2_P[i];
			}
		}
	}
	return cnt;
}
int main() {
//	freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	cout << solution();

}