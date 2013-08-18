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
#define	ep		1e-9

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define	Sf		scanf
#define	Pf		printf
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
vector < ii > G[sz], neighbours[sz];
vi dist(sz, -1);
int N;

int findTime(int planet, int startTime) {
	int r = neighbours[planet].size()-1;
	if(r == -1)
		return 0;
	if(r > neighbours[planet].back().second)
		return 0;

	if(startTime < neighbours[planet][0].first)
		return 0;

	int l = 0;

	while(l < r) {
		int mid = (l+r+1)/2;
		if(neighbours[planet][mid].first > startTime)
			r = mid-1;
		else
			l = mid;
	}
	if(startTime >= neighbours[planet][l].first && startTime <= neighbours[planet][l].second)
		return neighbours[planet][l].second - startTime + 1;
	else
		return 0;
}

int main()
{
	int M;
	read(N);
	read(M);
	forn(i, M) {
		int a, b, c;
		read(a);
		read(b);
		read(c);
		G[a].pb(mp(b, c));
		G[b].pb(mp(a, c));
	}
/*
	forab(i, 1, N) {
		cout << i << ": " ;
		tr(it, G[i])
			Pf("(%d, %d), ", it->first, it->second);
		cout << endl;
	}
*/
	forab(i, 1, N) {
		int K;
		read(K);
		int l = -1, r = -1;
		while(K--) {
			int tmp;
			read(tmp);

			if(l == -1) 
				l = r = tmp;
			else if(tmp - r == 1)
				r++;
			else {
				neighbours[i].pb(mp(l, r));
				l = r = tmp;
			}
		}
		if(l != -1)
			neighbours[i].pb(mp(l, r));
	}
	/*
	forab(i, 1, N) { //if(i == N){
		cout << i << ": " ;
		tr(it, neighbours[i])
			Pf("(%d, %d) ", it->first, it->second);
		cout << endl;
	}
	cout << endl;
*/ 

	priority_queue <ii, vector <ii >, greater <ii> > pq;
	pq.push(mp( 0, N));

	while(!pq.empty()) {
		int tm = pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if(dist[v] > -1)
			continue;

		dist[v] = tm;
		int add = findTime(v, tm);
		dist[v] += add;
		//int add = findTime(v, tm+1);

//		Pf("u = %d, time = %d\n", v, tm);

		if(v == 1) {
			cout << dist[v] << endl;
			return 0;
		}

		tr(it, G[v]) {
			if(dist[it->first] < 0) {
//				Pf("u = %d, v = %d, add = %d, time = %d\n", v, it->first, add,tm+ add + it->second);
				pq.push(mp(tm+ add + it->second, it->first));
			}
		}
		//cout << endl;

	}

	cout << -1 << endl;

	return 0;
}

