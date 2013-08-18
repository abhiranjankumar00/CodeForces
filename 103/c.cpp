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

int sc[26], tc[26];

int process(int cnt) {
	int diff = 0;
	forn(i, 26) {
		if(sc[i] > tc[i])
			return 0;
		diff += (tc[i] - sc[i]);
	}
	return (diff == cnt ? 1 : 0) ; 
}

int main()
{
	ST s, t;	
	cin >> s >> t;
	if(t.size() > s.size()) {
		cout << 0 << endl;
		return 0;
	}

	int ans, diff = 0;
	forn(i, t.size()) {
		if(s[i] != '?')
			sc[s[i] - 'a']++;
		else
			diff++;
		tc[t[i] - 'a']++;
	}
	ans = process(diff);

	int b = 0, e = t.size() -1;

	while((++e) < s.size()) {
		if(s[e] != '?')
			sc[s[e] - 'a']++;
		else
			diff++;

		if(s[b] != '?')
			sc[s[b] - 'a']--;
		else
			diff --;
		b++;
		ans += process(diff);
	}
	cout << ans << endl;
	return 0;
}

