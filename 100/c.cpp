#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9
#define	Sf		scanf
#define	Pf		printf

#define pb		push_back
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

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
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;

#define	all(c)		(c).begin(), (c).end()
#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

vi v;
vvi ans;

bool findSet() {
	auto a = v.begin(), b = v.end();

	if(a == v.end() || b == v.begin())	return false;
	b--;
	int x = *a, z = *b, y;
	if(x == z)	return false;

	v.erase(a);
	v.erase(b);
	auto c = v.begin();

	for(; c != v.end() && *c == x; c++);
	if(c == v.end())	return false;
	y = *c;
	if(y == z)		return false;
	v.erase(c);
	vi t = {x, y, z};
	ans.pb(t);

	return true;
}

bool f() {
	if(v.size() < 3)	return false;
	auto at = v.begin();
	int a = *at;
	v.erase(at);

	auto ct = v.end();
	ct--;
	v.erase(ct);
	int c = *ct;
	if(a == c)		return false;

	auto bt = v.begin();
	for(; bt != v.end() && *bt == a; bt++);
	if(bt == v.end())	return false;
	int b = *bt;
	v.erase(bt);

	vi tmp = {a, b, c};
	ans.pb(tmp);

/*
	for(auto &x : tmp) {
		write(x);
	}
	cout << endl;
*/
	return true;
}

int main()
{
	int n, tmp;
	cin >> n;
	forn(_n, n) {
		read(tmp);
		v.pb(tmp);
	}
	sort(all(v));

	while(f());
	writeln(ans.size());
	for(auto &a : ans) {
		for(auto &x : a)
			write(x);
		Pf("\n");
	}
/*
	while(findSet());

	cout << ans.size() << endl;
	for(auto &r : ans) {
		for(auto &s : r)
			write(s);
		Pf("\n");
	}
*/
	return 0;
}

