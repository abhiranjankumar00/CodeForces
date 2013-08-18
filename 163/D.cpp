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

const int sz = 201;
const int inf = 1e8;

int D[sz][sz];
int deg[sz];

int main()
{
	int N, M;
	cin >> N >> M;

	forab(i, 1, N)
		forab(j, 1, N) {
			if(i == j)
				D[i][j] = 0;
			else
				D[i][j] = inf;
		}

	forn(i, M) {
		int x, y, d;
		cin >> x >> y >> d;
		deg[x]++;
		deg[y]++;
		D[x][y] = D[y][x] = d;
	}
/*
	forab(i, 1, N) {
		forab(j, 1, N)
			write(D[i][j]);
		cout << endl;
	}
	cout << endl;
*/
	forab(k, 1, N)
		forab(i, 1, N)
			forab(j, 1, N)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
	int ans = 0;
/*
	forab(i, 1, N) {
		forab(j, 1, N)
			write(D[i][j]);
		cout << endl;
	}
	cout << endl;
*/
	forab(i, 1, N) {
		int mx1 = 0, mx2 = 0;
		forab(j, 1, N) {
			if(D[i][j] >= mx1) {
				mx2 = mx1;
				mx1 = D[i][j];
			}
			else if(D[i][j] >= mx2)
				mx2 = D[i][j];
		}
		if(deg[i] == 1)
			ans = max(ans, mx1);
		else
			ans = max(ans, mx1+mx2);
	}
	if(ans % 2 == 0)
		cout << ans/2 << endl;
	else
		cout << ans/2 << ".5" << endl;


	return 0;
}

