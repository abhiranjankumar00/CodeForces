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

vector <double> radius;
vi s;
vi x;
vi p;
int n;

void relax(int i, int j) {
	assert(j < s.size());
	int t= s[j];
	radius[i] =  min(radius[i], (x[i] - x[t])*(x[i]-x[t]) / (4*radius[t]));
}

int solve() {
	double sum = 0;
	forn(i, n) {
		DEBUG(i);
		radius.pb(p[i]);
//		DEBUG("#1");
		forn(j, min((int)s.size(), 300))
			relax(i, j);
//			relax(i, (int)s.size() - j -1 );
//		DEBUG("#2");
		while(s.empty() == false && radius[s.back()] <= radius[i])
			s.pop_back();
		s.pb(i);
		sum += radius[i];
	}
	cout << "radius : ";
	tr(it, radius)
		Pf("%lf ", *it);
	cout << endl;
	return sum;
}

int main()
{
	cin >> n;
	forn(i, n) {
		int xt, pt;
		cin >> xt >> pt;
		x.pb(xt);
		p.pb(pt);
	}
	cout << solve() << endl;

	return 0;
}
