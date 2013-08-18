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

const int sz = 1e3 + 111;
int M, K;
int D[sz], S[sz];
int dist[sz][sz], fact[sz][sz];
map < ii, int> m;

int solve(int id = 1, int f = 0) {
	if(id == M+1)
		return 0;

	auto it = m.find(mp(id, f));

	if(it != m.end())
		return it->second;

	int ans = (1<<30);
	
	f += S[id];

	forab(id1, id+1, M+1) {
		int k = (dist[id][id1] - f)/S[id] + ( (dist[id][id1] - f)%S[id] == 0 ? 0 : 1);
		if(dist[id][id1] - f <= 0)
			k = 0;
		int ff = f + k*S[id] - dist[id][id1] + fact[id+1][id1-1];
//		Pf("  %d -> %d, d = %2d, f = %2d, ff = %2d, k = %2d, inDistanceTime = %2d\n", id, id1, dist[id][id1], f, ff, k, dist[id][id1] + k*K);

		ans = min(ans, dist[id][id1] + k*K + solve(id1, ff));
	}
//	Pf("--id = %d, f = %d, ans = %d\n", id, f, ans);
	return m[mp(id, f)] = ans;
}

int main()
{
	cin >> M >> K;
	forab(i, 1, M)
		cin >> D[i];
	forab(i, 1, M)
		cin >> S[i];

	forab(i, 1, M+1) {
		fact[i][i] = S[i];
		forab(j, i+1, M+1) {
			dist[i][j] = dist[i][j-1] + D[j-1];
			fact[i][j] = fact[i][j-1] + S[j];
		}
	}

	cout << solve() << endl;

	return 0;
}

