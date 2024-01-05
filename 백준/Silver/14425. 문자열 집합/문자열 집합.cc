#include <iostream>
#include <map>

using namespace std;

map<string, bool> m;
string str;
int res = 0;
int N,M;

int main(){
	cin >> N >> M;

	// input
	for(int i = 0; i < N; i++){
		cin >> str;
		m.insert(pair<string, bool>(str, true));
	}

	// output
	for(int i = 0; i < M; i++){
		cin >> str;
		if(m[str] == true){
			res++;	
		}
	}

	cout << res;
}