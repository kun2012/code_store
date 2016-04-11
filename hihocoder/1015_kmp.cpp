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
#include <cctype> 
using namespace std;

char s[1000010];
char p[10010];

int next_pos[10010]; //std::next(c++11) 

int main() {
//	freopen("in.txt", "r", stdin); 
//	ifstream fin("in.txt");
//	cin.rdbuf(fin.rdbuf());
	
	int n;
	scanf("%d\n", &n);
	while(n--) {
		scanf("%s", p);
		scanf("%s", s);
		
		next_pos[0] = -1;
		int j = -1, i = 0;
		int plen = strlen(p);
		while(i < plen) {
			if (j == -1 || p[j] == p[i]) next_pos[++i] = ++j;
			else j = next_pos[j];
		}
		int ans = 0;
		int slen = strlen(s);
		j = 0, i = 0;
		
		while(i < slen) {
			if (j == -1 || p[j] == s[i]) ++i, ++j;
			else j = next_pos[j];
			if (j == plen) {
				ans++;
				j = next_pos[j];
			}	
		}
		cout << ans << endl;
	}
	return 0;
}
 
