#include <iostream>
using namespace std;

int recursive(int num) {
	// underlying conditions
	if (num == 1)	return 1;
	if (num == 2)	return 2;
	if (num > 2) {
		return num * recursive(num - 1);
	}

}

int main() {
	int N;
	cin >> N;
	
	cout << recursive(N);
}