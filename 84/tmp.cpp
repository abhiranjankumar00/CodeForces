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

bool  cnt[1000000] = {};
int count[1000000] = {};

int main()
{
	cnt[4] = cnt[7]  = true;
	count[4] = 1,	count[7] = 2;

	forn(i, 100000)
		if(cnt[i])
			cnt[i+4] = cnt[i+7] = true/* , 	count[i+4] = max(count[i] + 1, count[i+4]),	count[i+7] = max(count[i+7], count[i] + 1)*/:

	forn(i, 100000)	if(!cnt[i])
		printf("%d  ", i);
	cout << endl << endl;

	forn(i, 21)	if(cnt[i])
		Pf("(%d, %*d)  ", i, count[i]);
	cout << endl << endl;

	int c = 0;
	forab(i, 1, 20)	if(cnt[i])
		c++, Pf("(%d, %d)  ", i, c);

	return 0;
}

