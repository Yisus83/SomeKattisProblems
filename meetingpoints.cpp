#include<iostream>
#include<climits>
#include<map>
using namespace std;
int main() {
	int n; cin >> n;
	map<double,int>mp;
	long long x, y, xx, yy, sol = 0;
	double aux;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> xx >> yy;
		if (x == xx) {
			sol += i - mp[INT_MAX];
			mp[INT_MAX]++;
		}
		else {
			aux = 1.0*(y - yy) / (x - xx);
			sol += i - mp[aux];
			mp[aux]++;
		}
	}
	cout << sol << endl;
	return 0;
}