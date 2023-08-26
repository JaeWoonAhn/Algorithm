#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[10001];
int bsearch() {
	int s = 1;
	int e = N;

	while (1) {
		int mid = (s + e) / 2;
		if (mid >= 10000) {
			mid = 10000;
		}
		int sel = arr[mid];
		long long tgt = sel * sel;
		long long tgt1 = arr[mid + 1] * arr[mid + 1];

		if (N >= tgt && N < tgt1) {
			return mid;
		}
		if (tgt > N) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
}

int main() {
	cin >> N;
	
	for (int i = 1; i < 10001; i++) {
		arr[i] = i;
	}
	cout << bsearch();
}