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

#define sz 202
bool m[sz], vis[sz], present[sz], g[sz][sz];
int a[sz];

void dfs(int n, vi & v) {
	if(vis[n])	return ;
	vis[n] = true;

	v.pb(n);

	forn(i, sz)	if(present[i])	if(!vis[i])	if(g[i][n])
		dfs(i, v);
}

void Print() {
	cout << "   ";
	forn(i, sz)	if(present[i])
		cout << i << " " ;
	cout << endl;

	forn(i, sz)	if(present[i]){
		cout << i << ": ";
		forn(j, sz)	if(present[j])
			cout << g[i][j] << " ";
		cout << endl;
	}

	cout << endl << endl;
}

int main()
{
	forn(i, sz)	forn(j, sz)
		g[i][j] = true;

	int n, k;

	cin >> n;

	forn(_n, n*(n-1)/2) {
		cin >> k;
		CL(m, 0);

		forn(_k, k){
			Sf("%d", &a[_k]);
			m[a[_k]] =   present[a[_k]] = true;
		}

		if(k == 2) {
			forn(j, 2) {
				int t = a[j];
				forn(i, sz)
					g[i][t] = g[t][i] = false;
				g[t][t] = true;
			}
			continue;
		}

		forn(i, sz)	if(m[i])
			forn(j, sz)	if(!m[j])
				g[i][j] = g[j][i] = false;

//		Print();

	}

//	Print();
	CL(vis, 0);

		vvi v;
		forn(i, sz)	if(present[i])	if(!vis[i])
		{
			vi t;
			dfs(i, t);
			v.pb(t);
		}

		//cout << v.size() << endl;

		tr(it, v)
		{
			cout << it->size() << " ";
			tr(jt, *it)
				cout << *jt << " ";
			cout << endl;
		}



	return 0;
}
