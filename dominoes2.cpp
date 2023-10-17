#include<iostream>
#include<vector>
using namespace std;

void tevacae(vector<bool>& b, vector<vector<int> >& v, int z) {
	for (int i = 0;i < v[z].size();i++) {
		if (b[v[z][i]] == false) {
			b[v[z][i]] = true;
			tevacae(b, v, v[z][i]);
		}
	}
}

int main() {
	vector<vector<int> >v;
	int n, m, l, x, y, z, a;
	cin >> a;
	for (int h = 0;h < a;h++) {
		cin >> n >> m >> l;
		vector<bool>b(n+1, false);
		for (int i = 0;i <= n;i++) {
			v.push_back({});
		}
		for (int i = 0;i < m;i++) {
			cin >> x >> y;
			v[x].push_back(y);
		}
		for (int i = 0;i < l;i++) {
			cin >> z;
			b[z] = true;
			tevacae(b, v, z);
		}
		x = 0;
		for (int i = 0;i < b.size();i++) {
			if (b[i] == true) {
				x++;
			}
		}
		v.erase(v.begin(), v.end());
		cout << x << endl;
	}
	return 0;
}