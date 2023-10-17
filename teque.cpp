#include<iostream>
#include<deque>
using namespace std;
int main() {
	int n;cin >> n;
	deque<int>v;deque<int>u;
	while (n--) {
		string s;int x;cin >> s >> x;
		if (s == "push_back") {
			u.push_back(x);
			if (u.size() > v.size()) {
				v.push_back(u.front());
				u.pop_front();
			}
		}
		else if (s == "push_front") {
			v.push_front(x);
			if (v.size() > u.size() + 1) {
				u.push_front(v.back());
				v.pop_back();
			}
		}
		else if (s == "push_middle") {
			if (v.size() > u.size()) {
				u.push_front(x);
			}
			else {
				v.push_back(x);
			}
		}
		else {
			if (x >= v.size()) {
				cout << u[x - v.size()] << endl;
			}
			else { cout << v[x]<<endl; }
		}
		cout<<"";
	}
	return 0;
}