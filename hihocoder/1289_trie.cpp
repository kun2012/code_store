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

typedef long long ll;

struct node {
	int sta = 0;
	node* next[2];
	//node(int _sta) : sta(_sta) {}  //FIX ME !!!
	
};

node *root;

int n, m;

void ins(node* &p, ll ip, int clen, int len, int sta) {

	if (p == NULL) {
		p = new node();
	}
	
	if (p->sta != 0) return ; //already have an action
	
	if (clen > len) {
		p->sta = sta;
		return ;
	}
	
	int op = (((1ll << (32 - clen)) & ip) == 0 ? 0 : 1);
	
	ins(p->next[op], ip, clen + 1, len, sta);	
}

int query(node* &p, ll ip, int cur) {
	if (cur == 32) return p->sta;
	int op = (((1ll << (32 - cur)) & ip) == 0 ? 0 : 1);
	if (p->next[op] == NULL) return p->sta;
	//return the longest prefix
	int chsta = query(p->next[op], ip, cur + 1);
	if (chsta == 0) return p->sta;
	return chsta;
}

int main() {
//	freopen("in.txt", "r", stdin); 
//	ifstream fin("in.txt");
//	cin.rdbuf(fin.rdbuf());
	
	cin >> n >> m;
	char s[100];
	int sta, len;
	ll t1, t2, t3, t4;
	char c;
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		sta = (s[0] == 'a' ? 1 : 2);
		scanf("%d.%d.%d.%d", &t1, &t2, &t3, &t4);
		scanf("%c", &c);
		if (c == '/') {
			scanf("%d", &len);
		} else {
			len = 32;
		}
		ll ip = (t1 << 24) + (t2 << 16) + (t3 << 8) + t4;
		ins(root, ip, 1, len, sta);
	}
	
	for (int i = 0; i < m; i++) {
		scanf("%d.%d.%d.%d", &t1, &t2, &t3, &t4);
		ll ip = (t1 << 24) + (t2 << 16) + (t3 << 8) + t4;
		int act = query(root, ip, 1);
		if (act == 2) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	
	return 0;
}
 
