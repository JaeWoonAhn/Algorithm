#include <iostream>

using namespace std;
int sum = 0;
void rec(int n) {
	if (n  == 1) {
		return;
	}
	
	sum++;
	if (n % 2 == 0) {
		rec(n / 2);
	}
	else {
		rec(3 * n + 1);
	}
}
int main() {
	int a;
	cin >> a;

	rec(a);
	
	cout << sum;
}