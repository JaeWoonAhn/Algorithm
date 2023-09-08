#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>	
using namespace std;

int N;
struct team_info {
	int num_of_call;
	int sum_of_score;
};
unordered_map<string, team_info> um;
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++) {
		string team_name;
		int teamMate_score;
		cin >> team_name >> teamMate_score;

		if (um.find(team_name) != um.end()) {
			// exist
			um[team_name].num_of_call++;
			um[team_name].sum_of_score += teamMate_score;
		}
		else {
			// don't exist
			um.insert({ team_name,{1,teamMate_score} });
		}
	}


	vector<string> v;
	string coco_team, friend_team;
	cin >> coco_team >> friend_team;

	string victory_team = coco_team;
	int max = um[coco_team].sum_of_score;


	cout << um[coco_team].num_of_call<< " " <<um[coco_team].sum_of_score << "\n";
	cout << um[friend_team].num_of_call<< " " <<um[friend_team].sum_of_score << "\n";


	if (max < um[friend_team].sum_of_score) {
		victory_team = friend_team;
	}
	cout << victory_team;

}