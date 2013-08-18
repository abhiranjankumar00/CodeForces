//%%%%%%%%%%%%
//%%%%lost%%%%
//%%%%%%%%%%%%

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

typedef long long  int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<string> vs;

#define Pf	printf
#define	Sf	scanf

#define PI M_PI
#define E M_E
#define	ep	1e-9

#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp	make_pair

#define pb	push_back
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0; i < n; i++)
#define forab(i, a, b)	for(int i = a; i <= b; i++)
#define rep(i, a, b)	for(int i = a; i>=b; i--)
#define Sq(x)	(x*x)

struct Target {
	int x, r, hit, idx;
	Target() {
		hit = -1, idx = -1;
	}
	Target(int _x, int _r, int _idx) {
		x = _x, 	r = _r, 	hit = -1, 	idx = _idx;
	}
	void Print() {
		Pf(" {%d %d %d}\n", x, r, hit);
	}
};

bool operator < (const Target &a, const Target &b) {
	return a.x < b.x;
}

bool Less(const Target &a, const Target &b) {
	return a.idx < b.idx;
}

bool In(int x, int y, const Target &t) {
	int dist = (t.x - x)*(t.x - x) + y*y ;
//	Pf("x = %d, y = %d , t.x = %d, t.r = %d, dist = %d\n"  , x, y , t.x, t.r, dist );
	return dist <= Sq(t.r);
}

int main()
{
	int n, m, x, y, r, idx, cnt;

	while(~Sf("%d", &n)) {
		Target t[10010];
		cnt = 0;
		forn(i, n)
			Sf("%d %d", &x, &r), 	t[i].x = x, 	t[i].r = r, 	t[i].idx = i+1;
		sort(t, t+n);
/*
		forn(i, n)
			t[i].Print();
*/
		Sf("%d", &m);

		forn(i, m) {
			Sf("%d %d", &x, &y);
			idx = lower_bound(t, t+n, Target(x, 0, -1)) - t;


			if(idx-1 >= 0 && idx-1 < n) 
				if(t[idx-1].hit < 0)
					if(In(x, y, t[idx-1]))
						t[idx-1].hit = i+1, cnt++ /*, Pf("{%d %d} idx = %d ", x, y, idx-1), t[idx-1].Print()*/;
			if(idx >= 0 && idx < n)
				if(t[idx].hit < 0)
					if(In(x, y, t[idx]))
						t[idx].hit = i+1, cnt++ /*, Pf("x = %d , y = %d, idx = %d ", x, y, idx), t[idx].Print()*/;
		}

		sort(t, t+n, Less);

		cout << cnt << endl;
		forn(i, n)
			Pf("%d ", t[i].hit);

		cout << endl;
	}


	return 0;
}
