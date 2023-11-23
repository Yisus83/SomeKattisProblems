#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;cin >> n;
    bool c = false;
    if (n == 1) { cin >> n;cout << 1 << endl; }
    else {
        int x, y;cin >> x >> y;
        int aux = 2;
        int sol = 1;
        while (x == y && aux < n) {
            aux++;
            cin >> y;
        }
        if (x < y) { c = true;sol++; }
        else if (x > y) { c = false;sol++; }
        x = y;
        for (int i = aux;i < n;i++) {
            cin >> y;
            if (c == true) {
                if (y < x) {
                    c = false;
                    sol++;
                }
            }
            else {
                if (y > x) {
                    c = true;
                    sol++;
                }
            }
            x = y;
        }
        cout << sol << endl;
    }
    return 0;
}