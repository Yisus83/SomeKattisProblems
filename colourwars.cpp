#include<iostream>
#include<map>
using namespace std;
int main() {
	int n,t;
	map<int, int>s;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> t;
		s[t]++;
	}
	t = 0;
	for (auto it: s) {
		if (it.second > it.first + 1) {
			if (it.second%(it.first+1)==0) {
				t = t + it.second;
			}
			else {
				t = t + ((it.second / (it.first + 1) + 1) * (it.first + 1));
			}
		}
		else {
			t = t + it.first + 1;
		}
	}
	cout << t;
	return 0;
}
