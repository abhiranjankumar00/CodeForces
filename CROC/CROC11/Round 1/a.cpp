//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
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

#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

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

ST a, b;
int ans1 = 0, ans2 = 0;
int n, l;

inline char charAt(int i, ST & st) {
	return st[i % st.size()];
}

void f(char a, char b) {
	if(a == b)
		return;

	if(a == 'R') {
		if(b == 'S')
			ans1++;
		else
			ans2++;
	}
	else if(a == 'S') {
		if(b == 'P')
			ans1++;
		else
			ans2++;
	}
	else if(a == 'P') {
		if(b == 'R')
			ans1++;
		else
			ans2++;
	}
	else
		assert(0);
}

int main()
{
	cin >> n >> a >> b;
	l = (a.size() / __gcd(a.size(), b.size())) * b.size();

	forn(i, l) {
		f(charAt(i, a), charAt(i, b));

	}

	ans1 *= (n/l);
	ans2 *= (n/l);
	
//	cout << ans1 << " " << ans2 << endl;

	forn(i, n%l) {
		f(charAt(i, a), charAt(i, b));
//		Pf("i = %d, a[i] = %c, b[i] = %c, ans1 = %d, ans2 = %d\n", i, charAt(i, a), charAt(i, b), ans1, ans2);
	}

	cout << ans2 << " " << ans1 << endl;

	return 0;
}

