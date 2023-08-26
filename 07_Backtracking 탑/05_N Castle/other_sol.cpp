#include <iostream>
using namespace std;

int N; 
int DAT[10]; 
int cnt = 0; 

void func(int row) {
	// 기저 조건 -> N-1번행까지 모두 castle을 각 행에 두었다면
	if (row == N) {
		cnt++; // 하나의 조합을 찾았다
		return; 
	}

	// 수행
	// 재귀 구성 -> 각 행에서는 N개의 열에 둘 수 있다. 
	for (int col = 0; col < N; col++) {
		// 가지치기 -> 만약 이미 이 열에 castle을 둔 적이 있다면, 안전하지 않은 배치이다.
		if (DAT[col] == 1)
			continue;
		DAT[col] = 1; //현재 행에서 col열에 castle을 하나 둔다.
		func(row + 1); // 현재 행에서 castle을 두었으니, 다음 행으로 이동한다.
		DAT[col] = 0; // 현재 행에서 두었던 castle을 해제
	}
}

int main() {

	// input 
	cin >> N;
	
	// solve
	func(0); // 0번 행에서 시작한다
	cout << cnt;
}