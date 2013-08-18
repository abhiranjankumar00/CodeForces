//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defence Force

#include <iostream>
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
#ifdef __cplusplus
	#undef __cplusplus
	#define __cplusplus 199712L
#endif
*/

#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif

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

const int SZ = 2001;
int Palin[SZ][SZ];
int cntl[SZ], cntr[SZ];
ST s;
int sz;

int palin(int x, int y) {
	assert(x >= 0 && y >= x && y < sz);

	int &ret = Palin[x][y];

	if(ret > -1)
		return ret;

	if(y - x < 2)
		return ret = (s[x] == s[y] ? 1 : 0);

	if(s[x] == s[y] && palin(x+1, y-1))
		return ret = 1;
	return ret = 0;
}

int main()
{
	CL(Palin, -1);
	cin >> s;
	sz = s.size();
	
	forn(i, sz)
		forab(j, i, sz-1)
			if(palin(i, j))
				cntr[i]++,	cntl[j]++;

//	forn(i, sz)
//		Pf("%d \t (->) %d, \t (<-) %d\n", i, cntr[i], cntl[i]);

	int64 ans = 0;
	forn(i, sz-1)
		forab(j, i+1, sz-1)
			ans += (1ll*cntl[i])*cntr[j];

	cout << ans << endl;
	return 0;
}

