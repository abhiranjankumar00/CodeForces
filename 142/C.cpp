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

/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

const int sz = 111;

ST table[sz];
vi ones[sz];
int N, M;

bool check() {
	forn(i, N) {
		bool allZero = true;
		forn(j, M)
			if(table[i][j] == '1') {
				allZero = false;
				ones[i].pb(j);
			}
		if(allZero == true)
			return false;
	}
	return true;
}

int minDist(int row, int idx) {
	auto it = lower_bound(all(ones[row]), idx);

	if(it != ones[row].end() && *it == idx)
		return 0;

	int right;
	if(it == ones[row].end())
		right = M - idx + ones[row].front();
	else
		right = *it - idx;

	int left;
	if(it == ones[row].begin()) 
		left = M - ones[row].back() + idx;
	else
		left = idx - *(it-1);

//	Pf("Row = %d, idx = %d, left = %d, right = %d\n", row, idx, left, right);

	return min(left, right);

}

int main()
{
	cin >> N >> M;
	forn(i, N)
		cin >> table[i];

	if(check() == false) {
		cout << -1 << endl;
		return 0;
	}

//	forn(i, N)
//		cout << table[i] << endl;
/*
	forn(i, N) {
		tr(it, ones[i])
			write(*it);
		cout << endl;
	}
*/

	int ans = 1<<29;

	forn(idx, M) {
		int sum = 0;
		forn(rows, N) {
			sum += minDist(rows, idx);
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;

	return 0;
}

