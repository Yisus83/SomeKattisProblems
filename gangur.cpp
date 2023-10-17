#include<iostream>
using namespace std;
int main() {
	string s;cin >> s;long long y = 0, x=0;
	for (int i = 0;i < s.length();i++) {
		if (s[i] == '>') {
			y++;
		}
		else if (s[i] == '<') {
			x += y;
		}
	}
	cout << x;
	return 0;
}