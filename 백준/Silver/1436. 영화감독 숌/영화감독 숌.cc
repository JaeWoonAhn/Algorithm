#include <bits/stdc++.h>

using namespace std;

int main() {
	int flag = 0;

	int n;
	cin >> n;

	string target = "665";
	int cnt = 0;
	while (cnt < n) {

		if (flag == 1) {
			flag = 0;
		}
		else {
			long long tmp = stoi(target);
			tmp++;
			//cout << tmp << endl;
			target = to_string(tmp);
		}

		for (int i = 0; i < target.length()-2; i++) {
			//cout << i << endl;
			string str = target.substr(i, 3);
			if (str == "666") {
				cnt++;
				long long tmp = stoi(target);
				tmp++;
				//cout << tmp << endl;
				target = to_string(tmp);
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1) {
		long long tmp = stoi(target);
		tmp--;
		//cout << tmp << endl;
		cout << tmp << endl;
	}
	else {
		cout << target << endl;
	}
	
	

	return 0;
}