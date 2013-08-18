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

void trim(ST &s) {
	while(s.size() > 1 && s[0] == '0')
		s = s.substr(1);
}

int num(char ch) {
	return isdigit(ch) ? ch - '0' : ch - 'A' + 10;
}

int num(ST &n, int b) {
	int ans = 0, B = 1, tmp;

	rep(i, n.size() - 1, 0) {
		tmp = num(n[i]);
		ans += tmp*B;
		B *= b;
		if(ans > 65)
			return -1;
	}
	return ans;
}

bool inline valid(int h, int m) {
	return (h >= 0 && h <= 23 && m >= 0 && m <= 59) ? true : false;
}

int main()
{
	char at[1000], bt[1000];
	Sf("%[^:]%*c%s", at, bt);

	ST hh(at), mn(bt);

	trim(hh);	trim(mn);
	int mx = 0;
	for(auto x : hh)
		mx = max(mx, num(x));
	for(auto x : mn)
		mx = max(mx, num(x));

	vi ans;

	forab(i, mx + 1, 65) {
		int h = num(hh, i);
		int m = num(mn, i);

//		Pf("B = %d, h = %d, m = %d\n", i, h, m);

		if(valid(h, m))
			ans.pb(i);
	}

	if(ans.size() == 0)
		writeln(0);
	else if(*ans.rbegin() > 62)
		writeln(-1);
	else
		for(auto x: ans)
			write(x);
	cout << endl;


	return 0;
}

