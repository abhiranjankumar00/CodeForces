//%%%%%%%%%%%%
//%%%%lost%%%%
//%%%%%%%%%%%%

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

typedef long long  int64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef string ST;
typedef stringstream SS;

#define Pf	printf
#define	Sf	scanf

#define PI	3.141592653589793
#define E	2.718281828459045
#define	ep	1e-9

#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp	make_pair

#define pb	push_back
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0; i < n; i++)
#define forab(i, a, b)	for(int i = a; i <= b; i++)
#define rep(i, a, b)	for(int i = a; i>=b; i--)

char g[15][15][15];
int vis[15][15][15];

int a[] = {-1, 1,  0, 0,  0, 0};
int b[] = { 0, 0, -1, 1,  0, 0};
int c[] = { 0, 0,  0, 0, -1, 1 };

int dfs(int l, int x, int y)
{
	if(vis[l][x][y] == 1)	return 0;
	vis[l][x][y] = 1;

	if(g[l][x][y] == -1)	return 0;

	if(g[l][x][y] == '#')	return 0;

	int ans = 1;

	forn(i, 6)
		ans += dfs(l+a[i], x + b[i], y + c[i]);

	return ans;


}

int main()
{
	int k, n, m, x, y;

	cin >> k >> n >> m;
	CL(g, -1);

	forab(_k, 1, k)		forab(_n, 1,  n)	forab(_m, 1, m)		cin >> g[_k][_n][_m];

	cin >> x >> y;

	cout << dfs(1, x, y);
	

	return 0;
}
