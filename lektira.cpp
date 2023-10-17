#include<iostream>
#include<string>
using namespace std;

void reverse(string& s) {
	string t = "";
	for (int k = s.size() - 1;k >= 0;k--) {
		t.push_back(s[k]);
	}
	s = t;
}

void compare(string& s, string& t) {
	int x = 0;
	while (x < s.size()) {
		if (s[x] == t[x]) {
			x++;
		}
		else if (s[x] > t[x]) {
			s = t;
			break;
		}
		else {
			break;
		}
	}
}

int main() {
	string s;cin >> s;
	string t, a, b, c, aux="";
	for (int i = 0;i < s.size();i++) {
		aux.push_back('z');
	}
	for (int i = 1;i < s.size() - 1;i++) {
		for (int j = i+1;j < s.size();j++) {
			a = ""; b = "";c = "";
			for (int k = 0;k < i;k++) {
				a.push_back(s[k]);
			}for (int k = i;k < j;k++) {
				b.push_back(s[k]);
			}for (int k = j;k < s.size();k++) {
				c.push_back(s[k]);
			}
			reverse(a);reverse(b);reverse(c);
			t = a + b + c;
			compare(aux, t);
		}
	}
	cout << aux;
	return 0;
}