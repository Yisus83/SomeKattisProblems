#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;cin >> n;vector<int>x(n);vector<int>y(n);
	for (int i = 0;i < n;i++) {
		int a, b;cin >> a >> b;a--;b--;x[i] = a;y[i] = b;
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int c = 0;
	for (int i = 0;i < n;i++) {
		c += abs(x[i] - i);
		c += abs(y[i] - i);
	}
	cout << c;
	return 0;
}