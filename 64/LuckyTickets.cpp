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

int F(int x, int y)
{
	int a = 0, b = 0;

//	cout << x << " " << y << " -> ";

	while(x > 0)
	{
		a = a*10 + x%10;
		x /= 10;
	}

	while(y > 0)
	{
		b = b*10 + y%10;
		y /= 10;
	}

//	cout << a << " " << b << endl;

	return a*b;
}

int main()
{
	int x, y, maxX, maxY, w = 0, reqW;

	cin >> maxX >> maxY >> reqW;

	for(x = 1; x <= maxX; x++)
	{
		for(y = 1; y <= maxY; y++)
		{
			if(x * y == F(x, y))
			{
				cout << x << " " << y << endl;
				w++;
			}

			if(w >= reqW)
				goto out;
		}
	}

	out:

	cout << endl << endl;

	if(w < reqW)
		cout << -1 << endl;
	else
	{
		if(x > maxX)
			cout << maxX ;
		else
			cout << x;
		cout << " ";
		if(y > maxY)
			cout << maxY;
		else
			cout << y << endl;
	}


	return 0;
}
