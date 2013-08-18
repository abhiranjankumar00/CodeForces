//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

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
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#ifdef __cplusplus
	#undef __cplusplus
	#define __cplusplus 199712L
#endif
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl		("\n")
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair

#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

int main()
{
	int a[111] = {}, b[111] = {};
	int n, m;
	cin >> n >> m;

	forn(i, n+1)
		cin >> a[i];
	forn(i, m+1)
		cin >> b[i];

	if(n == 0 && m == 0) {
		int sign = a[0]*b[0] < 0 ? -1 : 1;
		a[0] = abs(a[0]);
		b[0] = abs(b[0]);
		int d = __gcd(a[0], b[0]);
		cout << sign*a[0]/d << "/" << b[0]/d << endl;
	}
	else if(n == 0 && m != 0) {
//		cout << (b[0] < 0 ? "-1" : "") << "Infinity" << endl;
		cout << "0/1" << endl;
	}
	else if(n != 0 && m == 0) {
		int sign = a[0] < 0 ? -1 : 1;
		cout << (sign == -1 ? "-" : "") << "Infinity" << endl;
	}
	else if(n > m) {
//		cout << a[0] << "/" << 1 << endl;
		int sign = a[0] < 0 ? -1 : 1;
		cout << (sign == -1 ? "-" : "") << "Infinity" << endl;
	}
	else if(n < m) {
		cout << "0/1" << endl;
		//int sign = b[0] < 0 ? -1 : 1;
	//	cout << (sign == -1 ? "-" : "") << "Infinity" << endl;
	}
	else {		// n == m
		int sign = a[0] * b[0] < 0 ? -1 : 1;
		a[0] = abs(a[0]);
		b[0] = abs(b[0]);
		int d= __gcd(a[0], b[0]);
		cout << sign*a[0]/d << "/" << b[0]/d << endl;
	}

	return 0;
}

