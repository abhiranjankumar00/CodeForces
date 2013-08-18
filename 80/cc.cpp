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

int n, m, g[110][110], par[110];

int find(int x) {
	return x == par[x] ? x : ( par[x] = find(par[x]) );
}

void merge(int x, int y) {
	int px = find(x), py = find(y);
	par[px] = par[py] = min(px, py);
}

int main()
{
	int x, y, circle = 0;
	cin >> n >> m;

	forn(i, 110)	par[i] = i;

	forn(_x, m) {
		Sf("%d %d", &x, &y);
		if(find(x) == find (y))
			circle++;
		merge(x, y);
	}
/*
	Pf("circle = %d\nParents : \n",circle);
	forab(i, 1, n)
		Pf("%d: %d\n", i, find(i));
	cout << endl;
*/

	if(circle != 1) {
		cout << "NO\n";
		exit(0);
	}
	forab(i, 1, n)
		if(find(i) != 1)
			cout << "NO\n",		exit(0);
	cout << "FHTAGN!\n";

	return 0;
}

