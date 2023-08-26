#include <iostream>

using namespace std;
int sum = 0;
void rec(int n) {
	if (n / 10 == 0) {
		sum += n % 10;
		return;
	}
	rec(n / 10);
	sum += n % 10;
}
int main() {
	int a;
	cin >> a;

	rec(a);
	
	cout << sum;
}