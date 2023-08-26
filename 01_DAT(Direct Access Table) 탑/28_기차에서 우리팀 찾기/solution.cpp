#include <iostream>
#include <string>

using namespace std;

int main(){

	int brr[] = { 3, 7, 6, 4, 2, 9, 1, 7 };
	int arr[11][11][11] = {0,};
	int size_arr = sizeof(arr) / sizeof(arr[0]);

	int size_brr = sizeof(brr) / sizeof(brr[0]);
	//int size2_brr = sizeof(brr[0]) / sizeof(brr[0][0]);

	int a, b, c;
	cin >> a >> b >> c;

	for (int i = 1; i < size_brr - 1; i++) {
		arr[brr[i - 1]][brr[i]][brr[i + 1]]++;
		if (arr[a][b][c] == 1) {
			cout << i-1 << "번~"<<i+1<<"번 칸" << endl;
			break;
		}
	}
}