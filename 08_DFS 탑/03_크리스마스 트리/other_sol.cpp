#include <iostream>
#include <vector>
using namespace std;

int tree[1001][2]; 
int N;
vector<int>preorder;
vector<int>inorder;
vector<int>postorder; 

void dfs(int now) {

	if (now == -1)
		return;
	preorder.push_back(now);
	
	// 왼쪽으로 탐색 
	dfs(tree[now][0]);
	inorder.push_back(now);
	
	// 오른쪽으로 탐색
	dfs(tree[now][1]);
	postorder.push_back(now);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int root, left, right; 
		cin >> root >> left >> right;
		// root의 왼쪽 
		tree[root][0] = left;
		// root의 오른쪽
		tree[root][1] = right; 
	}

	dfs(1);

	for (auto it = inorder.begin(); it != inorder.end(); it++) 
		cout << *it << " ";
	cout << '\n';
	for (auto it = preorder.begin(); it != preorder.end(); it++)
		cout << *it << " ";
	cout << '\n';
	for (auto it = postorder.begin(); it != postorder.end(); it++)
		cout << *it << " ";
}