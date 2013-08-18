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

string absolve(string st) {
	if(st == "")
		return "";

		vs ans;
		ans.pb(st.substr(0, 1));
//		cout << "In for st = " << st << endl;

		forab(i, 1, st.size() -1 )  {
			if(st[i] == ':') {
				ans.pb(string());
			}
			else
				ans.back() += st[i];
		}
		string ret;
		forn(i, ans.size()) {
			while(ans[i].size() < 4)
				ans[i] = "0" + ans[i];
			ret += ans[i];
//			cout << ans[i];
			if(i == ans.size() - 1)
				;
//				cout << endl;
			else
				ret += ":";
//				cout << ":";
		}

		return ret;
}

void solve() {
	string st;
	cin >> st;
	DEBUG(st);

	if(st == "::") {
		cout << "0000:0000:0000:0000:0000:0000:0000:0000" << endl;
		return;
	}

	int idx = st.find("::");
	if(idx == string::npos) {
		int start = 0, len = 0;
		cout << absolve(st) << endl;
		return;
	}
	if(idx == st.size() - 2) {
		string ans = absolve(st.substr(0, st.size()-2));
//		DEBUG(st);
//		DEBUG(ans);
		while(ans.size()+1 < 40)
			ans += ":0000";
		cout << ans << endl;
		return;
	}
	if(idx == 0) {
		string ans = absolve(st.substr(2));
		while(ans.size() +1 < 40)
			ans = "0000:" + ans;
		cout << ans << endl;
		return;
	}

	vs ans(8);
	string fst = st.substr(0, idx);
	fst = absolve(fst);
	string snd = st.substr(idx+2);
	snd = absolve(snd);


//	DEBUG(st);
//	DEBUG(fst);
//	DEBUG(snd);
	while(fst.size() + snd.size() + 2 < 40)
		fst += ":0000";
	cout << fst + ":" +  snd << endl;
	return ;

	forn(i, 8) {
		cout << ans[i];
		if(i == 7)
			cout << endl;
		else
			cout << ":";
	}
}

int main()
{
	int N;
	cin >> N;
	while(N--) {
		solve();
	}

	return 0;
}

