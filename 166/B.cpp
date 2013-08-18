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
#define	eps		1e-9

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
const int sz = 1e5 + 10;

vi primes;
bool isPrime[sz];

int main()
{
	CL(isPrime, -1);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i < sz; i++)	if(isPrime[i]) {
		for(int j = 2*i; j < sz; j+=i)
			isPrime[j] = false;
		primes.pb(i);
	}
	cout << primes.size() << endl;

	int diff;
	for(int i = 1; primes[i] < 1e5; i++)
		diff = max(diff, primes[i] - primes[i-1]);
	cout << diff << endl;

	int arr[555][555];
	int N, M;
	cin >> N >> M;
	forn(i, N)
		forn(j, M) {
			int tmp;
			cin >> tmp;

			arr[i][j] = *lower_bound(all(primes), tmp) - tmp;
		}

	int ans = 1e8;
	forn(i, N) {
		int tmp = 0;
		forn(j, M)
			tmp += arr[i][j];
		ans = min(ans, tmp);
	}
	forn(j, M) {
		int tmp = 0;
		forn(i, N)
			tmp += arr[i][j];
		ans = min(ans, tmp);
	}
	cout << ans << endl;



	return 0;
}

