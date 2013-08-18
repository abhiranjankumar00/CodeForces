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

// /*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
// */

ST G[16];
int mx, N, M, appleIsAt;
vi pos;

void extractPosition() {
	forn(i, N) forn(j, M) if(isdigit(G[i][j])) {
		pos[G[i][j] - '0'] = i*M + j;
	}
}

bool createNextPath(const vi &v, int xadd, int yadd, vi &ret) {
	rep(i, v.size()-2, 1)
		ret[i+1] = v[i];

	int x = v[1]%M + xadd;
	int y = v[1]/M + yadd;

	if(x < 0 || y < 0 || x >= M || y >= N)
		return false;

	if(G[y][x] == '#')
		return false;

	ret[1] = y*M + x;

	forab(i, 2, v.size()-1)
		if(ret[i] == ret[1])
			return false;

	return true;
}

int main()
{
	cin >> N >> M;

	forn(i, N)
		cin >> G[i];
	forn(i, N)
		DEBUG(G[i]);

	mx = 0;
	forn(i, N)
		forn(j, M) {
			if(isdigit(G[i][j]))
				mx = max(mx, G[i][j]-'0');
			if(G[i][j] == '@')
				appleIsAt = i*M+j;
		}
	
	DEBUG("#1");
	DEBUG(appleIsAt);
	pos.resize(mx+1, -1);
	extractPosition();

	DEBUG("#2");
	map <vi, int> dist;
	queue <vi> q;
	vi nextPath(mx+1);
	q.push(pos);
	dist[pos] = 0;
	DEBUG("#3");

	while(! q.empty()) {
		vi cur = q.front();
		q.pop();
		int d = dist[cur];
		DEBUG("#4");
		
/*		cout << d << ": ";
		forab(i, 1, cur.size()-1) {
			write(cur[i]);
		}
		cout << endl;
*/

		if(cur[1] == appleIsAt) {
			cout << d << endl;
			return 0;
		}

		static int X[] = {1, -1, 0, 0};
		static int Y[] = {0, 0, -1, 1};

		forn(i, 4) {
			if(!createNextPath(cur, X[i], Y[i], nextPath))
				continue;
			if(dist.find(nextPath) != dist.end())
				continue;
			dist[nextPath] = d+1;
			q.push(nextPath);

		}

		DEBUG("#5");
	}
	DEBUG("#6");
	cout << -1 << endl;

	return 0;


}

