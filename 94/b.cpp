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
#define	CL(a, b)	memset(a, b, sizeof(a))

int main()
{
	int n, m, x, y;
	bool in[111];
	CL(in, -1);
	
	cin >> n >> m;
	vector <set <int> > v(n);

	forn(i, m) {
		Sf("%d %d", &x, &y);
		v[x-1].insert(y-1);
		v[y-1].insert(x-1);
	}

	int ans = 0;
	set<int> :: iterator jt;

	while(true) {
		vi a;
		a.clear();
		forn(i, n)	if(in[i] && v[i].size() == 1)
			a.pb(i);

		if(a.size() == 0)	break;
		ans++;

		tr(it, a) {
			int t = *it;
			in[t] = false;
			
			forn(i, n)	 if(in[i] && (jt = v[i].find(t)) != v[i].end() )
				v[i].erase(jt);

		}

	}

//	cout << n-total << endl;
	cout << ans << endl;

	return 0;
}

