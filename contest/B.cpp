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


void solveb() {
	int n, m;
	cin >> n >> m;
	vector<vector<char> > form(n, vector<char>(m + 1));
	char c;
	string fict;
	c = getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m + 1; j++) {
			form[i][j] = getchar();
		}
	}

	bool start = 0, finish = 0;

	int k;
	cin >> k;

	vector<int> cnts(k);
	vector<char> syl(k);// lab(k);

	for (int i = k - 1; i >= 0; i--) {
		cin >> fict >> cnts[i] >> syl[i];
	}

	k--;

	char c1 = '/', c2 = '\\', c3 = '|';

	for (int i = n - 2; i >= 0; i--) {

		start = 0;

		while (k >= 0 && cnts[k] == 0)
			k--;

		if (k < 0)
			break;

		cnts[k]--;
		c = syl[k];

		for (int j = 0; j < m; j++) {
			if (form[i][j] == ' ')
				form[i][j] = c;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m + 1; j++) {
			cout << form[i][j];
		}
	}
}


int main() {
	solveb();
}