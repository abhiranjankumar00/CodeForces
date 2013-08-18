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

int idx[(int)1e6 + 111];

int main()
{
	int N, K;
	cin >> N >> K;

	if(N < 3*K) {
		cout << -1 << endl;
		return 0;
	}

	if(K % 2 == 0) {
		int id = 0;
		for(; id < 3*K; id++)
			if(id % 3 == 2 && id % 2 == 0)
				idx[id] = (id+1)/3;
			else if(id % 3 == 0 && id % 6 == 3)
				idx[id] = (id-1)/3;
			else
				idx[id] = id/3;
		while(id < N)
			idx[id++] = 0;
		forn(i, N)
			write(idx[i]+1);
		return 0;
	}
	idx[0] = idx[1] = idx[4] = 0;
	idx[2] = idx[3] = idx[6] = 1;
	idx[5] = idx[7] = idx[8] = 2;

	int id = 9;
	for(; id < 3*K; id++)
		if(id % 3 == 2 && id % 2 == 1)
			idx[id] = (id+1)/3;
		else if(id % 3 == 0 && id % 2 == 0)
			idx[id] = (id-1)/3;
		else 
			idx[id] = id/3;
	while(id < N)
		idx[id++] = 0;
	forn(i, N)
		write(idx[i] + 1);

	return 0;
}

