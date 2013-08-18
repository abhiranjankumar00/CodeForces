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

#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG

ST s, t;
vi mx, mn;
vector <bool> in;

int main()
{
	cin >> s >> t;
	DEBUG(s);
	DEBUG(t);

	mx.resize(s.size(), 0);
	mn.resize(s.size(), t.size());
	in.resize(s.size(), false);

	if(s.size() < t.size() || s.front() != t.front() || s.back() != t.back()) {
		DEBUG("#0");
		cout << "No" << endl;
		return 0;
	}

	mx[0] = 1;
	in[0] = true;

	int tidx = 1;

	for(int sidx = 1; sidx < s.size() && tidx < t.size(); sidx++) {
		mx[sidx] = mx[sidx-1];
		if(t[tidx] == s[sidx]) {
			tidx++;
			in[sidx] = true;
			mx[sidx]++;
		}
	}
	forab(sidx, 1, s.size()-1)
		mx[sidx] = max(mx[sidx], mx[sidx-1]);
	forn(i, s.size())	mx[i]--;

	if(tidx < t.size()) {
		DEBUG("#2");
		cout << "No" << endl;
		return 0;
	}
/*
	cout << "mx= ";
	forn(i, s.size())
		cout << mx[i] ;
	cout << endl;
*/
	mn[s.size()-1] = t.size();
	in[s.size()-1] = true;
	tidx = t.size()-2;
	for(int sidx = s.size()-2; sidx >= 0 && tidx >= 0 ; sidx--) {
		mn[sidx] = mn[sidx+1];
		if(t[tidx] == s[sidx]) {
			tidx--;
			mn[sidx]--;
			in[sidx] = true;
		}
	}
	rep(sidx, s.size()-2, 0)
		mn[sidx] = min(mn[sidx], mn[sidx+1]);
	forn(i, s.size())	mn[i]--;
/*
	cout << "mn= ";
	forn(i, s.size())
		cout << mn[i] ;
	cout << endl;
*/
	vi pos(26, -1);
	rep(i, t.size()-1, 0)
		pos[t[i]-'a'] = i;

	forn(i, s.size()) {
		if(pos[s[i] - 'a'] == -1) {
			DEBUG("#3");
			cout << "No" << endl;
			return 0;
		}
	}
	
	vvi idx(26);
	forn(i, t.size())
		idx[t[i] - 'a'].pb(i);
	forn(i, s.size()) {
		int id = s[i] - 'a';
		auto iter = lower_bound(all(idx[id]), mn[i]-1);
		if(iter == idx[id].end() || *iter > mx[i]+1) {
			DEBUG("#3b");
			DEBUG(i);
//			Pf("mn-1 = %d, mx+1 = %d, it = %d\n", mn[i]-1, mx[i]+1, *iter);
			cout << "No" << endl;
			return 0;
		}
	}
/*
	forab(i, 1, s.size()-2)	if(in[i] == false) {
		if( !(pos[s[i]] <= mn[i]-1 && pos[s[i]] >= mx[i]+1)) {
			DEBUG("#4");
			cout << "No" << endl;
			return 0;
		}	
	}
*/
	DEBUG("#5");
	cout << "Yes" << endl;


	return 0;
}

