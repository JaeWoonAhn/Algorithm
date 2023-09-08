/*
Q. 경력직 추천
삼성 재직자는 실력 좋은 경력직 지인을 우리 회사로 추천하고 싶어합니다.
이를 DB에 등록하고자 합니다.
재직자 사번과 추천할 지인 이름을 입력 받습니다.

0 <= 재직자 사번 <= 999,999,999
지인 이름 : 최대 8글자, 대소문자로 허용
다른 사람인데 불구하고, 동명이인 / 중복 사원 ID는 존재하지 않습니다.

******************* 입력
첫 줄에는 명령어의 수 N을 입력 받습니다. (1 <= N <= 170,000)

다음 줄 부터 N 개의 명령어를 입력 받습니다.



지인추천 : recommand [사번] [대상이름]

특정 사번을 가진 재직자가, 특정 인물을 추천합니다.(명령어 최대 호출 수 : 5,000)

해당 사람이 추천한 인물의 수를 출력합니다.

예시)

recommand 35 BTS  //35번이 BTS를 추천 --> 총 추천 수 1 출력
recommand 70 BTS//70번이 BTS를 추천 --> 총 추천 수 1 출력
recommand 35 KFC //35번이 KFC를 추천 --> 총 추천 수 2 출력


추천 인물 출력명령어 : print [사번]

특정 사번이 추천한 사람들을 모두 출력합니다.(명령어 최대 호출 수 : 2,000)

추천한 순서대로 출력합니다.

추천 인물이 한 명도 없다면 none을 출력합니다.

예시)

print 40 // 40번이 추천한 사람들 모두 출력 --> "none" 출력
print 35 // 35번이 추천한 사람들 모두 출력 --> BTS KFC
print 70 // 70번이 추천한 사람들을 모두 출력 --> BTS


인물에 대한 정보 출력 : whois [대상이름]

특정 인물을 추천한 사번들을 출력합니다. (명령어 최대 호출 수 : 100,000)

사번은 오름차순으로 출력합니다.

추천한 사람이 없다면 none을 출력합니다.

예시)

whois BTS --> 35 70
whois BHC --> none
*/

#include <iostream>
#include <unordered_map>	
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
unordered_map<int, vector<string>> for_print;
unordered_map<string, vector<int>> for_whois;

void solution() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;

	string cmd, recom;
	int id_num;

	for (int tc = 1; tc <= N; tc++) {
		cin >> cmd;

		if (cmd == "recommand") {
			cin >> id_num >> recom;
			for_print[id_num].push_back(recom);
			for_whois[recom].push_back(id_num);

			// print how many times "id_num" recommend 
			cout << for_print[id_num].size() << endl;
		}

		else if (cmd == "print") {
			cin >> id_num;
			// print none
			if (for_print[id_num].size() == 0) {
				cout << "none\n";
			}
			else {
				// 추천했던 사람들 출력
				for (int i = 0; i < for_print[id_num].size(); i++) {
					cout << for_print[id_num][i] << " ";
				}
				cout << endl;
			}
		}
		else if (cmd == "whois") {
			string target;
			cin >> target;
			// print who(id_num) recommended target
				// print sorted id_num
			sort(for_whois[target].begin(), for_whois[target].end());
			
			// print none
			if (for_whois[target].size() == 0) {
				cout << "none\n";
			}
			else {
				// 추천했던 사람들 출력
				for (int i = 0; i < for_whois[target].size(); i++) {
					cout << for_whois[target][i] << " ";
				}
				cout << endl;
			}
		}
	}
}

int main() {

	solution();

	return 0;
}