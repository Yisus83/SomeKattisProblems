#include<iostream>
#include<deque>
using namespace std;
int main() {
	deque<char>a;
	deque<char>b;
	string s;cin >> s;
	for (char c : s) {
		if (c == 'R') {
			a.push_back(b.front());
			b.pop_front();
		}
		else if (c == 'L') {
			b.push_front(a.back());
			a.pop_back();
		}
		else if (c == 'B') {
			a.pop_back();
		}
		else {
			a.push_back(c);
		}
	}
	for (int i = 0;i < a.size();i++) {
		cout << a[i];
	}
	for (int i = 0;i < b.size();i++) {
		cout << b[i];
	}cout << endl;
	return 0;
}