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

const int sz = 1e6;
int arr[sz];
map <int, vi> m;
int N, M, K;

int main()
{
	int tmp;
	int ans = 1;
	cin >> N >> M >> K;

	forn(i, N) {
		cin >> tmp;
		m[tmp].pb(i);
	}


	for(auto &x: m) {
/*
		cout << x.first << ": ";
		for(auto &y: x.second)
			cout << y << " ";
		cout << endl;
*/
		vi &v = x.second;
		int cnt = 1;
		int l = 0, r = 0, n = v.size(), k = K;

		while(l+1 < n) {
			while(r+1 < n && v[r+1] - v[r] -1 <= k) {
//				Pf("r+1 = %d, n = %d, v[r+1] = %d, v[r] = %d, k = %d\n", r+1, n, v[r+1], v[r], k);
				k -= v[r+1] - v[r] - 1;
				cnt++;
				ans = max(ans, cnt);
				r++;
			}
//			Pf("l = %d, r = %d, k = %d, cnt = %d, ans = %d\n", l, r, k, cnt, ans);
			ans = max(ans, cnt);
			k += v[l+1] - v[l] - 1;
			cnt--;
			l++;
		}
//		cout << endl;
//		ans = max(ans, cnt);
	} 
//	cout << endl;
	
	cout << ans << endl;
	
	return 0;
}

