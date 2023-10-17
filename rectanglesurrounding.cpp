#include<iostream>
using namespace std;
int main() {
	int n, x1, x2, y1, y2, tot=0, minx=500, maxx=0, miny=500, maxy=0;
	bool v[500][500];
	cin >> n;
	for (int i = 0;i < 500;i++) {
		for (int j = 0;j < 500;j++) {
			v[i][j] = false;
		}
	}
	while (n != 0) {
		for (int g = 0;g < n;g++) {
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 < minx) {
				minx = x1;
			}
			if (x2 > maxx) {
				maxx = x2;
			}
			if (y1 < miny) {
				miny = y1;
			}
			if (y2 > maxy) {
				maxy = y2;
			}
			for (int i = x1;i < x2;i++) {
				for (int j = y1;j < y2;j++) {
					v[i][j] = true;
				}
			}
		}
		for (int i = minx;i < maxx;i++) {
			for (int j = miny;j < maxy;j++) {
				if (v[i][j] == true) {
					tot++;
					v[i][j] = false;
				}
			}
		}
		minx = 500;
		miny = 500;
		maxx = 0;
		maxy = 0;
		cout << tot << endl;
		cin >> n;
		tot = 0;
	}
	return 0;
}