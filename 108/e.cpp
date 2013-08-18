//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defence Force

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
*/

#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif

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

struct Node {
	int x, y, c;
	Node() { x = y = c = -1;}
	Node(int _x, int _y)  {	x = _x, y = _y, c = -1; }
	Node(int _x, int _y, int _c)	{ x = _x, y = _y, c = _c; }
};

bool operator < (const Node &a, const Node & b) { 	return a.c > b.c; }

int N, M, K;
int flower[111][111];
bool Flower[111][111];
int ans = 1e9;
vector <ii> idx;
int X[] = { 1, -1, 0,  0};
int Y[] = { 0,  0, 1, -1};
bool in[111][111], in2[111][111];
int par[111][111][2];
int cost[111][111];

void dijkstra(int sx, int sy) {
	priority_queue <Node> pq;
	forn(n, N)	forn(m, M) {
		in2[n][m] = in[n][m];
		if(in[n][m])
			cost[n][m] = 0;
		else
			cost[n][m] = 1e9;
	}

	pq.push(Node(sx, sy, flower[sx][sy]));
	int x,y, c;

	while(!pq.empty()) {
		x = pq.top().x, y = pq.top().y, c = pq.top().c;
		pq.pop();
		if(in2[x][y])
			break;
		in2[x][y] = true;

		forn(i, 4){
			int xx = x + X[i], yy = y + Y[i];
			if(xx >= 0 && xx < N && yy >= 0 && yy < M)
				if(cost[xx][yy] > cost[x][y] + flower[xx][yy]) {
					cost[xx][yy] = cost[x][y] + flower[xx][yy];
					pq.push(Node(xx, yy, cost[xx][yy]));
				}
		}
	}

	while(true) {
		in[x][y] = true;
		int tx = par[x][y][0], ty = par[x][y][1];
		x = tx, y = ty;
		if(x == sx && y == sy)
			break;
	}
}

int main()
{
	cin >> N >> M >> K;
	forn(n, N)	forn(m, M)	read(flower[n][m]);

	idx.resize(K);
	forn(k, K) {
		read(idx[k].first);
		read(idx[k].second);
	}
	sort(all(idx));

	do {
		in[idx[0].first][idx[0].second] = true;
		cost[idx[0].first][idx[0].second] = flower[idx[0].first][idx[0].second];

	} while(next_permutation(all(idx)));

	return 0;
}

