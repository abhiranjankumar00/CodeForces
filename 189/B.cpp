//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>	// Don't know why it is here.
#include <numeric>		// +1
#include <cassert>
#include <utility>		// +1
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 				int64;
typedef vector<int> 			vi;
typedef string 					ST;		// Never used it :X
typedef stringstream 			SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 			ii;
typedef vector<string> 			vs;

// WHY YOU DON'T WORK :X
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater than 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

#define tr(i, c)		for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)	// \m/ Defined 3rd time.
#define forn(i, n)		for(int i = 0, __even_my_fish_codes_better__ = (int)n; i <  __even_my_fish_codes_better__; i++)
#define forab(i, a, b)	for(int i = a, __even_my_fish_codes_better__ = (int)b; i <= __even_my_fish_codes_better__; i++)
#define rep(i, a, b)	for(int i = a, __even_my_fish_codes_better__ = (int)b; i >= __even_my_fish_codes_better__; i--)

#define PI				M_PI		// Fish!!! Fails on some compilers (probably MSVC++ & some GNU C++).
#define E 				M_E			// Fish!!! Fails on some compilers (probably MSVC++ & some GNU C++).
#define endl			("\n")		// Really required?

#define	all(c)			(c).begin(), (c).end()
#define	cl(a, b)		memset(a, b, sizeof(a))
#define mp				make_pair
#define pb				push_back

#define	Sf				scanf
#define	Pf				printf
#define read(n)			scanf("%d", &n)
#define write(n)		printf("%d ", (int)n)
#define writeln(n)		printf("%d\n", (int)n)

#if (0 or defined ONLINE_JUDGE)		// Why topcoder doesn't use it. :(
	#define	debug
#else 
	#define debug(x)	cout << #x << " = " << x << "\n"
#endif

bool check(const vector <int> &arr) {
	int N = arr.size();
	for(int i = 0; i < N-1; ++i) {
		if(arr[i] > arr[i+1])
			return false;
	}
	return true;
}

bool stepKill(int kill, const vector <int> &arr) {
	vector <int> tmp = {arr[0]};
	int N = arr.size();
	int mx = arr[0];
	int curKill = 0;

	for(int i = 1; i <= N-1; ++i) {
		if(arr[i-1] > arr[i])
			continue;
		if(arr[i] > mx) {
			printf("In arr[%d] = %d\n", i, arr[i]);
			mx = arr[i];
			tmp.push_back(arr[i]);
			curKill = 0;
			continue;
		}
		curKill++;
		printf("arr[%d] = %d, curKill = %d\n", i, arr[i], curKill);
		if(curKill > kill) {
			mx = arr[i];
			tmp.push_back(arr[i]);
			curKill = 0;
		}
	}
	cout << endl;
	bool ret = check(tmp);

	if(ret || true) {
		printf("kill = %d: ", kill);
		for(auto it = begin(tmp); it != end(tmp); ++it) {
			 printf("%d ", *it);
		}
		cout << "\n";
	}

	return ret;
}

int main()
{
	int N;
	cin >> N;

	vector <int> arr(N);
	for(int i = 0; i < N; ++i) {
		cin >> arr[i];
		printf("%d ", arr[i]);
	}
	cout << "\n" << "\n";
	
	if(check(arr)) {
		cout << 0 << "\n";
		return 0;
	}

	for(int kill = 0; kill <= N; ++kill) {
		stepKill(kill, arr);
	}

	return 0;
}

