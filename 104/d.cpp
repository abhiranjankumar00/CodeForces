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

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair

#define pb		push_back
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

ST ans;

bool process(int c4, int c7, int c47, int c74) {
	ans = "";

	if(c47 == c74) {
		int t = c4 - c47 - 1;
		if(t < 0 || c7 < c74)
			return false;
		while(t--) {
			ans += '4';
			c4--;
		}
		while(c47) {
			ans += "47";
			c47--;
			c74--;
			c4--;
			c7--;
		}
		while(c7) {
			ans += "7";
			c7--;
		}
		ans += "4";
		c4--;
		if(c4 < 0 || c7 < 0 || c47 < 0 || c74 < 0)
			return false;
		return true;
	}

	if(c47 == c74 + 1) {
		int t = c4 - c47 - 0;
		if(t < 0 || c7 < c47)
			return false;
		while(t--) {
			ans += '4';
			c4--;
		}
		while(c47) {
			ans += "47";
			c47--;
			c74--;
			c4--;
			c7--;
		}
		c74++;
		while(c7) {
			ans += "7";
			c7--;
		}
		if(c4 < 0 || c7 < 0 || c47 < 0 || c74 < 0)
			return false;
		return true;
	}

	if(c47 + 1 == c74 ) {
		ans += "74";
		c74--;	c4--;	c7--;
		int t = c4 - c47 - 1;
		if(t < 0 || c7 < c47)
			return false;
		while(t--) {
			ans += '4';
			c4--;
		}
		while(c47) {
			ans += "47";
			c47--;
			c74--;
			c4--;
			c7--;
		}
		c74++;
		while(c7) {
			ans += "7";
			c7--;
		}
		ans += "4";
		c4--;
		c74--;
		if(c4 < 0 || c7 < 0 || c47 < 0 || c74 < 0)
			return false;
		return true;
	}
	return false;
}
int main()
{
	int c4, c7, c47, c74;
	cin >> c4 >> c7 >> c47 >> c74;

	bool ret = process(c4, c7, c47, c74);
	if(c47 == c74)
		ret = process(c4, c7, c47, c74);
	else if(c47 == c74+1) {
		ret = process(c4, c7-1, c47-1, c74); 
		ans += "7";
	}
	else if(c47 == c74-1) {
		ret = process(c4, c7-1, c47, c74-1); 
		ans = "7" + ans;
	}
	else
		ret = false;

	if(ret)
		cout << ans << endl;
	else
		cout << -1 << endl;

	return 0;
}

