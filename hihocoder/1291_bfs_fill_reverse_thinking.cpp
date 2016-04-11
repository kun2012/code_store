#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map> 
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
using namespace std;

struct Point {
	int x, y, z;
	Point(){};
	Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

bool exist[110][110][110];
bool out[110][110][110];
stack<Point> ps;
queue<Point> fq;

//check the neighbors condition
bool check_neighbors(int x, int y, int z) {
	if (exist[x][y][z]) return false;
	if (z == 1) return true;
	if (exist[x - 1][y][z] || exist[x + 1][y][z] || exist[x][y - 1][z] ||
		exist[x][y + 1][z] || exist[x][y][z - 1] || exist[x][y][z + 1])
		return true;
	return false;
}

bool fill(int x, int y, int z) {
	fq.push(Point(x, y, z));
	while(!fq.empty()) {
		Point p = fq.front();
		fq.pop();
		int u = p.x, v = p.y, w = p.z;
		if (u < 0 || u > 101 || v < 0 || v > 101 || z < 1 || z > 101) continue;
		if (exist[u][v][w] || out[u][v][w]) continue;
		out[u][v][w] = true;
		fq.push(Point(u - 1, v, w));
		fq.push(Point(u + 1, v, w));
		fq.push(Point(u, v - 1, w));
		fq.push(Point(u, v + 1, w));
		fq.push(Point(u, v, w - 1));
		fq.push(Point(u, v, w + 1));
	}
}

int main() {
//	freopen("in.txt", "r", stdin); 
//	ifstream fin("in.txt");
//	cin.rdbuf(fin.rdbuf());
	
	int T, n;
	cin >> T;
	while(T--) {
		cin >> n;
		while(!ps.empty()) ps.pop();
		while(!fq.empty()) fq.pop();
		memset(exist, false, sizeof(exist));
		int x, y, z;
		bool is_build_suc = true;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			if (!is_build_suc) continue;
			if (!check_neighbors(x, y, z)) {
				is_build_suc = false;
				continue;
			}
			ps.push(Point(x, y, z));
			exist[x][y][z] = true;
		}
		if (!is_build_suc) {
			cout << "No" << endl;
			continue;
		}
		//cover the ground
		for (int i = 0; i <= 101; i++) {
			for (int j = 0; j <= 101; j++) {
				exist[i][j][0] = true;
			}
		}
		//reverse finding outside points
		memset(out, false, sizeof(out));
		fill(0, 0, 1);
		while(!ps.empty()) {
			Point p = ps.top();
			ps.pop();
			int x = p.x, y = p.y, z = p.z;
			if (out[x - 1][y][z] || out[x + 1][y][z] ||
				out[x][y - 1][z] || out[x][y + 1][z] ||
				out[x][y][z - 1] || out[x][y][z + 1]) {
					exist[x][y][z] = false;
					fill(x, y, z);
			} else {
				is_build_suc = false;
				break;		
			}
		}
		if (is_build_suc) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	
	return 0;
}
 
