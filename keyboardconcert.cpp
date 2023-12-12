#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, m;cin >> n >> m;
	vector<vector<int>>v;
	vector<bool>k(n, true);
	for (int i = 0;i < n;i++) {
		int x;cin >> x;
		for (int j = 0;j < x;j++) {
			int y;cin >> y;
			while (v.size() <= y) { v.push_back({}); }
			v[y].push_back(i);
		}
	}
	int sw = 0;
	for (int i = 0;i < m;i++) {
		int x;cin >> x;
		vector<bool>aux(n, false);
		for (int j = 0;j < v[x].size();j++) {
			aux[v[x][j]] = true;
		}
		for (int j = 0;j < n;j++) {
			if (aux[j] == false && k[j] == true) {
				k[j] = false;
			}
		}
		bool t4s = false;
		for (int j = 0;j < n;j++) {
			if (k[j] == true) {
				t4s = true;
			}
		}
		if (t4s == false) {
			sw++;
			k = aux;
		}
	}
	cout << sw << endl;
	return 0;
}