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

//#define PI	3.141592653589793
//#define E	2.718281828459045
#define PI	(2*acos(0))
#define E	(exp(1))
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

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
	return a*b/gcd(a, b);
}


int main()
{
	string her = "Hermione\n", ron = "Ron\n";
	int a, b, c, d, e, f, l;

	while(cin >> a >> b >> c >> d >> e >> f)
	{

		
		if(d == 0)
		{
			cout << her;
			continue;
		}
		if(c == 0)
		{
			cout << ron;
			continue;
		}
		if(b == 0)
		{
			cout << her;
			continue;
		}
		if(a == 0)
		{
			cout << ron;
			continue;
		}
		
		if(f == 0)
		{
			cout << her ;
			continue;
		}
		if(e == 0)
		{
			cout << ron ;
			continue;
		}

		int g =gcd(a, b);
		a/= g, b /= g;

		g = gcd(c, d);
		c /= g, d /= g;

		g = gcd(e, f);
		e /= g, f /= g;
//		Pf("%d->%d %d->%d %d->%d\n", a, b, c, d, e, f);


		l = lcm(b, c);
		a *= l/b;
		d *= l/c;
		b = c = l;

//		Pf("#1 a = %d , b = %d , c = %d , d = %d , e = %d , f = %d , l = %d\n", a,b, c, d, e, f,  l);

		l = lcm(d, e);
		c *= l / d;
		a *= l/d;
		b *= l/d;
		f *= l/e;
		d = e = l;
//		Pf("#2 a = %d , b = %d , c = %d , d = %d , e = %d , f = %d , l = %d\n", a,b, c, d, e, f,  l);

//		Pf("%d->%d %d->%d %d->%d\n", a, b, c, d, e, f);

		if(f > a)
			cout << ron ;
		else
			cout << her ;
	}
	

	return 0;
}
