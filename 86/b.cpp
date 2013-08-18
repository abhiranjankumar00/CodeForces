//%%%%%%%%%%%%
//%%%%lost%%%%
//%%%%%%%%%%%%

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

typedef long long  int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<string> vs;

#define Pf	printf
#define	Sf	scanf

#define PI M_PI
#define E M_E
#define	ep	1e-9

#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp	make_pair

#define pb	push_back
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0; i < n; i++)
#define forab(i, a, b)	for(int i = a; i <= b; i++)
#define rep(i, a, b)	for(int i = a; i>=b; i--)

int main()
{
	int n, k;
	map<ST, set<ST> >m;
	vs name;

	m.clear();
	name.clear();

	cin >> n >> k;
	ST st, st1, st2, idx;

	forn(i, n) {
		cin >> st;
		name.pb(st);
	}

	forn(i, n)
		forn(j, n)
			if(i != j)
				m[name[i]].insert(name[j]);

	tr(it, m) {
		cout << it-> first << " : ";
		tr(jt, it->second)
			cout << *jt << " ";
		cout << endl;
	}

	forn(i, k) {
		cin >> st1 >> st2;
		m[st1].erase(st2);
		m[st2].erase(st1);

	}
	tr(it, m) {
		cout << it-> first << " : ";
		tr(jt, it->second)
			cout << *jt << " ";
		cout << endl;
	}

	return 0;
}

