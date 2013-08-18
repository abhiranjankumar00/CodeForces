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

vector <vector <ii> > G;
vi dist;
int n, m, s, l;
struct Node {
	int v, curdist, pardist;
	Node() {
		v = curdist = pardist = -1;
	}
	Node(int n, int c, int p) {
		v = n;	curdist = c;
		pardist = p;
	}
};

bool operator < (const Node &a, const Node & b) {
	return a.curdist < b.curdist;
}

int main()
{
	cin >> n >> m >> s;
	s--;
	G.resize(n);
	dist = vi(n, 123456789);
	int x, y, w;
	forn(_m, m) {
		Sf("%d %d %d", &x, &y, &w);
		x--;	y--;
		G[x].pb(mp(y, w));
		G[y].pb(mp(x, w));
	}

	cin >> l;
	if(l == 0) {
		cout << 1 << endl;
		return 0;
	}

	int ans = 0;
	dist[s] = 0;
	priority_queue <Node> pq;
	pq.push(Node(s, 0, 0));

	while(!pq.empty()) {
		Node nd = pq.top();
		pq.pop();
		if(nd.curdist > l && nd.pardist < l) {
			ans++;
			continue;
		}
		if(nd.curdist > l)	continue;
		if(nd.curdist > dist[nd.v])	continue;

		tr(it, G[nd.v]) {
			if(it->second + nd.curdist < dist[it->first]) {
				dist[it->first] = nd.curdist + it->second;
				pq.push(Node(it->first, dist[it->first], nd.curdist));
			}
		}
	}

	tr(it, dist)
		if(*it == l)
			ans++;

	forn(i, dist.size()) {
//		cout << i+1 << "-" << dist[i] << endl;
	}
	cout << ans << endl;

	return 0;
}

