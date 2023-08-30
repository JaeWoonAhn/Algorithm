#include <iostream>
#include <string>

using namespace std;

int main(){

	char brr[15];
	string input;
	cin >> input;
	int arr[26] = { 0, };
	int size_arr = sizeof(arr) / sizeof(arr[0]);

	int size_brr = sizeof(brr) / sizeof(brr[0]);
	// int size2_brr = sizeof(brr[0]) / sizeof(brr[0][0]);

	for (int i = 0; i < input.length(); i++) {
		arr[int(input[i] - 'A')]++;
	}

	int max = 0;
	int idx = 0;
	int count = 0;
	for (int i = 0; i < size_arr; i++) {
		if (arr[i] > max) {
			max = arr[i];
			idx = i;
		}
	}

	cout << char(idx + 65) ;
}