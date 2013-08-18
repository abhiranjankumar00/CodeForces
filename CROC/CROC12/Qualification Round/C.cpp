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
// /*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
// */

int main()
{
	int N;
	int arr[1111];
	cin >> N;
	int ans = 0;

	forab(i, 1, N)
		cin >> arr[i];

	if(N == 1 || N % 2 == 0) {
		cout << -1 << endl;
		return 0;
	}

	rep(y, N, 2) {
		int x = y/2;

		int mx = arr[2*x];
		mx = max(mx, arr[2*x+1]);
		ans += mx;

		//Pf("arr[%d] = %d, mx = %d, ans = %d\n", y, arr[y],  mx, ans);

		arr[x] -= min(arr[x], mx);
		arr[2*x] = arr[2*x+1] = 0;
/*
		arr[2*x] -= min(arr[2*x], mx);
		arr[2*x+1] -= min(arr[2*x+1], mx);
*/
/*
		forab(i,1, N)
			Pf("%2d ", arr[i]);
		cout << endl;
		forab(i, 1, N)
			Pf("%2d ", i);
		cout << endl << endl;
*/
	}

	ans +=  arr[1];

	cout << ans;

	return 0;
}

