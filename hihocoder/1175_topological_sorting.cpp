#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map> 
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
using namespace std;

int a[100010];
vector<int> g[100010];
int in[100010];

const int MOD = 142857;

int main() {
//	freopen("in.txt", "r", stdin); 
//	ifstream fin("in.txt");
//	cin.rdbuf(fin.rdbuf());

	int n, m, k;
	
	cin >> n >> m >> k;
	int x;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < k; i++) {
		cin >> x;
		a[x]++;
	}
	memset(in, 0, sizeof(in));
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		in[v]++;
		g[u].push_back(v);
	}
	
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			que.push(i);
		}
	}
	int ans = 0;
	while(!que.empty()) {
		int u = que.front();
		que.pop();
		ans = (ans + a[u]) % MOD;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			in[v]--;
			a[v] = (a[v] + a[u]) % MOD;
			if (in[v] == 0) que.push(v);
		}
	}
	cout << ans << endl;
	return 0;
}
 
