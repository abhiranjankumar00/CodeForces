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
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

#define X first
#define Y second

int main()
{
	int N;
	cin >> N;
	vector < ii > pts(N-1);
	vi t, r, c;

	forn(i, N-1) {
		cin >> pts[i].X >> pts[i].Y; 
		pts[i].X--;
		pts[i].Y--;
	}

	forn(i, N-1) {
		if(pts[i].X != i+1) {
			int x = pts[i].X;
			t.pb(1);
			r.pb(pts[i].X);
			c.pb(i+1);
			forab(j, i, N-2) {
				if(pts[j].X == i+1)
					pts[j].X = x;
				else if(pts[j].X == x)
					pts[j].X = i+1;
			}
		}

		if(pts[i].Y != i) {
			int y = pts[i].Y;
			t.pb(2);
			r.pb(i);
			c.pb(y);
			forab(j, i, N-2) {
				if(pts[j].Y == i)
					pts[j].Y = y;
				else if(pts[j].Y == y)
					pts[j].Y = i;
			}
		}
	}
	cout << t.size() << endl;
	forn(i, t.size()) 
		cout << t[i] << " " << r[i]+1 << " " << c[i]+1 << endl;


	return 0;
}

