#include<iostream>
using namespace std;
int main() {
	int n, m, aux, x;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> m;
		aux = 1;
		for (int i = 0;i < m;i++) {
			cin >> x;
			if (x == aux) {
				aux++;
			}
		}
		cout << m-aux+1 << endl;
	}

	return 0;
}