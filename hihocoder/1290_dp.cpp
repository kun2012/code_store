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
#include <cmath>
using namespace std;

bool a[110][110];
int n, m;
int f[110][110][2]; // 0: right, 1: down

int oo = 100000000;

int main() {
//	freopen("in.txt", "r", stdin); 
//	ifstream fin("in.txt");
//	cin.rdbuf(fin.rdbuf());
	
	cin >> n >> m;
	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == '.') a[i][j] = false;
			else a[i][j] = 	true;
			f[i][j][0] = f[i][j][1] = oo;
		}
	}
	
	f[0][0][0] = 0;
	if (m == 1 || a[0][1]) f[0][0][1] = 0;
	else f[0][0][1] = 1;
	
	if (a[0][0]) {
		f[0][0][0]++;
		f[0][0][1]++;
	}
	
	for (int j = 1; j < m; j++) {
		f[0][j][0] = min(f[0][j][0], f[0][j - 1][0]);
		if (j == m - 1 || a[0][j + 1]) f[0][j][1] = f[0][j - 1][0];
		else f[0][j][1] = f[0][j - 1][0] + 1;
		if (a[0][j]) {
			f[0][j][0]++;
			f[0][j][1]++;
		}
	}
	
	for (int i = 1; i < n; i++) {
		f[i][0][1] = min(f[i][0][1], f[i - 1][0][1]);
		if (i == n - 1 || a[i + 1][0]) f[i][0][0] = f[i - 1][0][1];
		else f[i][0][0] = f[i - 1][0][1] + 1;
		if (a[i][0]) {
			f[i][0][0]++;
			f[i][0][1]++;
		}
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			//right
			f[i][j][0] = f[i][j - 1][0];
			if (i == n - 1 || a[i + 1][j]) f[i][j][0] = min(f[i][j][0], f[i - 1][j][1]);
			else f[i][j][0] = min(f[i][j][0], f[i - 1][j][1] + 1);
			//down
			f[i][j][1] = f[i - 1][j][1];
			if (j == m - 1 || a[i][j + 1]) f[i][j][1] = min(f[i][j][1], f[i][j - 1][0]);
			else f[i][j][1] = min(f[i][j][1], f[i][j - 1][0] + 1);
			if (a[i][j]) {
				f[i][j][0]++;
				f[i][j][1]++;
			}
		}
	}
	
	cout << min(f[n - 1][m - 1][0], f[n - 1][m - 1][1]) << endl;
	
	return 0;
}
 
