#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> v1;
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N; 
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		v.push_back(temp);
	}



	while (v.size()>=3) {
		sort(v.begin(), v.end());
		int temp_sum = v[0] + v[1];
		v.erase(v.begin());
		v.erase(v.begin());
		v.insert(v.begin(), temp_sum);
		v1.push_back(temp_sum);
	}
	int sum = v[0] + v[1];
	for (int i = 0; i < v1.size(); i++) {
		sum += v1[i];
	}
	cout << sum;
}