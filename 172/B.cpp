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
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
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
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater than 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define endl		("\n")
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define PI		M_PI
#define E 		M_E
#define	eps		1e-9

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

#if (0 or defined ONLINE_JUDGE)
	#define DEBUG
#else 
	#define DEBUG(x)	cout << #x << " = " << x << "\n"
#endif

struct Frac {
	int64 num, den;
	Frac(int64 n, int64 d) {
		num = abs(n);
		den = abs(d);
		d = __gcd(num, den);
		num /= d;
		den /= d;
	}
	bool operator < (const Frac &ob ) const {
		if(num*ob.den < den*ob.num)
			return true;
		if(num*ob.den > den*ob.num)
			return false;
		if(den != ob.den)
			return den < ob.den;
		return num < ob.num;
	}

	Frac operator -(const Frac &ob) const {
		Frac ans(num * ob.den - ob.num * den, den * ob.den);
		return ans;
	}
};

int main()
{
	int64 x, y, n;
	cin >> x >> y >> n;

	Frac ret(0, 1);

	for(int64 b = 1; b <= n; b++) {
		int64 a = (x*b)/y;
		Frac tmp(a, b);
		if( tmp - Frac(x, y) < ret - Frac(x, y) )
			ret = tmp;

		tmp = Frac(a+1, b);
		if( tmp - Frac(x, y) < ret - Frac(x, y) )
			ret = tmp;
	}

	cout << ret.num << "/" << ret.den << endl;

	return 0;
}

