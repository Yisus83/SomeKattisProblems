#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	string s;int n;cin >> s >> n;
	vector<char>v;
	for (int i = 0;i < s.size();i++) {
		v.push_back(s[i]);
	}
	sort(v.begin(), v.end());
	for (int i = v.size()-n;i <n;i++) {
		if (v[i] != s[i]) { cout << "No";return 0; }
	}
	cout << "Yes";
	return 0;
}