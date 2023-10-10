#include <iostream>

using namespace std;

int main() {

	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int min_dist = x;

	if (min_dist > y) {
		min_dist = y;
	}
	if (min_dist > (w-x)) {
		min_dist = (w-x);
	}
	if (min_dist > (h-y))
		min_dist = (h-y);

	cout << min_dist << endl;


}