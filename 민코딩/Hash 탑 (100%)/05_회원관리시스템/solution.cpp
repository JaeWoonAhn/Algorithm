#include <iostream>
#include <unordered_map>

using namespace std;
/*
Q. 회원관리시스템
각 명령어에 대한 결과를 다음과 같이 출력합니다.

회원가입

가입 성공시 : welcome [본인 포함 회원 수]
중복 ID로 인한 가입 실패시 : reg fail
회원 탈퇴 후, 재 가입이 가능합니다.
가입 직후에는, 로그인이 안되어있는 상태입니다.

로그인

로그인 성공시 : login [로그인한 회원 수]
로그인 실패시 : login fail
회원 정보가 잘못되었거나, 이미 로그인 되어 있다면 fail입니다.

비밀번호 변경

변경 성공시 : success
정보가 잘못되어 로그인 실패시 : change fail
탈퇴한 회원의 비밀번호를 변경할 수 없습니다.

로그아웃

로그아웃 성공시 : logout [자신을 제외한 남은 로그인한 회원 수]
정보가 잘못되어 로그아웃 실패시 : logout fail

회원탈퇴

회원탈퇴 성공시 : bye [자신을 제외한 남은 회원수]
정보가 잘못되어 회원 탈퇴 실패시 : bye fail
로그인이 되어있을 때만, 회원 탈퇴가 됩니다.
회원 탈퇴 시, 로그아웃이 된 후 회원 탈퇴가 됩니다.

구현)
 + TIP	// 아래의 값 존재 확인 과정에서도 값이 insert되기 때문에 유의해서 구현할 것
	if (um[-1].row == 0 && um[-1].col == 0) // <- key : -1로 data가 추가
			cout << "1";		// 위의 조건은 um[-1] 이 없더라도 통과된다. 
	

*/
int N;
string command, ID, PW;
unordered_map<string, string> enroll;
unordered_map<string, string> login;

void solution() {
	cin >> command;

	if (command == "reg") {
		cin >> ID >> PW;
		auto it = enroll.find(ID);
		if (it != enroll.end())
		{
			// exist
			cout << "reg fail\n";
			return;
		}
		else
		{
			enroll.insert({ ID,PW });
			cout << "welcome " << enroll.size() << "\n";
			return;
		}
	}
	else if (command == "login") {
		
		cin >> ID >> PW;
		auto it = login.find(ID);
		if (it != login.end())
		{
			// already login
			cout << "login fail\n";
		}
		else
		{
			// don't login 
			auto tgt = enroll.find(ID);
			if (tgt != enroll.end()) {
				if ((*tgt).second == PW) {
					// if DB info is correct -> login
					login.insert({ ID,PW });
					cout << "login " << login.size() << "\n";
				}
				else {
					// pw is not correct
					cout << "login fail\n";
				}
			
			}
			else {
				// there is no info in DB
				cout << "login fail\n";
			}

		}
		return;
	}
	else if (command == "change") {
		string change_PW;
		cin >> ID >> PW >> change_PW;

		auto it = enroll.find(ID);
		if (it != enroll.end()) {
			if ((*it).second == PW) {
				// 아이디 비밀번호 일치 -> 비번 변경
				enroll[ID] = change_PW;
				cout << "success\n";
			}
			else {
				// pw is not correct
				cout << "change fail\n";
			}

		}
		else {
			// there is no such data in DB
			cout << "change fail\n";
		}
		return;

	}
	else if (command == "bye") {
		cin >> ID;
		if (login.find(ID) != login.end()) {
			// exist
			login.erase(ID);
			enroll.erase(ID);
			cout << "bye " << enroll.size() << endl;
			return;
		}
		else {
			cout << "bye fail\n";
			return ;
		}
	
	}
	else if (command == "logout") {
		cin >> ID;
		if (login.find(ID) != login.end()) {
			// exist
			login.erase(ID);
			cout << "logout " << login.size() << endl;
			return;
		}
		else {
			cout << "logout fail\n";
			return;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		solution();

	}

	return 0;
}