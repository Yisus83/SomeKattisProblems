#include<iostream>
#include<vector>
using namespace std;

void possible(vector<vector<char> >& v, int i, int j, int n) {
    if (i + 1 < n && v[i + 1][j] == '.') {
        v[i + 1][j] = 'a';
        possible(v, i + 1, j, n);
    }
    if (j + 1 < n && v[i][j + 1] == '.') {
        v[i][j + 1] = 'a';
        possible(v, i, j + 1, n);
    }
    if (i > 0 && v[i - 1][j] == '.') {
        v[i - 1][j] = 'a';
        possible(v, i - 1, j, n);
    }
    if (j > 0 && v[i][j - 1] == '.') {
        v[i][j - 1] = 'a';
        possible(v, i, j - 1, n);
    }
}

int sum(vector<vector<long long int> >& v, int n, vector<vector<char> >& c) {
    v[0][0] = 1;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (c[i][j] == '#') { v[i][j] = 0; }
            else {
                if (j > 0) { v[i][j] += v[i][j - 1]; }
                if (i > 0) { v[i][j] += v[i - 1][j]; }
                v[i][j] = v[i][j] % (2147483647);
            }
        }
    }
    return v[n - 1][n - 1];
}

int main() {
    int n;cin >> n;char c;
    vector<vector<char> >vc;
    vector<vector<long long int> >vi;
    for (int i = 0;i < n;i++) {
        vector<char>auxc;vector<long long int>auxi;
        for (int j = 0;j < n;j++) {
            cin >> c;auxc.push_back(c);auxi.push_back(0);
        }
        vc.push_back(auxc);
        vi.push_back(auxi);
    }
    if (vc[0][0] == '#' || vc[n - 1][n - 1] == '#') { cout << "INCONCEIVABLE";return 0; }
    else { vc[0][0] = 'a';possible(vc, 0, 0, n);if (vc[n - 1][n - 1] != 'a') { cout << "INCONCEIVABLE";return 0; } }
    int x = sum(vi, n, vc);
    if (x == 0) { cout << "THE GAME IS A LIE"; }
    else { cout << x; }
    return 0;
}