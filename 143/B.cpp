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

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define	Sf		scanf
#define	Pf		printf
#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)


#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG


int main()
{
	int64 N, D, L;
	cin >> N >> D >> L;
	DEBUG(N);
	DEBUG(D);
	DEBUG(L);
	int64 even = N/2 + N%2;
	int64 odd = N/2;
	DEBUG(even);
	DEBUG(odd);
	int64 mx = even*L - odd;
	int64 mn = even - odd*L;
	DEBUG(mx);
	DEBUG(mn);

	if(D < mn || D > mx) {
		cout << -1 << endl;
		return 0;
	}

	int64 arr[111];
	int64 sum = 0;
	forn(i, N) {
		arr[i] = i% 2 == 0 ? 1 : L;
		sum += (i%2 == 0 ? 1 : -1) * arr[i];
	}
	DEBUG(sum);

	for(int i = 0; i < N && sum <D; i++) {
		if(i%2 == 0) {
			int64 add = min(L - arr[i], D - sum);
			arr[i] += add;
			sum += add;
		}
		else {
			int64 sub = min(arr[i]-1, D-sum);
			arr[i] -= sub;
			sum += sub;
		}
	}

	DEBUG(sum);
	forn(i, N)
		Pf("%lld ", arr[i]);

	return 0;
}

