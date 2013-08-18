//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
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

#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

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

int n, m;
const int sz = 1e6 + 10;
bool in [sz];
int dist[sz];
vvi G(sz);

inline int idx(int y, int x) {
	return y*m + x;
}

int main()
{
	cin >> n >> m;
	vs g(n);
	CL(in, 0);
	CL(dist, 0x3f);

	forn(i, n)
		cin >> g[i];

	queue <int> q;
	int ans = -1;

	forn(i, n) 	forn(j, m)	if(g[i][j] == '#'){
		if(i == 0) {
			dist[j] = 1;
			in[j] = true;
			q.push(j);
		}

		forab(k, j+1, m-1)	if(g[i][k] == '#') {
			G[idx(i, k)].pb(idx(i, j));
			G[idx(i, j)].pb(idx(i, k));
		}

		forab(k, i+1, n-1)	if(g[k][j] == '#') {
			G[idx(k, j)].pb(idx(i, j));
			G[idx(i, j)].pb(idx(k, j));
		}
	}

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		if(u >= (n-1)*m) {
			ans = dist[u];
			break;
		}

		for(auto &x: G[u]) 	if(!in[x]){
			in[x] = true;
			dist[x] = dist[u] + 1;
			q.push(x);
		}
	}
/*
	forn(i, n) {
		forn(j, m)
			cout << dist[idx(i, j)] << " ";
		cout << endl;
	}
*/
	cout << ans << endl;
	
	return 0;
}

