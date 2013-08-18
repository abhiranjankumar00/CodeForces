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

#define lim 100001

int idx[lim];

void getDivisor(int n, vi& v) {
	int i;
	for( i = 1; i*i <= n; i++)
		if(! (n % i))
			if(i != n/i)
				v.pb(i), 	v.pb(n/i);
			else
				v.pb(i);
	sort(all(v));
}
int main()
{
	int X[lim], n, y;
	CL(idx, -1);

	cin >> n ;
	vvi factor(n);

	int x;
	forn(i, n) {
		Sf("%d %d", &X[i], &y);
		x = X[i];

		vi &f = factor[i];
		if(idx[x] > -1)
			f = factor[idx[x]];
		else
			getDivisor(x, f),	idx[x] = i;

//		Pf("%d : (%d - %d)\n", x, i - y, i - 1);
/*		Pf("%d (%d) -> ", x, f.size());
		tr(it, f)
			cout << *it << " ";
		cout << endl;
*/
		bool flag;
		int cnt = 0;
		forn(j, f.size()) {
			flag = true;
			forab(k, i - y, i-1)
				if(binary_search(all(factor[k]), f[j])) {
					flag = false; 	break;
				}
			if(flag)
				cnt++;
		}
		Pf("%d\n", cnt);
	}

	return 0;
}

