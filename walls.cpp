#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool dist(int x, int y, double a, double b, int r) {
	double aux = pow(pow(1.0 * x - a, 2) + pow(1.0 * y - b, 2), 0.5);
	if (r >= aux) { return true; }
	else { return false; }
}

int main() {
	int l, w, n, r;cin >> l >> w >> n >> r;
	vector<pair<double, double>>v = { {-l *0.5,0},{l*0.5,0},{0,-w*0.5},{0,w*0.5} };
	vector<int>cont(n, 0);
	vector<vector<bool>>b(n, vector<bool>(4, false));
	vector<bool>comp(4,false);
	for (int i = 0;i < n;i++) {
		int x, y;cin >> x >> y;
		for (int j = 0;j < 4;j++) {
			bool aux = dist(x, y, v[j].first, v[j].second, r);
			if (aux==true) { b[i][j] = aux;cont[i]++;comp[j] = true; }
		}
	}
	for (int i = 0;i < 4;i++) {
		if (comp[i] == false) { cout << "Impossible" << endl;return 0; }
	}
	for (int i = 0;i < n;i++) {
		if (cont[i] == 4) { cout << 1 << endl;return 0; }
	}
	for (int i = 0;i < n;i++) {
		if (cont[i] == 3) {
			cout << 2 << endl;return 0;
		}
	}
	bool dos = false;
	for (int i = 0;i < n;i++) {
		if (cont[i] == 2) {
			dos = true;
			for (int j = i+1;j < n;j++) {
				if (cont[j] == 2) {
					bool p = true;
					for (int k = 0;k < 4;k++) {
						if (b[i][k] == b[j][k]) {
							p = false;
						}
					}
					if (p == true) { cout << 2 << endl;return 0; }
				}
			}
		}
	}
	if(dos==true){
		cout << 3 << endl;return 0;
	}
	cout << 4 << endl;return 0;
	return 0;
}