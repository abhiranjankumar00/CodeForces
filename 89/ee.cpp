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
#define read(a)		scanf("%d", &(a))

bool vis[11000];
int path[11000];
int n, m;

bool dfs(int a , int cnt , const vvi &G, int par ) {
	if(a!= 1 && vis[a] == true)
		return false;
/*
	Pf("a = %d, vis[%d] = %d, cnt = %d, n = %d\n", a, a, vis[a], cnt, n);
	forn(i, cnt)
		Pf("(%d, %d) -> ", path[i], vis[i]);
	cout << a << endl;
*/
	if(a == 1  && cnt == n) {
/*		cout << "Path found: ";
		forn(i, cnt)
			Pf("%d ", path[i]);
		cout << endl;
*/
		forn(i, cnt-1)
			Pf("%d %d\n", path[i], path[i+1]);
		Pf("%d 1\n", path[cnt-1]);

		return true;
	}

	vis[a] = true;
	path[cnt] = a;
	
	tr(it, G[a])	if(*it != par) {
		if(dfs(*it, cnt+1, G, a))
			return true;
	}

	vis[a] = false;
	return false;
}

int main()
{
	cin >> n >> m;
	vvi G(n+1);
	CL(vis, 0);

	forn(i, m) {
		int a, b;
		read(a),	read(b);
		G[a].pb(b),	G[b].pb(a);
	}
/*
	forn(i, G.size()) {
		cout <<  i << " -> " ;
		tr(it, G[i])
			cout << *it << " ";
		cout << endl;
	}
*/
	if(!dfs(1, 0, G, -1))
		cout << 0 << endl;


	return 0;
}

