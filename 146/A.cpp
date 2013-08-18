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
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

const int sz = 1e6 + 100;
int fact[sz];

int64 lcm(int64 a, int64 b, int64 c) {
	int64 l1 = a*b / __gcd(a, b);
	return l1*c / __gcd(c, l1);
}

int main()
{
	forn(i, sz)	fact[i] = i;
	for(int i = 2; i < sz; i++)	if(fact[i] == i) 
		for(int j = i+i; j < sz; j+=i)
			fact[j] = i;

	int N;

	cin >> N;

	if(N ==1) {
		cout << 1 << endl;
		return 0;
	}
	if(N == 2) {
		cout << 2 << endl;
		return 0;
	}
	if(N == 3) {
		cout << 6 << endl;
		return 0;
	}

	DEBUG("#1");
	int64 a = -1, b = -1, c = 1;
	rep(i, N, 1) {
		int t = i;

		while(t % fact[i] == 0)
			t /= fact[i];

		if(t != 1)
			continue;
		
		if(a == -1)
			a = i;
		else if(b == -1)
			b = i;
		else
			break;
	}

	DEBUG("#2");
	forab(i, 1, N) {
		int t = i;
		while(t % fact[a] == 0)
			t /= fact[a];
		while(t % fact[b] == 0)
			t /= fact[b];
	
		if(t > c)
			c = t;
	}
	DEBUG("#3");
	DEBUG(a);
	DEBUG(b);
	DEBUG(c);
	cout << lcm(a, b, c) << endl;

	return 0;
}

