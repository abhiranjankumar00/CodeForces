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

int R, C;
enum {black, grey, white};
const int sz = 1600;
bool vis[sz][sz];
char G[sz][sz];

int X[] = {1, -1, 0,  0};
int Y[] = {0,  0, 1, -1};
bool isValid(int y, int x) {
	return y >= 0 && y < R && x >= 0 && x < C;
}

#define YY first
#define XX second

int main()
{
	cin >> R >> C;
	forn(i, R)
		cin >> G[i];
	int xs, ys;

	forn(i, R) {
		forn(j, C) {
//			cout << G[i][j];
			if(G[i][j] == 'S')
				ys = i, xs = j;
		}
//		cout << endl;
	}

//	DEBUG(ys);
//	DEBUG(xs);
	queue <ii> q;

	q.push(mp(ys, xs));
	vis[ys][xs] = true;

	while(!q.empty()) {
		ii nd = q.front();
		q.pop();
//		Pf("(%d, %d) -> ", nd.YY, nd.XX);

		forn(i, 4) {
			int x = (nd.XX + X[i] + C) % C;
			int y = (nd.YY + Y[i] + R) % R;
			if(isValid(y, x) && G[y][x] != '#' && !vis[y][x]) {
				vis[y][x] = true;
				q.push(mp(y, x));
			}
		}
	}
//	cout << endl;
/*
	forn(r, R) {
		forn(c, C)
			cout << vis[r][c];
		cout << endl;
	}
*/
	forn(c, C)
		if(vis[0][c] && vis[R-1][c]) {
			cout << "Yes" << endl;
			return 0;
		}

	forn(r, R)
		if(vis[r][0] && vis[r][C-1]) {
			cout << "Yes" << endl;
			return 0;
		}

	cout << "No" << endl;

	return 0;
}

