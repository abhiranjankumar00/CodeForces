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

const int sz = 1e5 + 111;
int par[sz], idx[30], dist[sz];

int main()
{
	ST st;
	cin >> st;
	reverse(all(st));
	DEBUG(st);

	CL(par, -1);
	CL(dist, 0);
	CL(idx, -1);

	forn(i, st.size()) {
		int cur = st[i] - 'a';
		int p = dist[cur];

		dist[cur] = 1;
		par[i] = -1;

		forab(j, 0, cur-1) {
			if(dist[j] + 1 >= dist[cur]) {
				dist[cur] = dist[j] + 1;
				par[i] = idx[j];
			}
		}

		if(p + 1 >= dist[cur]) {
			dist[cur] = p+1;
			par[i] = idx[cur];
		}

		idx[cur] = i;

		Pf("st[%d] = %c, dist = %d, par[%d] = %d, idx[%c] = %d\n", i, cur + 'a', dist[cur],i, par[i], st[i], idx[cur]);
	}
	cout << endl << endl;
/*
	forn(i, st.size())
		Pf("st[%d] = %c, par[%d] = %d\n", i, st[i], i, par[i]);
	cout << endl;
*/
	int id = 'z' - 'a';

	rep(i, 'z' - 'a', 0) {
		if(dist[i] > dist[id])
			id = i;
	}
//	DEBUG(id);

	id = idx[id];
//	DEBUG(id);

	while(id > -1) {
		Pf("%c", st[id]);
//		Pf("st[%d] = %c, par = %d\n", id,  st[id], par[id]);
//		cout << endl;
		id = par[id];
//		DEBUG(id);
	}

	return 0;
}

