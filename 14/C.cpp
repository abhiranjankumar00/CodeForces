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
#ifdef __cplusplus
	#undef __cplusplus
	#define __cplusplus 199712L
#endif
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

#define X first
#define Y second
typedef pair <int64, int64> pt;

struct line {
	pt a, b;
	line (pt x, pt y) {
		a = x,  b = y;
	}
};

bool isLine(line l) {
	if(l.a.X == l.b.X)
		return l.a.Y - l.b.Y != 0;
	if(l.a.Y == l.b.Y)
		return l.a.X - l.b.X != 0;
	return false;
}

bool isParallel(line l1, line l2) {
	if(!isLine(l1))
		return false;
	if(!isLine(l2))
		return false;

	if(l1.a.X == l1.b.X)
		return min(l1.a.Y, l1.b.Y) == min(l2.a.Y, l2.b.Y) && max(l1.a.Y, l1.b.Y) == max(l2.a.Y, l2.b.Y);

	if(l1.a.Y == l1.b.Y)
		return min(l1.a.X, l1.b.X) == min(l2.a.X, l2.b.X) && max(l1.a.X, l1.b.X) == max(l2.a.X, l2.b.X);

	return false;
}

int main()
{
	vector <line> l;

	forn(i, 4) {
		int64 a, b, c, d;
		cin >> a >> b >> c >> d;
		line ll = line(mp(a, b), mp(c, d));
		l.pb(ll);
	}

	if(isParallel(l[0], l[1]) && isParallel(l[2], l[3]))
		cout << "YES";
	else if(isParallel(l[0], l[2]) && isParallel(l[1], l[3]))
		cout << "YES";
	else
		cout << "NO";
	cout << endl;

	return 0;
}

