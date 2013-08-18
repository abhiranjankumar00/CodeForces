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
	int n;
	double per;

	while(cin >> n >> per)
	{
		vector <double> x(n);
		forn(i, n)
			cin >> x[i];

/*		Pf("n = %d , per = ", n);
		tr(it, x)
			cout << *it << " ";
		cout << endl;
*/
		double l = 0, mid, r = 1000, great = 0, less = 0;
		per /= 100;

		forn(_test, 400)
		{
			great = less = 0;
			mid = (l+r)/2;

			tr(it, x)
			{
				if(*it > mid)
					great += (*it - mid);
				else
					less += (mid - *it);
			}

//			Pf("l = %.5lf , r = %.5lf , mid = %.5lf , great = %.5lf , less  = %.5lf \n", l, r, mid , great, less);

			if( (great - ( great * per )) >= less)
				l = mid;
			else
				r = mid;
		}
		Pf("%0.20lf\n", mid);
	}

	return 0;
}
