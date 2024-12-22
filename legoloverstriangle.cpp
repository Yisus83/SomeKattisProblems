#include<iostream>
using namespace std;

long long checker(long long a, long long b) {
	long long c = 0, d = 0;
	double side = a / b;
	for (int i = 0; i < b; i++) {
		if (i % 2 == 0) {
			c += side * i / 2;
		}
		else {
			c += (side * i - 1) / 2;
		}
	}
	for (int i = 0; i < b; i++) {
		if (i % 2 == 1) {
			d += side * i / 2;
		}
		else {
			d += (side * i - 1) / 2;
		}
	}
	return max(c, d);
}

int main() {
	long long a, b;
	cin >> a >> b;
	cout << max(checker(a, b), checker(b, a)) << endl;
	return 0;
}