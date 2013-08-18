//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl		("\n")
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

int cnt[5005][5005];
int len;
char st[5005];
bool palin[5005][5005];

void updateFreq(int r, int c) {
	int cc;
	while(r <= len) {
		cc = c;
		while(cc <= len) {
			cnt[r][cc]++;
			cc += (cc & (-cc));
		}
		r += (r & (-r));
	}
}

int readFreq(int r, int c) {
	int ret = 0;
	int cc;
	while(r > 0) {
		cc = c;
		while(cc > 0) {
			ret += cnt[r][cc];
			cc -= (cc & (-cc));
		}
		r -= (r & (-r));
	}
	return ret;
}

int main()
{
	Sf("%s", st+1);
	len = strlen(st+1);

	int q;
	Sf("%d", &q);

	forn(d, len+1) {
		forab(i, 1, len) {
			int j = i+d;
			if(j > len)
				break;

			if(i == j)
				palin[i][j] = true;
			else if(j-i == 1) 
				palin[i][j] = st[i]==st[j] ? true : false;
			else if(palin[i+1][j-1])
				palin[i][j] = st[i] == st[j] ? true : false;
			else
				palin[i][j] = false;

			if(palin[i][j])
				updateFreq(i, j);
		}
	}

	while(q--) {
		int l, r;
		Sf("%d %d", &l, &r);
		int ans = readFreq(r, r) - readFreq(r, l-1) - readFreq(l-1, r) + readFreq(l-1, l-1);
		Pf("%d\n", ans);
	}

	return 0;
}

