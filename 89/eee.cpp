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

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int)b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int) b; i>=loop_ends_here; i--)

int n, m;
bool vis[11000];
int path[11000];

bool dfs(int a, int par, int cnt, vvi &G) {
	if(vis[a]) {
		if(cnt == n && a == 1)
			return true;
		return false;
	}

	vis[a] = true;
	forn(i, G[a].size())	if(G[a][i] != par) {
		if(dfs(G[a][i], a, cnt+1, G)) {
			path[cnt] = a;
			return true;
		}
	}

	vis[a] = false;
	return false;
}

int main()
{
	cin >> n >> m;
	vvi G(n+1);
	set< pair<int, int> > edge;

	forn(i, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].pb(b);
		G[b].pb(a);
		edge.insert(mp( min(a, b), max(a, b) ));
	}

	CL(vis, 0);
	
	if(dfs(1, -1, 0, G)) {
		forn(i, n-1)
			Pf("%d %d\n", path[i], path[i+1]), 	edge.erase(mp(min(path[i], path[i+1]), max(path[i], path[i+1])));
		Pf("%d %d\n", path[n-1], 1);
		edge.erase(mp(1, path[n-1]));
		tr(it, edge)
			Pf("%d %d\n", it->first, it->second);
	}
	else
		Pf("0");

	return 0;
}

