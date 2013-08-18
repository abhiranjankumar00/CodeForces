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

const int sz = 1e4 + 10;
int64 a[sz], b[sz], c, n;

int64 check(int64 x) {
	int64 cnt = 0;

	forn(i, n) {
		cnt += 1 + (a[i]*x)/b[i];
	}

	return cnt ;
}

int main()
{
	cin >> n >> c;

	forn(i, n) 
		cin >> a[i] >> b[i];

	int64 l = -1, r = -1;
	int64 ret = 0ll;
/*
	forn(i, 1111) {
		if(check(i)) {
			if(l == -1)
				l = i;
			r = i;
			ret++;
		}
	}
*/
	int64 low = 0, high = (long long)3e15 + 10;

	while(low < high) {
		int64 mid = (low + high )/2;
//		Pf("(%lld, %lld) = %lld\n", low, high,mid);
		if(check(mid) >= c)
			high = mid;
		else
			low = mid+1;
	}
	//cout << low << endl;
	l = low;

	low = 0, high = (long long)3e15 + 10;
	while(low < high) {
		int64 mid = (low + 1 +  high )/2;
//		Pf("(%lld, %lld) = %lld\n", low, high,mid);
		if(check(mid) > c)
			high = mid-1;
		else
			low= mid;
	}
	//cout << low << endl;
	//
	cout << high - low + 1 << endl;

//	Pf("l = %lld, r = %lld, cnt = %lld", l, r, ret);
	return 0;
}

