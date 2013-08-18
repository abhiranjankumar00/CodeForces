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

const int sz = 2e5 + 10;
int H[sz];
int  h, m, n;
map <int, int> hsh;

map <int, set <int> > used;

int main()
{
//	cin >> h >> m >> n;
	Sf("%d %d %d\n", &h, &m, &n);
	int ret = 0;

//	cout << h << " " << m << " " << n << endl << endl;

	while(n--) {
		char sign;
		int id;
		Sf("%c %d", &sign, &id);

		if(sign == '+') {
			int t, cnt = 0;
			Sf("%d", &t);
/*
			if(used.find(t%m) == used.end()) {
				used[t%m] = set <int> {t};
				hsh[id] = t%m;
			}
*///			else 
			{
				auto &st = used[t%m];
				while( st.find( (t + cnt*m) % h) != st.end())
					ret++, cnt++;
				st.insert((t + cnt*m ) % h);
				hsh [id] = (t + cnt*m )% h;
			}
//			Pf("sign = %c, id = %d, t = %d\n", sign, id, hsh[id]);
		}
		else {
			int hs = hsh[id];
//			Pf("sign = %c, id = %d, t = %d\n", sign, id, hs);
			used[hs%m].erase(hs);
		}
//		cout << "cnt = " << ret << endl;
		Sf("\n");
/*
		for(auto &x: used) {
			cout << x.first << " -> ";
			for(auto &y: x.second)
				cout << y << " ";
			cout << endl;
		}
		cout << endl;
*/	}
	cout << ret << endl;

	return 0;
}

