#include<iostream>
#include<vector>
using namespace std;
int main() {
	string s; cin >> s;
	s = string(s.rbegin(), s.rend());
	long long sum=0, aux=0;
	vector<int>v(21,0);
	for (int i = 0; i < s.length(); i++) {
		v[i] = s[i] - '0';
		sum += v[i];
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != 0) {
			v[i] = 0;
			v[i + 1]++;
			break;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 10) { v[i] = 0; v[i + 1]++; }
	}
	for (int i = 0; i < v.size(); i++) {
		aux += v[i];
	}
	int index = 0;
	while (aux < sum) {
		if (v[index] == 9)index++;
		else { v[index]++; aux++; }
	}
	v = vector<int>(v.rbegin(), v.rend());
	index = 0;
	while (v[index] == 0)index++;
	while (index < v.size()) {
		cout << v[index]; index++;
	}
	cout << '\n';
	return 0;
}