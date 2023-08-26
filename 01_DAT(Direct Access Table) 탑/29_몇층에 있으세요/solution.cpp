#include <iostream>
#include <string>

using namespace std;

int brr[5][3] = {
{15, 18, 17},
{4, 6, 9},
{10, 1, 3},
{7, 8, 9},
{15, 2, 6}
};

	int size_brr = sizeof(brr) / sizeof(brr[0]);
	int a, b, c;
int isPattern(int x) {
	
	int arr[18][18][18] = {0,};
	int size_arr = sizeof(arr) / sizeof(arr[0]);

	arr[brr[x][0]][brr[x][1]][brr[x][2]]++;
	if(arr[a][b][c] == 1){
		return 1;
	}
	return 0;


}
int main(){


	//int size2_brr = sizeof(brr[0]) / sizeof(brr[0][0]);

	cin >> a >> b >> c;

	for (int i = 0; i < size_brr ; i++) {
		if (isPattern(i) == 1) {
			cout << 5-i << "층";
			break;
		}
	}
}