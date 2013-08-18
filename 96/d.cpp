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

char cur = 'F';
int sz;
int maxAns = 0;
ST st;

void maxi(int a) {
	if(a > maxAns)	{writeln(a);
//	cout << st << endl;
	}
	maxAns = max(maxAns, a);
}

int ans[111][111];

int cal(int idx, int ans, int rem) {

	if(rem < 0) {
		cout << st << ", ";
		Pf("idx = %d, ans = %d, rem = %d\n", idx, ans, rem);
		return 0;
	}

	if(idx == sz) {
		cout << st << ", ";
		Pf("idx = %d, ans = %d, rem = %d\n", idx, ans, rem);
		return rem == 0 ? ans : 0;
	}


	cout << st << ", ";
	Pf("idx = %d, ans = %d, rem = %d\n", idx, ans, rem);
	if(rem == 0)	maxi(ans);

	maxi(cal(idx+1, (st[idx] == cur ? ans+1 : 0), rem) );

	for(int i = 2; i<=rem; i+=2) {
		maxi( cal(idx+1, (st[i] == cur ? ans+1 : 0), rem - i));
	}

	for(int i = 1; i<=rem; i+=2) {
		st[i] = 'T';
		maxi( cal(idx+1, (st[i] == cur ? ans+1 : 0), rem - i));
	}
}

int main()
{
	cin >> st;
	int n;
	cin >> n;
	sz = st.size();
//	cout << st << endl;

	cal(0, 0, n);
	cur = 'T';
//	cal(0, 0, n);
//	cout << maxAns << endl;
	cout << endl << maxAns << endl;

	return 0;
}

