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
	int X = 1, Y = 1, w, reqW, maxX, maxY;
	w = 1;

	cin >> maxX >> maxY >> reqW;
/*
	while(w < reqW && X <= maxX && Y <= maxY)
	{

		forab(x, 1, X)
			if( (Y+1)*x == F(x, Y+1) )
			{
				cout << w+1 << " -> " <<  x << " , " << Y+1 << endl;
				w++;
			}

		Y += 1;

		if(w >= reqW)
			break;

		forab(y, 1, Y)
			if( (X+1) * y == F(y, X+1))
			{
				cout << (w+1) << " -> " <<  X +1 << " , " << y << endl;
				w++;
			}

		X += 1;

		if(w >= reqW)
			break;
	}
*/
	while(w < reqW && X <= maxX && Y <= maxY)
	{
		if( (X+1) * Y < (Y+1)* X || Y == maxY)
		{
			forab(y, 1, Y)
				if( (X+1)*y == F(X+1, y) )
					Pf("%d -> %d, %d\n", w+1, X+1, y),	 w++;
			++X;
		}
		else
		{
			forab(x, 1, X)
				if( (Y+1)* x == F(Y+1, x) )
					Pf("%d -> %d, %d\n", w+1, x, Y+1), 	w++;
			++Y;
		}


	}

	cout << endl << endl;

	if(X > maxX)
		X = maxX;
	if(Y > maxY)
		Y = maxY;

	if(w >= reqW)
		cout << X << " " << Y << endl;
	else
		cout << -1 << endl;

	return 0;
}
