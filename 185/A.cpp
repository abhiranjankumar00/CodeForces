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

const int sz = 2e3 + 1;
long long  x[sz], y[sz];

long long  complexity(int N) {
	long long  tot = 0;
	long long  d = 1e18;
	
	for(int i = 0; i < N; i++) {
		for(int j = i+1; j <= N-1; j++) {
			tot++;
			if(x[j] - x[i] >= d)
				break;
			d = min(d, y[j] - y[i]);
		}
	}
	return tot;
}

int main()
{
	long long  d = 1;
	x[0] = 0, y[0] = 0;
	int N = sz;

	for(int i = 1; i <= sz-1; i++) {
		x[i] = 0;
		y[i] = y[i-1] + d;
		d++;
	}
/*
	for(int i = 0; i < N; i++) {
		printf("(%lld, %lld), ",x[i], y[i] );
	}
*/
	long long  K;
	cin >> N >> K;
	long long  kk = complexity(N);
	//cout << "kk = " << kk << "\n"; 
	if(kk > K) {
		for(int i = 0; i < N; i++) {
			printf("%lld %lld\n", x[i], y[i]);
		}
	}
	else {
		cout << "no solution" << "\n";
	}

	return 0;
}

