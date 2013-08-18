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


vi cntBrackets;
vi cntBraces;
ST st;
vi cnt;

int range(int l, int r) { 
	if(l < 0)
		return 0;
	if(l > r)
		return 0;
	if(r >= st.size())
		return 0;

	if(l == 0)
		return cnt[r];
//		return cntBrackets[r];

	return cnt[r]- cnt[l-1];
//	return cntBrackets[r] - cntBrackets[l-1];
}

#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG

int main()
{
	vector <char> brackets;
	vector <int> pos;
	getline(cin, st);
	if(st.size() == 0) {
		cout << 0 << endl << "" << endl;
		return 0;
	}
//	cin >> st;
//	cntBrackets.resize(st.size(), 0);
//	cntBraces.resize(st.size(), 0);

	forn(i, st.size()) {
		if(i == 0)
			st[i] == '[' ? cnt.pb(1) : cnt.pb(0);
		else 
			st[i] == '[' ? cnt.pb(cnt.back()+1) : cnt.pb(cnt.back());

		if(st[i] == '(' || st[i] == '[') {
			brackets.pb(st[i]);
			pos.pb(i);
/*
			if(st[i] == '(')
				cntBraces[i] = (i == 0 ? 1 : (cntBraces[i-1]+1));
			if(st[i] == '[')
				cntBrackets[i] = (i == 0 ? 1 : (cntBrackets[i-1]+1));
*/
		}
		else if(st[i] == ']') {
			if(brackets.empty() == false && brackets.back() == '[') {
				brackets.pop_back();
				pos.pop_back();
			}
			else {
				brackets.pb(st[i]);
				pos.pb(i);
			}
//			if(i == 0)
//				cntBrackets[0] = 0;
//			else
//				cntBrackets[i] = cntBrackets[i-1];
		}
		else {	// st[i] == ')' 
			if(brackets.empty() == false && brackets.back() == '(') {
				brackets.pop_back();
				pos.pop_back();
			}
			else {
				brackets.pb(st[i]);
				pos.pb(i);
			}
//			if(i == 0)
//				cntBrackets[i] = 0;
//			else
//				cntBrackets[i] = cntBrackets[i-1];
		}
	}

/*
	cout << "st  = ";
	tr(it, st)
		cout << setw(2) << *it << " ";
	cout << endl;

	cout << "cnt = ";
//	tr(it, cntBrackets)
	tr(it, cnt)
		cout << setw(2) << *it << " ";
	cout << endl;
	
	cout << "idx = " ;
	forn(i, st.size())
		cout << setw(2) << i << " " ;
	cout << endl << endl;

	cout << "brackets : ";
	tr(it, brackets)
		cout << setw(2) << *it << " ";
	cout << endl;
	cout << "positions: ";
	tr(it, pos)
		cout << setw(2) << *it << " ";
	cout << endl;
*/
	int mxCnt = 0, L = 0, R = 0;
	if(pos.empty()) {
		cout << cnt[st.size()-1] << endl;
//		cout << cntBrackets[st.size()-1] << endl;
		cout << st << endl;
		return 0;
	}
	else {
		DEBUG(range(0, pos.front()-1));
		
		if(0 != pos.front() && range(0, pos.front()-1) > mxCnt) {
			mxCnt = range(0, pos.front()-1);
			L = 0;
			R = pos.front()-1;
		}

		forn(i, pos.size()-1) {
			if(pos[i+1] > pos[i]+1) {
				DEBUG(range(pos[i]+1, pos[i+1]-1));
				if(range(pos[i]+1, pos[i+1]-1) > mxCnt) {
					mxCnt = range(pos[i]+1, pos[i+1]-1);
					L = pos[i] + 1;
					R = pos[i+1]-1;
				}
			}
		}
		if(range(pos.back(), st.size()-1) > mxCnt && pos.back() < st.size()-1) {
			mxCnt = range(pos.back()+1, st.size()-1);
			L = pos.back()+1;
			R = st.size()-1;
		}
	}

	if(mxCnt == 0) {
		cout << 0 << endl;
		cout << "" << endl;
		return 0;
	}

	cout << mxCnt << endl;
	cout << st.substr(L, R-L+1);

	return 0;
}

