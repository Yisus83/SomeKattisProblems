#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m;cin >> n >> m;
	string s;cin >> s;
	vector<int>v = { min(n,m)-1,abs(n - m)-1,9 - max(n,m) };
	vector<int>u = { 0,min(n,m),max(n,m)};
	int j = 0;
	vector<int>sol;
	for (int i = 0;i < 4;i++) {
		if (s[i] == 'B') {
			if (i < 3 && s[i + 1] == 'B') {
				if (v[j] == 2) {
					sol.push_back(u[j] + 1);
					sol.push_back(sol[0] + 1);
					i = 4;
				}
				else {
					cout << -1;
					return 0;
				}
			}
			else {
				if (v[j] == 1) {
					sol.push_back(u[j] + 1);
				}
				else {
					cout << -1;return 0;
				}
			}
		}
		else {
			j++;
		}
	}
	cout << sol[0] << " " << sol[1];
	return 0;
}