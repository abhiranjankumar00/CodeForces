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

#define lim 100010

bool p[lim];
vector < set<int> > s(lim);

void preprocess() {
	CL(p, -1);

	p[0] = p[1] = false;
	s[1].insert(1);

	for(int i = 2; i*i < lim; i++)
		if(p[i]) {
			s[i].insert(i);
			for(int j = i+i; j<lim; j+= i)
				s[j].insert(i), p[j] = false;
		}
/*
	forn(i, 25)
	{
		cout << i << " : ";
		tr(it, s[i])
			cout << *it << ", ";
		cout << endl;
	}
*/

}

int main()
{
	preprocess();
	int x[lim], y[lim], n;

	cin >> n;

	forab(i, 1, n) {
		Sf("%d %d", &x[i], &y[i]);
		map <int, int> m;

		tr(it, s[x[i]])
			m[*it] = true;

/*		cout << x[i] << ": ";
		tr(it, m)
			cout << it->first << " ";
		cout << endl;
*/
		forab(j, i - y[i], i-1) {
//			cout << x[j] << " ";
			tr(it, m)	if(it->second == true) {
				if(x[j] % it->first == 0)
					it->second = false;
			}
		}
//		cout << endl;

		cout << x[i] << " : ";
		tr(it, m)	if(it->second)
			cout << it->first << " ";
		cout << endl;
		cout << endl;
	}
	

	return 0;
}

