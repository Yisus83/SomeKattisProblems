#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int> >& a) {
	vector<vector<int> >aux;
	vector<int>aux2;
	for (int i =3;i >= 0;i--) {
		for (int j = 0;j <4;j++) {
			aux2.push_back(a[j][i]);
		}
		aux.push_back(aux2);
		aux2.erase(aux2.begin(), aux2.end());
	}
	a = aux;
}

void combine(vector<vector<int> >& a) {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			while (j < a[i].size() - 1 && a[i][j] == 0) {
				a[i].erase(a[i].begin() + j);
			}
		}
		while (a[i].size() < 4) {
			a[i].push_back(0);
		}
		for (int j = 1;j < 4;j++) {
			if (a[i][j - 1] == a[i][j]) {
				a[i][j - 1] *= 2;
				a[i][j] = 0;
			}
		}
		for (int j = 0;j < 4;j++) {
			while (j < a[i].size() - 1 && a[i][j] == 0) {
				a[i].erase(a[i].begin() + j);
			}
		}
		while (a[i].size() < 4) {
			a[i].push_back(0);
		}
	}
}

int main() {
	int n, x;
	vector<vector<int> >a;
	vector<int>aux;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			cin >>x;
			aux.push_back(x);
		}
		a.push_back(aux);
		aux.erase(aux.begin(), aux.end());
	}
	cin >> n;
	for (int i = 0;i < n;i++) {
		rotate(a);
	}
	combine(a);
	for (int i = 0;i < (4 - n);i++) {
		rotate(a);
	}
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}