#include <iostream>
#include <string>

using namespace std;

int main(){

	char brr[5][3] = {
	{'A', 'B', 'C'},
	{'A', 'G', 'H'},
	{'H', 'I', 'J'},
	{'K', 'A', 'B'},
	{'A', 'B', 'C'}
	};
	int arr[26] = { 0, };
	int size_arr = sizeof(arr) / sizeof(arr[0]);

	int size_brr = sizeof(brr) / sizeof(brr[0]);
	int size2_brr = sizeof(brr[0]) / sizeof(brr[0][0]);

	for (int i = 0; i < size_brr; i++) {
		for (int j = 0; j < size2_brr; j++) {
			arr[brr[i][j] - 'A']++;
		}
	}

	int max = 0;
	int idx = 0;
	int count = 0;
	for (int i = 0; i < size_arr; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << char(i + 65);
		}
	}
}