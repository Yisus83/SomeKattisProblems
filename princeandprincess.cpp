#include<iostream>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	int t;cin >> t;
	int printer = 1;
	while (t--) {
		int n, p, q;cin >> n >> p >> q;
		int x;
		vector<pair<int, int>>v(pow(n,2), { -1,-1 });
		for (int i = 0;i <= p;i++) {
			cin >> x;
			v[x-1].first = i;
		}
		for (int i = 0;i <= q;i++) {
			cin >> x;
			v[x-1].second = i;
		}
		set<pair<int, int>>st;
		x = pow(n, 2);
		for (int i = 1;i < x;i++) {
			if (v[i].first != -1 && v[i].second != -1) {
				st.insert({ v[i].first,v[i].second });
			}
		}
		vector<int>sol = {0};
		for (auto it = st.begin();it != st.end();++it) {
			if(it->second>sol.back()){
				sol.push_back(it->second);
			}
			else{
				int low = lower_bound(sol.begin(), sol.end(), it->second)-sol.begin();
				sol[low] = it->second;
			}
		}
		cout << "Case " << printer << ": " << sol.size()<<endl;
		printer++;
	}
	return 0;
}