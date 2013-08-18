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
typedef vector<vi> vvi;
typedef vector<ST> vs;
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

int main()
{
	/*
	int p1, p2, p3, p4, a, b;
	vi p(4);

//	while(cin >> p1 >> p2 >> p3 >> p4 >> a >> b)
	while(cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b)
	{
		vvi x (4) ;
		int idx =0;
		map <int, int> m;

		sort(all(p));
		do {
			forn(i, 4)
				x[idx].pb(p[i]);
			idx++;
		} while(next_permutation(all(p)));

		forn(i, 4)
		{
			tr(it, x[i])
				cout << *it << " \t ";
			cout << endl;
		}

	}
*/
/*
	vi x(4);
	int a, b;

	while(cin >> x[0] >> x[1] >> x[2] >> x[3] >> a >> b)
	{
		vvi p(24);
		sort(all(x));

		tr(it, x)
			cout << *it << " ";
		cout << endl;

		int idx = 0;

		do {
			tr(it, x)
				p[idx].pb(*it);

			idx++;
		}while( next_permutation(all(x))  ) ;

		int ret = 0;

		tr(it, p)
		{
			tr(jt, *it)
			{

				cout << *jt << " ";
			}
			cout << endl;

			//if()
		}
*/
		/*
		b = min(b, *min_element(all(p)) );
		forab(i, a, b)
		{
			int t = i, cnt = 0;
		//	tr(it, p)
			forn(i, 24)
			{
				t = i;
				forn(j, 4)
				{
					t = t%p[i][j];
				}
				Pf("i = %d  t = %d  \t  prime = {%d, %d, %d, %d}\n", i, t, p[i][0], p[i][1], p[i][2], p[i][3]);
				if(i==t)
					cnt++;
			}
			if(cnt >= 7)
			{
				ret++;
				break;
			}

		}

		cout << ret << endl;
	}
*/
	vi x(4);
	int a, b;

	while(cin >> x[0]>> x[1] >> x[2] >> x[3] >> a >> b)
	{
		b = min(b, *min_element(all(x)));

		vvi p;

		sort(all(x));

		do {
			p.pb(vi());
			int idx = SZ(p) -1;

			tr(it, x)
				p[idx].pb(*it);

		} while ( next_permutation(all(x)) ) ;
/*
		tr(it, p)
		{
			tr(jt, *it)
				cout << *jt << " ";
			cout << endl;
		}

		cout << SZ(p) << endl;
*/
		int ret = 0;

		forab(i, a, b)
		{
			int f , cnt = 0;

			forn(k, SZ(p))
			{
				f = i;
				forn(j, SZ(p[k]))
				{
					f = f % p[k][j];
				}

				if(f == i)
					cnt++;
			}

//			Pf("i = %d  , cnt == %d\n  ", i, cnt);
			if(cnt >= 7)
				ret++;
		}
		cout << ret << endl;
	}

	return 0;
}
