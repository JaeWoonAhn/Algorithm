#include <iostream>
#include <vector>
#include <queue>
using namespace std;


priority_queue<int> small;
priority_queue<int, vector<int>, greater<int>> big;
int main() {
	int temp = 500;

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		
		if ((a <= temp && b >= temp) || (a >= temp && b <= temp)) {
			// 하나는 크고, 하나는 작을 때
			if (a <= temp) {
				small.push(a);
				big.push(b);
			}
			else {
				big.push(a);
				small.push(b);
			}
			cout << temp << "\n";
		}
		else if (a <= temp && b <= temp) {
			small.push(a);
			small.push(b);

			big.push(temp);

			temp = small.top();
			cout << temp << "\n";
			small.pop();
		}
		else if (a >= temp && b >= temp) {
			big.push(a);
			big.push(b);

			small.push(temp);

			temp = big.top();
			cout << temp << "\n";
			big.pop();
		}
	}

}