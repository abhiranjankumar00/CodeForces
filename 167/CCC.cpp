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
const int sz = 1e5 + 111;

int64 ht[sz], wd[sz];

int main()
{
	int N;
	cin >> N;
	forn(i, N)
		cin >> ht[i];
	forn(i, N) {
		if(ht[i] == ht[N-1])
			wd[i] = sz;
		else
			wd[i] = lower_bound(ht, ht+N, ht[i]+1) - ht;
	}
	forab(i, N, sz-1)
		wd[i] = sz;
/*
	cout << "ht:   ";
	forn(i, N)
		Pf("%-6lld ", ht[i]);
	cout << endl;
	cout << "wd:   ";
	forn(i, N)
		Pf("%-6lld ", wd[i]);
	cout << endl;
*/

	int64 curht = ht[0];
	int id = 0;


	int M;
	int64 w, h;
	cin >> M;

	while(M--) {
		cin >> w >> h;

		if(id >= N) {
			cout << curht << endl;
			curht += h;
			continue;
		}
		if( curht < ht[id+1]) {
			if(w < wd[id]) {
				cout << curht << endl;
				curht += h;
				continue;
			}
			while(wd[id] < w) {
				id++;
				curht = ht[id];
			}
		}
		while(id < N && wd[id] < w) {
			id++;
			curht = ht[id];
		}
		cout << curht << endl;
		curht += h;
		
	}

	return 0;
}

