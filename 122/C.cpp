//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

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
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

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

char G[55][55];
int N, M;
bool vis[55][55];

void show() {
	forn(i, N)	cout << G[i] << endl;	cout << endl;
}

bool valid(int i , int j) {
	return i >= 0 && i < N && j >= 0 && j < M;
}

int X[] = {0, 0, -1, 1};
int Y[] = {1, -1, 0, 0};

void dfs(int u, int v) {
	if(!valid(u, v))
		return ;

	if(G[u][v] == '.')
		return;

	if(vis[u][v] == true)
		return;

	vis[u][v] = true;

	forn(j, 4)
		dfs(u+X[j], v + Y[j]);
}

int main()
{
	cin >> N >> M;
	forn(i, N)
		cin >> G[i];

//	show();

	int cnt = 0;

	vector <ii> pts;
	forn(i, N)	forn(j, M)	if(G[i][j] == '#')	pts.pb(mp(i, j));

	forn(i, N)	forn(j, M)	cnt += G[i][j] == '#' ? 1 : 0;
	if(cnt <= 2) {
		cout << -1 << endl;
		return  0;
	}
	if(cnt == 3){
		cout << 1 << endl;
		return 0;
	}
	forn(i, N) {

		forn(j, M) { 	

			if(G[i][j] == '#'){
				CL(vis, 0);
				vis[i][j] = true;
				
				if(mp(i, j) == pts[0])
					dfs(pts[1].first, pts[1].second);
				else
					dfs(pts[0].first, pts[0].second);

				bool disConnected = false;

				forn(l, N)	forn(m, M)	if(G[l][m] == '#' && vis[l][m] == false)	disConnected = true;


				if(disConnected) {
					cout << 1 << endl;
					return 0;
				}
			}
		}
	}

	cout << 2 << endl;

	return 0;
}

