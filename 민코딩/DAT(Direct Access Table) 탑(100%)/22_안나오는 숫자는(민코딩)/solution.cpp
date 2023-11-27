#include <iostream>

using namespace std;

int main(){

	int brr[3][3];

	int arr[10] = { 0, };
	int size_arr = sizeof(arr) / sizeof(arr[0]);

	int size_brr = sizeof(brr) / sizeof(brr[0]);
	int size2_brr = sizeof(brr[0]) / sizeof(brr[0][0]);

	for (int i = 0; i < size_brr; i++) {
		for (int j = 0; j < size2_brr; j++) {
			cin >> brr[i][j];
			arr[brr[i][j]] = 1;
		}
	}

	for (int i = 1; i < size_arr; i++) {
		if (arr[i] == 0) {
			cout << i << " ";
		}
	}

}