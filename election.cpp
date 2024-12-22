#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t;cin >> t;
	int n, v, u, w;
	while (t--) {
		cin >> n >> v >> u >> w;
		vector<long long>dp(n+1, 0);
		dp[v] = 1;
		long long aux = n - u - v;
		while (aux--) {
			int index = n;
			while (index > v) {
				dp[index] += dp[index - 1];
				index--;
			}
		}
		long long a = 0, b = 0;
		int partition=n/2;
		for (int i = 0;i <= partition;i++) {
			a += dp[i];
		}
		for (int i = partition+1;i <= n;i++) {
			b += dp[i];
		}
		if (b == 0) { cout << "RECOUNT!" << endl; }
		else {
			double x = w * 0.01, y = b * 1.0 / (a + b) * 1.0;
			if (x < y) { cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl; }
			else { cout << "PATIENCE, EVERYONE!" << endl; }
		}
	}
	return 0;
}