#include <iostream>

using namespace std;

int dp[36];
int dfs(int target) {
	
	if (target == 0) {
		return dp[target] = 0;
	}
	else if(target==1) {
		return dp[target] = 1; 
	}
	else if ( dp[target] == 0) {
		return dp[target] = dfs(target - 2) + dfs(target - 1);
	}
	
}
int n;
int main() {
	cin >> n;
	dfs(n-1);
	cout << dp[n-1];
	return 0;
}