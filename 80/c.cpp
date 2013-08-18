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
typedef string ST;
typedef stringstream SS;
typedef vector< vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<string> vs;

#define Pf	printf
#define	Sf	scanf

#define PI M_PI
#define E M_E
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

int circle, n, m ;
int vis[110] ={0};
bool g[110][110] = {false};

void dfs(int idx, int par)  {
	if(vis[idx] == 2)
		circle++;

	if(circle >2){
		cout << "NO\n";
		exit(0);
	}

	if(vis[idx])
		return;

	vis[idx] = 2;

	forab(i, 1, n)	if(i != par)
		if(g[idx][i])
			dfs(i, idx);
	vis[idx] = 1;
}

int main()
{
	int x, y;
	circle = 0;

	cin >> n >> m;

	forab(i, 1, m)
		Sf("%d %d", &x, &y),	g[x][y] = g[y][x] = true;

	dfs(1, -1);

	forab(i, 1, n)
		if(!vis[i])
			Pf("NO\n"),	exit(0);;

	if(circle == 1)
		cout << "FHTAGN!\n";
	else
		cout << "NO\n";

	return 0;
}
