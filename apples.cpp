#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m;cin >> n >> m;
	vector<string>g;vector<vector<pair<char, int> > >v(m);
	for (int i = 0;i < n;i++) {
		string s;cin >> s;g.push_back(s);
	}
	for (int i = 0;i < m;i++) {
		int a = 0;int d = 0;
		for (int j = 0;j < n;j++) {
			if (g[j][i] == 'a') {
				a++;
			}
			else if (g[j][i] == '.') { d++; }
			else {
				if (d != 0) { v[i].push_back(make_pair('.', d)); }
				if (a != 0) { v[i].push_back(make_pair('a', a)); }
				a = 0;while (j<n&&g[j][i] == '#') {
					a++;
					j++;
				}
				v[i].push_back(make_pair('#', a));
				a = 0;
				d = 0;
				j--;
			}
			cout << "";
		}
		if (d != 0) { v[i].push_back(make_pair('.', d)); }
		if (a != 0) { v[i].push_back(make_pair('a', a)); }
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (v[j][0].second == 0) {
				v[j].erase(v[j].begin());
			}
			cout << v[j][0].first;v[j][0].second--;
		}
		cout << endl;
	}
	return 0;
}