#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<map>
#include<queue>

using namespace std;

typedef long long ll;
using pii = pair<int, int>;

void bfs(int i, int j, vector<vector<char > >& t, int n, int m) {

	queue<pair<int, int> > q;
	q.push(make_pair(i, j));

	vector<vector<int> > used(n + 2, vector<int>(m + 2, 0));

	used[i][j] = true;

	while (!q.empty()) {
		pii p = q.front();
		q.pop();

		int x = p.first, y = p.second;

		if (t[x][y] != 'B' && t[x][y] != 'h') {
			t[x][y] = '.';
			if (x + 1 < n + 2) {
				if (used[x + 1][y] == 0) {
					used[x + 1][y] = 1;
					q.push(make_pair(x + 1, y));
				}
			}
			if (y + 1 < m + 2) {
				if (used[x][y + 1] == 0) {
					used[x][y + 1] = 1;
					q.push(make_pair(x, y + 1));
				}
			}
			if (x - 1 >= 0) {
				if (used[x - 1][y] == 0) {
					used[x - 1][y] = 1;
					q.push(make_pair(x - 1, y));
				}
			}
			if (y - 1 >= 0) {
				if (used[x][y - 1] == 0) {
					used[x][y - 1] = 1;
					q.push(make_pair(x, y - 1));
				}
			}

		}
	}

}


void solved() {

	int n, m;
	cin >> n >> m;
	vector<vector<char > > table(n + 2, vector<char>(m + 2, 'b'));

	int k;
	cin >> k;
	vector<pair<int, int> > vp(k);
	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> vp[i].first >> vp[i].second;
		x = vp[i].first;
		y = vp[i].second;
		table[x][y] = 'B';
	}
	vp.push_back(vp[0]);

	for (int i = 1; i < vp.size(); i++) {
		pii from = vp[i - 1];
		pii to = vp[i];

		if (from.first == to.first) {
			int x = from.first;
			for (int j = min(to.second, from.second) + 1; j < max(to.second, from.second); j++) {
				table[x][j] = 'h';
			}
		}
		else {
			int y = from.second;
			for (int i = min(from.first, to.first) + 1; i < max(from.first, to.first); i++) {
				table[i][y] = 'h';
			}
		}
	}

	bool start = 0;

	table[0][0] = '.';
	bfs(0, 0, table, n, m);

	/*
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			cout << table[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
	*/

	/*a Ц количество полных клеток.
	b		Ц количество половинных клеток.
	c		Ц количество внешних углов.
	d		Ц количество внутренних углов.*/

	int A = 0, B = 0, C = 0, D = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (table[i][j] == 'b' || table[i][j] == 'h') {
				if (table[i + 1][j] == '.' || table[i][j + 1] == '.' ||
					table[i - 1][j] == '.' || table[i][j - 1] == '.') {
					B++;
				}
				else
					A++;
			}

			else if (table[i][j] == 'B') {

				if (table[i + 1][j] == '.' || table[i][j + 1] == '.' ||
					table[i - 1][j] == '.' || table[i][j - 1] == '.') {
					C++;
				}
				else
					D++;
			}
		}
	}

	cout << A << " " << B << " " << C << " " << D << endl;

}


int main() {
	solved();
}