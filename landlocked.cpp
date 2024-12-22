#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<tuple>
using namespace std;

map<char, int>mp;
queue<pair<int, int>>q;
queue<pair<int, int>>swapper;

void floodfill(vector<vector<int>>& board, int x, int y, int z, vector<string>&v, char c) {
	if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()||board[x][y]!=-2)return;
	if (v[x][y] != c) {
		swapper.push({ x,y });
		return;
	}
	board[x][y] = z;
	floodfill(board, x+1, y, z, v, c);
	floodfill(board, x-1, y, z, v, c);
	floodfill(board, x, y+1, z, v, c);
	floodfill(board, x, y-1, z, v, c);
	floodfill(board, x + 1, y+1, z, v, c);
	floodfill(board, x - 1, y-1, z, v, c);
	floodfill(board, x-1, y + 1, z, v, c);
	floodfill(board, x+1, y - 1, z, v, c);
}

int main() {
	int n, m, step=-1; cin >> n >> m;
	int x, y;
	vector<string>v(n);
	vector<vector<int>>board(n, vector<int>(m, -2));
	for (auto &s : v)cin >> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'W' && board[i][j] == -2) {
				floodfill(board, i, j, -1, v, 'W');
			}
		}
	}
	swap(q, swapper);
	while (!q.empty()) {
		step++;
		while (!q.empty()) {
			tie(x, y) = q.front();
			q.pop();
			if (board[x][y] != -2)continue;
			floodfill(board, x, y, step, v, v[x][y]);
		}
		swap(q, swapper);
	}
	set<char>checker;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (checker.find(v[i][j]) == checker.end()) {
				mp[v[i][j]] = board[i][j];
				checker.insert(v[i][j]);
			}
			else {
				mp[v[i][j]] = min(board[i][j], mp[v[i][j]]);
			}
		}
	}

	mp = mp;
	for (auto it : mp) {
		if (it.first != 'W') {
			cout << it.first << " " << it.second << "\n";
		}
	}
	return 0;
}