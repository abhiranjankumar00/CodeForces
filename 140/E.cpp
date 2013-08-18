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

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define	Sf		scanf
#define	Pf		printf
#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

int64 mod, l, r, k, range;

struct Zero {
	int64 a, b, c, d;
};
const Zero operator *(const Zero &X, const Zero &Y) {
	Zero ret;
	ret.a = (X.a*Y.a) % mod + (X.b*Y.c) % mod;
	ret.b = (X.a*Y.b) % mod + (X.b*Y.d) % mod;
	ret.c = (X.c*Y.a) % mod + (X.d*Y.c) % mod;
	ret.d = (X.c*Y.b) % mod + (X.d*Y.d) % mod;
	ret.a = (ret.a % mod + mod) % mod;
	ret.b = (ret.b % mod + mod) % mod;
	ret.c = (ret.c % mod + mod) % mod;
	ret.d = (ret.d % mod + mod) % mod;
	return ret;
}

Zero _pow(int64 n) {
	Zero ret;
	ret.a = ret.b = ret.c = 1;
	ret.d = 0;
	if(n == 0) {
		return ret;
	}
	if(n % 2 == 1)
		return ret * _pow(n-1);
	ret = _pow(n/2);
	ret = ret*ret;
	return ret;
}

int64 fact(int64 n) {
	return _pow(n).a;
}

int main()
{
	cin >> mod >> l >> r >> k;
	if(l%2 == 1)
		l++;
	if(r%2 == 1)
		r--;
	range = (r-l)/2 + 1;

	if(range < k)
		cout << 1 % mod << endl;
	else  {
		int64 F = fact(r - 2*k + 2);
		cout << F << endl;
	}

	return 0;
}

