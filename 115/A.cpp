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

int main()
{
	ST s;
	cin >> s;

	int ret = -1;

	forn(i, s.size()) {
		forab(j, i+1, s.size() -2) {

			ST as =  s.substr(0, i+1) ;
			ST bs = s.substr(i+1, j-i);
			ST cs = s.substr(j+1) ;

//			if(as.length() > 7 || bs.length() > 7 || cs.length() > 7)
//				continue;

			if(as.size() > 1 && as[0] == '0')
				continue;
			if(bs.size() > 1 && bs[0] == '0')
				continue;
			if(cs.size() > 1 && cs[0] == '0')
				continue;

			int a =  0;//atoi(as.c_str());
			int b = 0; //atoi(bs.c_str());
			int c = 0; //atoi(cs.c_str());

			forn(k, as.size())
				a += as[k] - '0';
			forn(k, bs.size())
				b += bs[k] - '0';
			forn(k, cs.size())
				c += cs[k] - '0';
//			cout << a << " " << b << " " << c << endl;

			if(a > (int)1e6 || b >  (int)1e6 || c > (int)1e6)
				continue;
			ret = max(ret, a+b+c);
		}
	}

	cout << ret << endl;
	
	return 0;
}

