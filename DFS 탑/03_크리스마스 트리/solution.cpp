#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
vector<int> v[1001];
vector<int> v1[1001];
vector<int> temp;
int visited[1001] = { 0 };
int N;
int parent;

void pattern1(int now) {
	// underlying conditions
	if (temp.size() == 0) {
		return;
	}
	int next;
	int left = 0;
	int right = 1;
	int	next_right = v[now][right];
	int	next_left = v[now][left];
	temp.push_back(next_left);

	next = temp.back();

	if (next == -1) {
		cout << now << " ";
		temp.pop_back();	// 왼쪽의 -1 버리기
		temp.pop_back();	// now까지 빼기
		temp.push_back(next_right);	// 오른쪽 넣기
		next = temp.back();


		if (next == -1) {
			// 오른쪽까지 -1 일 경우는 부모 노드나오도록 pop_back()
			temp.pop_back();	// 오른쪽의 -1버리기
			if (temp.size() >= 1) {
				next = temp.back();	// now의 부모
			}
			else {
				return;
			}
			v[next][left] = -1;
		}
		pattern1(next);

	}
	else {
		pattern1(next);
	}
}

void pattern2(int now) {
	// 이진트리
	for (int i = 0; i < 2; i++) {
		int next = v1[now][i];

		if (next == -1) {
			continue;
		}
		if (visited[next] == 1) {
			continue;
		}

		visited[next] = 1;
		cout << next << " ";
		pattern2(next);
	}
}

void pattern3(int now) {
	// binary tree
	for (int i = 0; i < 2; i++) {
		int next = v1[now][i];

		if (next == -1) {
			continue;
		}
		if (visited[next] == 1) {
			continue;
		}

		visited[next] = 1;
		pattern3(next);
		cout << next << " ";

	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int node, left, right;
		cin >> node >> left >> right;

		v[node].push_back(left);
		v[node].push_back(right);
		v1[node].push_back(left);
		v1[node].push_back(right);
	}
	temp.push_back(1);
	pattern1(1);
	cout << endl;

	visited[1] = 1;
	cout << 1 << " ";
	pattern2(1);
	cout << endl;

	for (int i = 2; i < 1001; i++) {
		visited[i] = 0;
	}

	pattern3(1);
	cout << "1";
	cout << endl;
}