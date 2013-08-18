#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9
#define	Sf		scanf
#define	Pf		printf

#define pb		push_back
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

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
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;

#define	all(c)		(c).begin(), (c).end()
#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

int main()
{
	vector <ii> idx;
	int x11, y11, x22, y22, x1, x2, y1, y2;
	cin >> x11 >> y11 >> x22 >> y22;
	x1 = min(x11, x22),	x2 = max(x11, x22);
	y1 = min(y11, y22),	y2 = max(y11, y22);

	forab(x, x1, x2) {
		idx.pb(mp(x, y1));
		idx.pb(mp(x, y2));
	}
	forab(y, y1, y2) {
		idx.pb(mp(x1, y));
		idx.pb(mp(x2, y));
	}
	sort(all(idx));
	idx.resize(unique(all(idx)) - idx.begin());
	vi in(idx.size(), 1);
/*
	tr(it, idx) {
		Pf("(%d, %d) ", it->first, it->second);
	}
*/
	int test, x, y, r, xx, yy;
	cin >> test;
	while(test--) {
		Sf("%d %d %d", &x, &y, &r);

		forn(i, idx.size()) {
			xx = x - idx[i].first;
			yy = y - idx[i].second;
			if(xx*xx + yy*yy <= r*r)
				in[i] = 0;
		}

	}

	cout << accumulate(all(in), 0) << endl;
	return 0;
}

