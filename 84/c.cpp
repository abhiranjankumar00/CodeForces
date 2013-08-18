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

int par[1000100];
int num[1000100];
char  a[1000100] = {'\0'};

int main()
{
	CL(par, -1);
	CL(num, -1);
	int n;
	cin >> n;

	num[4] = 4,	num[7] = 7;

	forab(i, 1, n)	if(num[i] > 0) {
		if(num[i+4] < 0)
			num[i+4] = 4,	par[i+4] = i;
		if(num[i+7] < 0)
			num[i+7] = 7,	par[i+7] = i;
	}

	if(num[n]< 0)
		cout << -1;
	else {
		int idx = 0;
		while(n > 0) {
			a[idx++] = '0' + num[n];
			n = par[n];
		}
		reverse(a, a+idx);
		printf("%s",a);
	}

	return 0;
}

