//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

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
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

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

int64 ht = 0;
vector <pair <int64, int>> idx1, idx2;
int c1 = -1, c2 = -1, id1 = -1, id2 = -1;

void cal(int a, vector <pair <int64, int> > &v1, int b, vector <pair <int64, int> > &v2) {
	if(a < 0 || b < 0 || a >= v1.size() || b >= v2.size())
		return;

	if(v1[a].second == v2[b].second)
		return;

	if(v1[a].first + v2[b].first < ht)
		return;

	ht = v1[a].first + v2[b].first;
	id1 = a;	id2 = b;
	c1 = v1[a].second;	c2 = v2[b].second;
}

int main()
{
	int n;
	read(n);
	map <int, vector<pair<int64, int> > > m;

	forab(i, 1, n) {
		int c, s;
		Sf("%d %d", &c, &s);

		m[c].pb(mp(s, i));
	}

	for(auto &x : m) {
		vector <pair<int64, int>> &v = x.second;
		sort(all(v), greater<pair<int64, int>>());

		forn(i, v.size()) {
			if(i > 0)
				v[i].first += v[i-1].first;

			if(i == idx1.size())
				idx1.pb(v[i]);
			else if(i == idx2.size())
				idx2.pb(v[i]);
			else if(v[i] >= idx1[i] ) {
				swap(idx1[i], idx2[i]);
				idx1[i] = v[i];
			}
			else if(v[i] > idx2[i])
				idx2[i] = v[i];
		}
	}

	forn(i, idx1.size()) {
		cal(i, idx1, i, idx2);
		cal(i, idx1, i-1, idx2);
		cal(i, idx1, i+1, idx2);

		cal(i, idx1, i+1, idx1);
		cal(i, idx1, i-1, idx1);
	}

	forn(i, idx1.size()) {
		Pf("%d - %lld", i, idx1[i].first);
		if(i < idx2.size())
			Pf(", %lld", idx2[i].first);
		cout << endl;
	}

	cout << ht << endl;
	
	return 0;
}

