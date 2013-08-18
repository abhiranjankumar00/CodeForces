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
#include <numeric>	// +1
#include <cassert>
#include <utility>	// +1
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;		// Never used it :X
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/* Why you don't work :(
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater than 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define endl		("\n")			// Really required?
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)	// Defined 3rd time \m/.

#define PI		M_PI			// Fish!!! Fails on some compilers (probably MSVC++ & some GNU C++).
#define E 		M_E			// Fish!!! Fails on some compilers (probably MSVC++ & some GNU C++).
#define	eps		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, __even_my_fish_codes_better__ = (int)n; i < __even_my_fish_codes_better__; i++)
#define forab(i, a, b)	for(int i = a, __even_my_fish_codes_better__ = (int)b; i <= __even_my_fish_codes_better__; i++)
#define rep(i, a, b)	for(int i = a, __even_my_fish_codes_better__ = (int)b; i >= __even_my_fish_codes_better__; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back
// Will use these. PROMISE.
#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//
// Double promise.
#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", (int)n)
#define writeln(n)	printf("%d\n", (int)n)

#if (0 or defined ONLINE_JUDGE)
	#define	debug
#else 
	#define debug(x)	cout << #x << " = " << x << "\n"
#endif

int main()
{
	int N, K;
	cin >> N >> K;

	if(N == 1) {
		if(K == 1)
			cout << "a" << endl;
		else
			cout << -1 << endl;
		return 0;
	}
	if(K == 1) {	//  hack case: 2 1
		cout << -1 << endl;
		return 0;
	}
	if(N < K) {
		cout << -1 << endl;
		return 0;
	}
	if(N == K) {
		forn(i, K)
			cout << (char)('a' + i);
		cout << endl;
		return 0;
	}
	int v = 0;

	forn(i, N-(K-2)) {
		cout << (char)('a' + v);
		v = 1-v;
	}
	v = 2;
	forn(i, K-2) {
		cout << (char)('a' + v);
		v++;
	}

	return 0;
}

