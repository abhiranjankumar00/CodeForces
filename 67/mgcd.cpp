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



int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int Find(int lo, int hi, int d) {
	rep(i, hi, lo)
		if(d % i == 0)	
			return i;
	return -1;
}
vi fact;
vi res;
vector <bool> vis;
int sz;

void bt(int idx = 0)
{
	if(idx == sz)
	{
		int t = 1;
		forn(i, sz)	if(vis[i])
			t *= fact[i];
		res.pb(t);
		return;
	}
	vis[idx] = false;
	bt(idx+1);
	vis[idx] = true;
	bt(idx+1);
}

void Process(int n) {
	fact.clear();

	while(n % 2 == 0)
		fact.pb(2), n /= 2;

	for(int i = 3; i*i <= n; i+=2)
	{
		while(n%i == 0)
		{
//			cout << n << " " << i << endl;
			fact.pb(i);
			n /= i;
		}
	}
	if(n != 1)
		fact.pb(n);

//	cout << endl << endl;
//
	sz = SZ(fact);
	vis.resize(sz);
	res.clear();

	bt( 0);

	sort(all(res));

	res.resize(unique(all(res))- res.begin() );
/*
	tr(it, res)
		cout << *it << " \t";
	cout << endl;
	*/
}

int FindNew(int lo, int hi) {

	vector <int> :: iterator it;
	it = upper_bound(all(res), hi);
	int idx = it - res.begin();

	if(it != res.end() && *it <= hi && *it >=lo)
		return *it;
	
	if(it != res.begin()){
		int n = res[idx-1];
		if(n >= lo && n <= hi)
			return n;
	}
	return -1;

}

int main()
{
	int a, b, low, hi;
	cin >> a >> b;
	int n, d = gcd(a, b);

	Process(d);
/*
	tr(it, fact)
		cout << *it << " ";
	cout << endl << endl;;
*/
	cin >> n;

	forn(_n, n) {
		Sf("%d %d", &low, &hi);
		Pf("%d\n", FindNew(low, hi));
	}

	return 0;
}
