#include<iostream>
#include<map>
using namespace std;
int main() {
    int n, m;cin >> n >> m;
    int x = 0, y, z;string s;
    map<int,int>v;
    while (m--) {
        cin >> s;
        if (s == "SET") {
            cin >> y >> z;
            v[y] = z;
        }
        else if (s == "RESTART") {
            cin >> x;
            v.erase(v.begin(), v.end());
        }
        else if (s == "PRINT") {
            cin >> y;
            if (v.find(y)!=v.end()) {
                cout << v[y]<<endl;
            }
            else { cout << x << endl; }
        }
    }
    return 0;
}