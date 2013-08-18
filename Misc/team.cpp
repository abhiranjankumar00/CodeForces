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

#define	ep	1e-9
#define	CL(a, b)	memset(a, b, sizeof(a))

#define pb	push_back
#define mp	make_pair
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0; i < n; i++)
#define forab(i, a, b)	for(int i = a; i <= b; i++)
#define rep(i, a, b)	for(int i = a; i>=b; i--)

int a[500001], b[500001][3], d[500001], e[100001];
int didx, eidx;

int main()
{
	int n, x, k;
	
	while(cin >> n)
	{
		bool found = false, valid = true;;
		didx = eidx = 0;

		forab(i, 1, 3*n)
		{
			Sf("%d", &x);
			a[x] = i;
		}

		forab(i, 1, n)
		{
			forn(j, 3)
				Sf("%d", & b[i][j]);
		}

		cin >> k;
		forab(i, 1, n)
		{
			if(!valid)	break;

			forn(j, 3)
			{
				if(found)	e[eidx++] = b[i][j];
				else		d[didx++] = b[i][j];
			}

			if(b[i][0] == k || b[i][1] == k || b[i][2] == k)
			{
				found = true;
				forn(l, 3)	if(b[i][l] < k)
					valid = false;
			}
		}

		if(!valid)
		{
			forab(i, 1, 3*n)
				if(i^k)
					Pf("%d ", i);
			cout << endl;
			continue;
		}

		sort(d, d+didx);
		sort(e, e+eidx);

		forn(j, didx) if(k^d[j])	Pf("%d ", d[j]);
		forn(j, eidx) if(k^e[j])	Pf("%d ", e[j]);
		cout << endl;
	}

	return 0;
}
