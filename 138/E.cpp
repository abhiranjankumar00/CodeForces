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
#define read(n)		scanf("%lld", &n)
#define write(n)	printf("%lld ", n)
#define writeln(n)	printf("%d\n", n)

// /*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
// */

const int sz = 2010;
const int64 mod = (int64)1e9 + 7;

int64 _pow(int64 a, int64 n) {
	if(n == 0)
		return 1ll;
	a %= mod;
	int64 tmp = _pow(a, n/2);
	tmp = (tmp*tmp) % mod;
	if(n % 2 == 1ll)
		tmp = (a*tmp) % mod;

	while(tmp < 0)
		tmp += mod;

	return tmp;
}

int64 inv(int64 n) {
	return _pow(n, mod-2);
}

int64 dp[sz];

int64 readInt() {
	char ch;
	while((ch = getchar() ) < '0' || ch > '9');
	int64 ret = ch - '0';

	while((ch = getchar()) >= '0' && ch <= '9')
		ret = ret * 10 + ch - '0';
	return ret;
}

int main()
{
	DEBUG(mod);

	int N;
        int64 K;
	int64 a[sz];
	N = readInt();
	K = readInt();
//	cin >> N >> K;

	dp[0] = 1;
	forab(j, 1, sz-5) {
		dp[j] = (dp[j-1]*(j+K-1)) % mod;
		while(dp[j] < 0)
			dp[j] += mod;
		dp[j] = (dp[j] * inv(j)) % mod;
		while(dp[j] < 0)
			dp[j] += mod;
//		dp[j] = dp[j-1] * (j+K-1)/j;
	}
/*
	forn(i, 10)
		write(dp[i]);
	cout << endl;
*/
	forn(i, N)
		a[i] = readInt();
//		cin >> a[i];

	char ans[2000*13] = {0};
	char *ptr = ans;
	forn(i, N) {
		int64 cur = 0;
		int k = 0;

		forn(k, i+1) {
			cur += (dp[k]*a[i-k])%mod;
			cur %= mod;
		}

		ptr += sprintf(ptr, "%d ", (int)cur);
//		cout << cur << " ";
	}
	Pf("%s", ans);

	return 0;
}

