#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<map>
#include<queue>
#include<fstream>

using namespace std;

typedef long long ll;
using pii = pair<int, int>;


void solvec() {
	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for (auto& s : a)
		cin >> s;

	vector <ll> tmp;
	vector<ll> b(m);

	ll last_w = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] > last_w) {
			tmp.push_back(a[i]);
			last_w = a[i];
		}
	}

	a.clear();

	a.push_back(tmp[0]);
	for (int i = 1; i < tmp.size(); i++) {
		a.push_back(tmp[i] - tmp[i - 1]);
	}

	sort(a.begin(), a.end());

	for (auto& s : b)
		cin >> s;

	sort(b.begin(), b.end());

	int cntr = 0;

	int ptra = 0, ptrb = 0;

	while (ptra < a.size() && ptrb < b.size()) {
		if (a[ptra] < b[ptrb])
			ptra++;
		else {
			cntr++;
			ptra++;
			ptrb++;
		}
	}

	cout << cntr << endl;
}

int main() {
	int t = 1;

	while (t--)
		solvec();
}