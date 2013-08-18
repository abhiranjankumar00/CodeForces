//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defence Force

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
*/

#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif

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

const int sz = 1e5 + 100;

int main()
{
	bool open[sz] = {false}, in[sz] = {false};
	bool isPrime[sz];
	CL(isPrime, -1);

	isPrime[0] = isPrime[1] = false;
	vvi factor(sz);

	for(int i = 2; i < sz; i++)	if(isPrime[i]) {
		factor[i].pb(i);
		for(int j = i+i;j < sz; j+= i) {
			factor[j].pb(i);
			isPrime[j] = false;
		}
	}

	int ass[sz];
	CL(ass, -1);

	int n, m;
	Sf("%d %d\n", &n, &m);
	int t;
	char ch;

//	cout << n << " " << m << endl;
	forn(_m, m) {
		Sf("%c %d\n", &ch, &t);
//		Pf("%c %d\n", ch, t);
//		continue;

		if(ch == '-') {
			if(open[t] == false) 
				Pf("Already off\n");
			else {
				tr(it, factor[t])
					ass[*it] = -1;
				open[t] = false;
				Pf("Success\n");
			}
		}
		else {
			if(open[t]) {
				Pf("Already on\n");
				continue;
			}
			bool flag = true;
			tr(it, factor[t]) {
				if(ass[*it] > -1) {
					Pf("Conflict with %d\n", ass[*it]);
					flag = false;
					break;
				}
			}
			if(flag) {
				open[t] = true;
				tr(it, factor[t])
					ass[*it] = t;
				Pf("Success\n");
			}
		}
	}

	return 0;
}

