#include <iostream>

using namespace std;

int arr[65536] = { 0, };
int brr[3][4] = {
{65000, 35, 42, 70},
{70, 35, 65000, 1300},
{65000, 30000, 38, 42}
};

int main(){

	int size_arr = sizeof(arr) / sizeof(arr[0]);

	int size_brr = sizeof(brr) / sizeof(brr[0]);
	int size2_brr = sizeof(brr[0]) / sizeof(brr[0][0]);

	for (int i = 0; i < size_brr; i++) {
       	for (int j = 0; j < size2_brr; j++) {
			arr[brr[i][j]]++;
		}
	}

	int max = 0;
	int idx = 0;
	for (int i = 0; i < size_arr; i++) {
		if (arr[i] > max) {
			max = arr[i];
			idx = i;
		}
	}

	cout << idx << endl;
	
    return 0;
}