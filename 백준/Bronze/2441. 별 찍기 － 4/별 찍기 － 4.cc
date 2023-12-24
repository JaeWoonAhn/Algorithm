#include <iostream>

using namespace std;

void solution() {

}
int main() {

	int n; 
	cin >> n;
	int cnt = 0;

	while (n >= 0) {
		for (int i = 0; i < cnt; i++) {
			cout << " ";
		}
		for (int i = 0; i < n; i++) {
			cout << "*";
		}
		cout << endl;

		cnt++;
		n--;
	}


	
}