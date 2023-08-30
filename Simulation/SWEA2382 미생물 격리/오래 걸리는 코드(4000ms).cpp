#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
/*
Q. SWEA 2382 미생물 격리
N*N(5<= N <= 100) 정사각형 구역안에 K(5<= K <= 1,000)개의 미생물 군집이 있다.

설명.
init()
- 각 미생물 군집의 위치, 군집 내 미생물의 수(1<= 미생물 수 <= 10,000), 이동 방향이 주어진다.

고려할 사항
- 각 군집들은 1시간마다 이동방향에 있는 다음 셀로 이동한다.
	@ 군집의 이동방향은 상하좌우 중 한 방향만 가진다.
		(상:1 , 하:2, 좌:3, 우:4)

	@ 만약 군집이 이동하다가 N*N의 가장 자리로 가게되면
		1) 군집 내 미생물의 절반이 죽는다. ( /2 후 소수점 이하 버림)
		2) 이동방향이 반대로 바뀐다.

	@ 이동 후 두 개 이상의 군집이 한 셀에 모이는 경우 군집이 합쳐진다.
		1) 합쳐 진 군집의 미생물 수는 군집들의 미생물 수의 합
		2) 군집들 중 미생물 수가 가장 많은 군집의 방향이 이동방향이 된다.

	@ 최초에 둘 이상의 군집이 동일한 셀에 배치되는 경우는 없다.
	@ 최조에 가장자리 부분에는 군집이 배치되지 않는다.


목표.
- M(1<= M <= 1,000)시간 후 남아 있는 미생물 수의 총합을 구하라.
*/

/*
idea. 최대한 효율적으로 해보자!
- unordered_map으로 군집을 관리할 수 있지 않을까?
- 군집 이동을 다 하고 나서 점검해봐야하나?
	- 군집개수로 loop 후 이동 -> DAT로 map에 1,2,3,4 개의 군집이 모였는지 {y,x}를 vector로 넣어서 관리

*/
struct Coordi {
	int y, x;
	bool operator==(Coordi right) const { // 같은 HashValue에서 정확한 key의 data를 찾기 위해 사용 
		return y == right.y && x == right.x;
	}
};
struct HashFuncCoordi {
	size_t operator()(Coordi key) const {
		return key.y * 100 + key.x;
	}
};
struct Microbe {
	int y, x;
	int numOfMicrobe;
	int heading;
};
unordered_map<Coordi, vector<int>, HashFuncCoordi> DAT;
unordered_map<int, Microbe> Colony;
int N, M, K;

// heading (상:1,하:2,좌:3,우:4)
int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,-1 ,1 };

void init() {
	// DAT[1~5] , 1: map에 1개의 군집만 존재하는 좌표, 2: ... 5: map에 가장자리에 존재하는 군집의 좌표
	N = M = K = 0;
	DAT.clear();
	Colony.clear();

}
void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int y, x, numOfMicrobe, heading;
		cin >> y >> x >> numOfMicrobe >> heading;
		Colony[i] = { y,x,numOfMicrobe,heading };
	}
}
void solution() {
	// 미생물 입력 완료! 미생물 군집마다 이동 시작
	
	for (int t = 0; t < M; t++) {
		// unordered_map 데이터 접근 (나중에 erase로 없앨녀석 없앨거라)
		// 1. 이동
		for (auto it = Colony.begin(); it != Colony.end(); it++) {
			int now_y = it->second.y;
			int now_x = it->second.x;
			int now_heading = it->second.heading;
			
			int next_y = now_y + dy[now_heading];
			int next_x = now_x + dx[now_heading];

			// 이동 내용 update
			it->second.y = next_y;
			it->second.x = next_x;

			// DAT update
			int id = it->first;
			DAT[{next_y, next_x}].push_back(id);
		}


		// 2. 이동 완료, 겹친 녀석들, 경계 녀석들 작업
		// 2-1. 경계 녀석들 작업(반절 죽이기 , 방향 바꾸기)
		for (auto it = Colony.begin(); it != Colony.end(); it++) {
			int now_y = it->second.y;
			int now_x = it->second.x;

			if (now_y == 0 || now_y == N - 1 || now_x == 0 || now_x == N - 1) {
				// 2-1-1. 반절 죽이기
				it->second.numOfMicrobe /= 2;	

				// 2-1-2. 방향 바꾸기
				it->second.heading += 1;
				if (it->second.heading > 4) {
					it->second.heading = 3;
				}
				else if (it->second.heading == 3) {
					it->second.heading = 1;
				}
			}
		}

		// 2-2. 겹친 녀석들 제일 미생물 수 많은 녀석으로 통합시키고 나머지 삭제
		for (auto it = DAT.begin(); it != DAT.end(); it++) {
			
			// 2-2-1. 겹친 녀석들 중 최고 존엄 찾기!
			int overlap = it->second.size();	// 겹친 개수
			if (overlap >= 2) {
				int max = 0;
				int max_id = 0;
				int sum_numOfMicrobe = 0;
				for (int i = 0; i < overlap; i++) {
					int id_fromDAT = it->second[i];
					int tgt = Colony[id_fromDAT].numOfMicrobe; 

					sum_numOfMicrobe += tgt;
					if (max < tgt) {
						max = tgt;
						max_id = id_fromDAT;
					}
				}
				// 2-2-2. 제일 큰 녀석한테 미생물 수 몰아주기
				Colony[max_id].numOfMicrobe = sum_numOfMicrobe;

				// 2-2-3. 버려진 녀석들 erase -> max_id가 아니면 합쳐져서 없어짐.
				for (int i = 0; i < overlap; i++) {
					int id_fromDAT = it->second[i];

					if (id_fromDAT != max_id) {
						Colony.erase(id_fromDAT);
					}
				}
			}
			// 2-2-4. vector 초기화
			it->second.clear();
		}
	}
}

void print(int testcase) {

	int sum = 0;
	for (auto it = Colony.begin(); it != Colony.end(); it++) {
		sum += it->second.numOfMicrobe;
	}

	cout << "#" << testcase << " " << sum << "\n";

}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solution();
		print(tc);
	}
}