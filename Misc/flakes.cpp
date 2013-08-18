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

//To the left of 2
//To the right of 1

int main()
{
	int n, m;
	int t;
	int l,r;
	ST st, sst;

	while(cin >> n >> m)
	{
		l = 1, r = n;
		forn(_m, m)
		{
			cin >> st >> st >> st >> sst >> t;
			if(st[0] == 'l')
				r = t-1;
			else
				l = t+1;

			
		}
//		cout << l << " - " << r << " \t ";
		if(r > n || l < 0 || r-l < 0)
			cout << -1 << endl;
		else
			cout << r-l+1 << endl;
//		cout << (r-l <0 ? -1 : r-l + 1) << endl;
	}

	return 0;
}
