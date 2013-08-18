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
const int sz = 1e5 + 111;

bool vis[sz];
set <int> G[sz];
vi ans;
set <int> st[sz];

void dfs(int a) {
	if(vis[a])
		return ;
	vis[a] = true;
	ans.pb(a);
	tr(it, G[a])
		dfs(*it);
}

void solve() {
	int N, a, b;
	read(N);

	ans.clear();
	forab(i, 1, N) 
		vis[i] = false, G[i].clear(), st[i].clear();

	forn(i, 2*N) {
		Sf("%d %d", &a, &b);
		st[a].insert(b);
		st[b].insert(a);
	}

	forab(i, 1, N) {
		cout << i << ": ";
		tr(it, st[i])
			write(*it);
		cout << endl;
	}

	DEBUG("#1");
	forab(i, 1, N) if(st[i].size() != 4) {
		cout << -1 << endl;
		return;
	}

	forab(i, 1, N) {
		tr(it, st[i]) {
			tr(jt, st[i]) 	if(*it != *jt) {
				if(st[*it].find(*jt) != st[*it].end()) {
					//G[i].pb(*it);
					G[i].insert(*it);
				}
			}
		}
	}
	
	forab(i, 1, N) {
		Pf("%d: ", i);
		tr(it, G[i])
			write(*it);
		cout << endl;
	}

	DEBUG("#2");
	forab(i, 1, N) {
		if(G[i].size() != 2) {
			cout << i << " = " << G[i].size() << endl;
			cout << -1 << endl;
			return ;
		}
	}

	dfs(1);
	DEBUG("#3");
	if(ans.size () != N) {
		cout << -1 << endl;
		return;
	}

	tr(it, ans)
		write(*it);
	cout << endl;
}

int main()
{

	forn(ijk, 2) 
		solve();
	return 0;
}

