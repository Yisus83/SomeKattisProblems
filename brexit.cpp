#include<iostream>
#include<vector>
using namespace std;

void brexit(vector<int>& v, vector<int>& w, vector<vector<int>>& u, int i) {
	v[i] = -1;
	for (int j = 0;j < u[i].size();j++) {
		v[u[i][j]]--;
		if (v[u[i][j]]>0&&v[u[i][j]] <= w[u[i][j]] / 2) {
			brexit(v, w, u, u[i][j]);
		}
	}
}

int main() {
	int c, p, x, l;cin >> c >> p >> x >> l;
	vector<int>v(c + 1, 0);vector<vector<int>>u(c+1);
	for (int i = 0;i < p;i++) {
		int y, z;cin >> y >> z;
		v[y]++;v[z]++;u[y].push_back(z);u[z].push_back(y);
	}
	vector<int>w = v;
	brexit(v, w, u, l);
	if (v[x] <= 0) { cout << "leave"; }
	else { cout << "stay"; }
	return 0;
}