#include<iostream>
using namespace std;
int main() {
	int x, y=0;cin >> x;
	y += x / 500;
	x = x % 500;
	if (x <= 400) {
		while (x >= 200) {
			y++;
			x -= 200;
		}
		if (x <= 100) {
			while(x>0){
				y++;
				x -= 100;
			}
		}
		else { y++; }
	}
	else { y++; }
	cout << y;
	return 0;
}