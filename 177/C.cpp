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
#define write(n)	printf("%d", (int)n)
#define writeln(n)	printf("%d\n", (int)n)

#if (0 or defined ONLINE_JUDGE)
	#define	debug
#else 
	#define debug(x)	cout << #x << " = " << x << "\n"
#endif

const int sz = 1e6 + 111;

int arr[sz];

void printBin(int n, int len) {
	return;
	rep(i, len-1, 0) {
		write((n & (1<<i))== 0 ? 0 : 1);
	}
	cout << " ";
}

int len(int N) {
	int ret = 0;
	while(N > 0) {
		ret++;
		N/=2;
	}
	return ret;
}

int main()
{
	int64 N = 10;
	cin >> N;
	CL(arr, -1);

	debug(N);
	int M = len(N);


	forn(i, N+1)
		printBin(i, M);
	cout << endl;

	if(N % 2 == 0) 
		arr[0] = 0;
	else
		arr[0] = N, arr[N] = 0;

	rep(i, N - N%2, 1) if(arr[i] == -1) {
		int N = len(i) - 2;
		int l = 0;
		rep(j, N, 0)
			if( (i & (1<<j)) == 0)
				l |= (1<<j);
		arr[l] = i;
		arr[i] = l;

		printBin(i, M);
		printBin(l, M);
//		cout << endl;

	}

	int64 sum = 0;

	forab(i, 0, N)
		sum += arr[i]^i;

	cout << sum << endl;
	if(false) forab(i, 0, N)
		Pf("%d ", arr[i]);
	cout << endl;



	return 0;
}

