#include<iostream>
#include<stack>
using namespace std;
int main() {
	int n; cin >> n;
	stack<int>v;
	for (int i = 0; i < n*2; i++) {
		int x = 0; cin >> x;
		if (v.size()!=0&&v.top() == x) {
			v.pop();
		}
		else { v.push(x); }
	}
	if (v.size() != 0) { cout << "impossible"; }
	else { cout << 2 * n; }
	return 0;
}