#include<iostream>
#include<vector>
using namespace std;
int main() {
	int x, y;
	while (cin >> x >> y) {
		int t; cin >> t;
		vector<pair<string, int>>v(t + 2, {"",0});
		vector<vector<int>>u(x, vector<int>(y, -1));
		cout << "Total " << x * y<<endl;
		for (int i = 0; i < t; i++) {
			cin >> v[i].first;
			int a, b,c,d; cin >> a >> b>>c>>d;
			for (int j = a; j < c; j++) {
				for (int k = b; k < d; k++) {
					if (u[j][k] == -1) {
						u[j][k] = i;
					}
					else {
						u[j][k] = -2;
					}
				}
			}
		}
		v[t].first = "Unallocated";
		v[t + 1].first = "Contested";
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (u[i][j] == -1) {
					v[t].second++;
				}
				else if (u[i][j] == -2) {
					v[t + 1].second++;
				}
				else {
					v[u[i][j]].second++;
				}
			}
		}
		cout << v[t].first << " " << v[t].second << endl;
		cout << v[t + 1].first << " " << v[t + 1].second << endl;
		for (int i = 0; i < t; i++) {
			cout << v[i].first << " " << v[i].second << endl;
		}
		cout << endl;
	}
	return 0;
}