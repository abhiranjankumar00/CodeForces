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

#define PF(x) printf(#x)
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

const int sz = 1e5 + 111;
int N, M;
vector <ii> G[sz], busy[sz];

int departsAt(int tm, int idx) {
	vector <ii> & busyTime = busy[idx];

	if(busyTime.empty())
		return tm;
	if(tm < busyTime.front().first || tm > busyTime.back().second)
		return tm;

	int l = 0, r = busyTime.size()-1;

	while(l < r) {
		int mid = (l+r+1)/2;
		if(busyTime[mid].first > tm)
			r = mid-1;
		else
			l = mid;
	}

	if(busyTime[l].first <= tm && busyTime[l].second >= tm)
		return busyTime[l].second+1;
	else
		return tm;

}

priority_queue <ii, vector <ii>, greater <ii> > pq;
vi dist(sz, -1);

bool insert(int tm, int planet) {

	int nextTime = departsAt(tm, planet);

	if(dist[planet] < 0 || nextTime < dist[planet]) {
		dist[planet] = nextTime;
		pq.push(mp(nextTime, planet));
		//Pf("v = %d, nextTime = %d\n", planet, nextTime);
		return true;
	}
	return false;
}

int main()
{
	cin >> N >> M;
	forab(i, 1, M) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].pb(mp(b, c));
		G[b].pb(mp(a, c));
	}

	forab(i, 1, N) {
		int K, l = -1, r = -1;
		cin >> K;

		while(K--) {
			int tmp;
			cin >> tmp;

			if(l < 0)
				l = r = tmp;
			else if(tmp - r == 1)
				r = tmp;
			else {
				busy[i].pb(mp(l, r));
				l = r = tmp;
			}
		}
		if(l >= 0)
			busy[i].pb(mp(l, r));
	}
	busy[N].clear();
 /*
	forab(i, 1, N) {
		Pf("%d: ", i);
		tr(it, G[i])
			Pf("(%d, %d) ", it->first, it->second);
		cout << endl;
	}
	cout << endl;
	forab(i,1, N) {
		cout << i <<  ": ";
		tr(it, busy[i])
			Pf("(%d, %d) ", it->first, it->second);
		cout << endl;
	}
 */

	insert(0, 1);		// insert(time, planet)
//	cout << endl;

	while(!pq.empty()) {
		int tm = pq.top().first;
		int u  = pq.top().second;

		pq.pop();

		if(u == N) {
			cout << tm << endl;
			return 0;
		}

//		if(dist[u] < tm)
//			continue;

//		Pf("u = %d, tm = %d\n", u, tm);

		tr(it, G[u]) 
			insert(it->second+tm, it->first);
//		Pf("\n");
		
	}

	cout << -1 << endl;

	return 0;
}

