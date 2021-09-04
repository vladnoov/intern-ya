
#include <vector>
#include<algorithm>

#include<iostream>

using namespace std;
int main() {
	vector<pair<int, int>> vp(3), vp_copy;
	cin >> vp[0].first >> vp[1].first >> vp[2].first;

	vp[0].second = 1;
	vp[1].second = 2;
	vp[2].second = 3;

	vp_copy = vp;
	for (int i = 0; i < 3; i++) {
		vp = vp_copy;
		if (vp[i].first >= min(vp[(i + 1) % 3].first, vp[(i + 2) % 3].first) &&
			vp[i].first <= max(vp[(i + 1) % 3].first, vp[(i + 2) % 3].first)) {
			cout << "YES\n";
			continue;
		}

		bool ans = 0;

		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {

				if (k == j) {
					continue;
				}

				vp = vp_copy;
				vp[k].first = vp[k].first - vp[j].first;

				if (vp[i].first >= min(vp[(i + 1) % 3].first, vp[(i + 2) % 3].first) &&
					vp[i].first <= max(vp[(i + 1) % 3].first, vp[(i + 2) % 3].first)) {
					ans = 1;
				}
			}
		}

		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}