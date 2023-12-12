#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
	int n, l;double p;cin >> n >> l >> p;
	vector<double>v(n + 1,0);
	v[n] = 1;
	for (int i = 0;i < l;i++) {
		for (int j = n;j > 1;j--) {
			double aux = pow(p, j);
			v[j - 1] += v[j] *aux;
			v[j] *= (1 - aux);
		}
		for (int j = 0;j < n;j++) {
			v[j + 1] /= 2;
			v[j] += v[j + 1];
		}
	}
	cout << fixed << setprecision(5) << 1 - v[0] << endl;
	return 0;
}