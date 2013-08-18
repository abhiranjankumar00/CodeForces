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

int main()
{
	int N, M;
	cin >> N >> M;
	string a = "", b = "";

	int r1 = N, r2 = N, b1 = M, b2 = M;

	forn(i, N+M) {
		if(r1) {
			a += 'r';
			r1--;
		}
		if(b1) {
			a += 'b';
			b1--;
		}

		if(b2) {
			b += 'b';
			b2--;
		}
		if(r2) {
			b += 'r';
			r2--;
		}
	}
	ii ans1(0, 0), ans2(0, 0);
	forab(i, 1, N+M-1) {
		if(a[i] == a[i-1])
			ans1.first++;
		else
			ans1.second++;

		if(b[i] == b[i-1])
			ans2.first++;
		else
			ans2.second++;
	}

	DEBUG(a);
	cout << ans1.first << " " << ans1.second << endl;
	cout << endl;
	DEBUG(b);
	cout << ans2.first << " " << ans2.second << endl;
	cout << endl << endl;

	if(ans1.first > ans2.first) {
		cout << ans1.first << " " << ans1.second << endl;
	}
	else if(ans1.first < ans2.first) {
		cout << ans2.first << " " << ans2.second << endl;
	}
	else
		cout << ans1.first << " " << min(ans2.second, ans1.second) << endl;


	return 0;
}

