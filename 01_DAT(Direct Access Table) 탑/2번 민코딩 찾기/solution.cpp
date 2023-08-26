#include <iostream>
#include <string>

using namespace std;

int main(){

	int arr[256] = { 0, };
	char brr[9] = {'M','I','N','C','O','D','I','N','G'};
	
	int size_brr = sizeof(brr) / sizeof(brr[0]);
	//int size2_brr = sizeof(brr[0]) / sizeof(brr[0][0]);

	int size_arr = sizeof(arr) / sizeof(arr[0]);

	int a;
	char c;
	cin >> a;


	for (int i = 0; i < size_brr; i++) {
			arr[brr[i]]++;
	}

	for (int i = 0; i < a; i++) {
		cin >> c;
		if (arr[c] >= 1) {
			cout << 'O';
		}
		else {
			cout << 'X';
		}
	}
	int max = 0;
	int idx = 0;
	for (int i = 0; i < size_arr ; i++) {
		if (arr[i] == 2) {
		}
	}
}