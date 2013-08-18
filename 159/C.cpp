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
//#define PI		M_PI
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
// /*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
// */

const  long double PI = 2*acos(0);

long double radToDeg(long double d) {
	long double ret = 180.0 * d / PI;
	if(ret < 0 )
		ret += 360;
	return ret;
}

const int sz = 1e5 + 111;
int X[sz], Y[sz];
long double ang[sz];

int main()
{
//	DEBUG(M_PI);
	int N;
	read(N);

	forn(i, N) {
		Sf("%d %d", &X[i], &Y[i]);
		if(Y[i] == 0) {
			ang[i] = X[i] > 0 ? 0 : 180;
		}
		else
			ang[i] = radToDeg(atan2(Y[i], X[i]));
//		cout << X[i] << " " << Y[i] << ": "  << ang[i] << endl;
	}
	sort(ang, ang+N);

	if(N == 1) {
		cout << 0 << endl;
		return 0;
	}

	long double ans = 360;
	forab(i, 1, N-1) {
		long double t = 360 - (ang[i] - ang[i-1]);
//		DEBUG(t);
		ans = min(ans, 360.0 - (ang[i] - ang[i-1]));
	}
	long double t;
	//t = 360.0 + ang[0] - ang[N-1];

//	t = 360.0 - t;
	t = ang[N-1] - ang[0];
//	DEBUG(t);
	ans = min(ans, t);
	DEBUG(ans);
	Pf("%0.10lf\n", (double) ans);

	return 0;
}

