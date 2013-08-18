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

#define Max 10000000000LL
string name[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
int64 a[1000], sz;

void Process(int64 n)
{
	int64 m, idx;

	idx = lower_bound(a, a+sz, n) - a;
/*	if(a[idx] == n){
		cout << 0 << " \t " << name[0] << endl;
//		cout << name[0] << endl;
		return ;
	}
*/	
	idx--;
	m  = n-1-a[idx];
	int64 diff = 1;
	forn(i, idx)
		diff *= 2;

	cout << name[m/diff] << endl;
//	cout << (m/diff) << " \t " << name[(m/diff)] << endl;
}

int main()
{
	a[0] = 0;
	a[1] = 5;
	sz = 2;

	forab(i, 2, 1000)
	{
		if(a[i-1] > Max)
		{
			sz = i-1;
			break;
		}
		a[i] = a[i-1] + (a[i-1] - a[i-2])*2;
	}

	int64 t;
	cin >> t ;
	Process(t);

//	cout << sz << endl << endl;
/*
	forn(i, sz)
		cout << a[i] << endl;
*/
/*

	forn(i, 5)
		cout << name[i] << endl << endl;

	ST st = "01234";

	forn(i, 200)
		st = st+  st[i] + st[i];

	cout << endl << st << endl;

	forn(i, 100) {
		cout << st[i] << " : " ;
		Process(i+1);
		cout << endl;
	}
*/
/*
	forn(i, 1000)
		printf("%d : %c \t ", i, st[i]);
	cout << endl;

	cout << endl << "0 : " << endl;
	forn(i, 1000)
		if(st[i] == '0')
			cout << i << ", ";
*/
	return 0;
}
