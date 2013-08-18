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
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

void solve(string &st, ii &ans, int R, int B) {
	int r = R, b = B;

	forn(i, R+B+10) {
		if(st.back() == 'r' && b) {
			st += 'b';
			b--;
		}
		else if(st.back() == 'b' && r) {
			st += 'r';
			r--;
		}
		else if(r) {
			st += 'r';
			r--;
		}
		else if(b) {
			st += 'b';
			b--;
		}

		if(st.back() == 'r' && r) {
			st += 'r';
			r--;
		}
		else if(st.back() == 'b' && b) {
			st += 'b';
			b--;
		}
		else if(r) {
			st += 'r';
			r--;
		}
		else if(b) {
			st += 'b';
			b--;
		}
	}
	
	ans = mp(0, 0);

	forab(i, 1, st.size()-1) {
		if(st[i] == st[i-1])
			ans.first++;
		else
			ans.second++;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	string a = "r", b = "b";
	ii ans1, ans2;

	solve(a, ans1, N-1, M);
	solve(b, ans2, N, M-1);

	if(ans1.first > ans2.first) 
		cout << ans1.first << " " << ans1.second << endl;
	else if(ans2.first > ans1.first) 
		cout << ans2.first << " " << ans2.second << endl;
	else
		cout << ans1.first << " " << min(ans1.second, ans2.second) << endl;

	return 0;
}

