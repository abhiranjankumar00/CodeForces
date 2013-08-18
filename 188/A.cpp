//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>	// Don't know why it is here.
#include <numeric>		// +1
#include <cassert>
#include <utility>		// +1
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 				int64;
typedef vector<int> 			vi;
typedef string 					ST;		// Never used it :X
typedef stringstream 			SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 			ii;
typedef vector<string> 			vs;

// WHY YOU DON'T WORK :X
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater than 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

#define tr(i, c)		for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)	// \m/ Defined 3rd time.
#define forn(i, n)		for(int i = 0, __even_my_fish_codes_better__ = (int)n; i <  __even_my_fish_codes_better__; i++)
#define forab(i, a, b)	for(int i = a, __even_my_fish_codes_better__ = (int)b; i <= __even_my_fish_codes_better__; i++)
#define rep(i, a, b)	for(int i = a, __even_my_fish_codes_better__ = (int)b; i >= __even_my_fish_codes_better__; i--)

#define PI				M_PI		// Fish!!! Fails on some compilers (probably MSVC++ & some GNU C++).
#define E 				M_E			// Fish!!! Fails on some compilers (probably MSVC++ & some GNU C++).
#define endl			("\n")		// Really required?

#define	all(c)			(c).begin(), (c).end()
#define	cl(a, b)		memset(a, b, sizeof(a))
#define mp				make_pair
#define pb				push_back

#define	Sf				scanf
#define	Pf				printf
#define read(n)			scanf("%d", &n)
#define write(n)		printf("%d ", (int)n)
#define writeln(n)		printf("%d\n", (int)n)

#if (0 or defined ONLINE_JUDGE)		// Why topcoder doesn't use it. :(
	#define	debug
#else 
	#define debug(x)	cout << #x << " = " << x << "\n"
#endif

int main()
{
	long long x, y, m;
	cin >> x >> y >> m;
	long long step = 0;

	if(y < x)
		swap(x, y);

	if(max(x, y) >= m) {
		cout << 0 << "\n";
		return 0;
	}
	if(max(x, y) <= 0) {
		cout << -1 << "\n";
		return 0;
	}

	if(x < 0) {
		step = (-x)/y + ((-x) % y != 0 ? 1 : 0);
		x += step * y;
	}
	while(max(x, y) < m) {
		long long  sum = x + y;
		long long xx = x, yy = y;
		step++;
		x = sum;
		y = max(xx, yy);
	}
	cout << step << "\n";

	return 0;


	while(true) {
		if(max(x, y) >= m)
			break;
		step++;
		long long ssum = x+y;
		if(ssum <= min(x, y)) {
			cout << -1 << "\n";
			return 0;
		}
		long long tmp = x+y;
		long long yy = y;
		long long xx = x;

		x  = max(xx, yy);
		y = tmp;

//		printf("%lld %lld\n", x, y);
	}
	cout << step << "\n";

	return 0;

	if(max(x, y) >= m) {
		cout << 0 << endl;
		return 0;
	}
	long long sum = x+y;
	if( sum <= min(x, y)) {
		cout << -1 << endl;
		return 0;
	}
	// y >= x
	if(y < x)
		swap(x, y);
	while(max(x, y) < m) {
		step++;
		long long tmp = y;
		y += x;
		x = tmp;
		printf("%lld %lld\n", x, y);
	}
	cout << step << "\n";

	return 0;
}

