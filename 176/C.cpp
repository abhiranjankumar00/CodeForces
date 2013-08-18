//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
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
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater than 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define endl		("\n")
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define PI		M_PI
#define E 		M_E
#define	eps		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
//#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

#if (0 or defined ONLINE_JUDGE)
	#define DEBUG
#else 
	#define DEBUG(x)	cout << #x << " = " << x << "\n"
#endif

const int sz = 1e6 + 111;
vi arr;
vi tmp;
int N;
//set <int> mp[sz];
map <int, set<int> >mp;
bool is[sz];

int idx(int n) {
	return lower_bound(all(tmp), n) - tmp.begin() + 1;
}

int main()
{
	read(N);
	arr = vi(N);

	forn(i, N) {
		read(arr[i]);
		tmp.pb(arr[i]);
	}
/*
	sort(all(tmp));
	tmp.erase(unique(all(tmp)), tmp.end());

	forn(i, N)
		arr[i] = idx(arr[i]);
*/
	forn(i, N)
		mp[arr[i]].insert(i);

	int t, idx;
	read(t);

	while(t --> 0) {
		read(idx);
		arr[idx-1] *= -1;
	}

	if(N % 2 == 1) {
		cout << "NO" << endl;
		return 0;
	}

	forn(i, N) if(arr[i] < 0){
		auto it = mp[abs(arr[i])].find(i);
		is[i] = true;

		//Pf("arr[%d] = %d\n", i, abs(arr[i]));
		DEBUG("#2");

		if(it == mp[abs(arr[i])].begin()) {
			DEBUG("#3");
			cout << "NO" << endl;
			return 0;
		}

		DEBUG("#4");
		auto jt = it;
		jt--;
		int val = *jt;
		is[val] = true;


		mp[abs(arr[i])].erase(it);
		DEBUG("#5");

		jt = mp[abs(arr[i])].find(val);
		mp[abs(arr[i])].erase(jt);
		DEBUG("#6");
	}

	rep(i, N-1, 0)	if(is[i] == false) {
		auto it = mp[arr[i]].find(i);

		if(it == mp[arr[i]].begin()) {
			DEBUG("#3");
			cout << "NO" << endl;
			return 0;
		}

//		auto jt = it;
//		jt--;
		auto jt = mp[arr[i]].begin();
		int val = *jt;
		is[i] = true;
		is[val] = true;

		mp[arr[i]].erase(it);
		//jt = mp[arr[i]].find(val);
		jt = mp[arr[i]].begin();
		mp[arr[i]].erase(jt);
		
		arr[i] *= -1;
	}

	forn(i, N) if(is[i] == false) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	forn(i, N)
		write(arr[i]);
	cout << endl;

	return 0;
}

