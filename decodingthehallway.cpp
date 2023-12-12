#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int t;cin >> t;
	vector<string>hw(11);
	hw[0] = "";
	hw[1] = "L";
	for (int j = 2;j <= 10;j++) {
		string aux = string(hw[j-1].rbegin(), hw[j-1].rend());
		for (int k = 0;k < aux.length();k++) {
			if (aux[k] == 'L') { aux[k] = 'R'; }
			else { aux[k] = 'L'; }
		}
		hw[j] = hw[j-1] + 'L' + aux;
	}
	for (int i = 1;i <= t;i++) {
		bool p = false;
		int x;cin >> x;
		string s;cin >> s;
		x = min(x, 10);
		bool nice = hw[x].find(s) != string::npos;
		if (nice) { cout << "Case " << i << ": Yes" << endl; }
		else{ cout << "Case " << i << ": No" << endl; }
	}
	return 0;
}