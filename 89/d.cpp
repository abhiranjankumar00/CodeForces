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

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int)b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int) b; i>=loop_ends_here; i--)

#define mod 100000000
//int Ans[101][11][101][11][2];
int Ans[110][110][2];

int aMax, bMax;

int f(int aLeft, int bLeft, bool chance)
{
	int &ans = Ans[aLeft][bLeft][chance];

	if(ans >= 0){
//		Pf("aLeft = %d, bLeft = %d, ans = %d\n", aLeft, bLeft, ans);
		return ans;
	}
/*
	if(aLeft == 0) 
		return (ans = bLeft > bMax ? 0 : 1);
	
	if(bLeft == 0)
		return (ans = aLeft > aMax ? 0 : 1);
*/
	ans = 0;

	if(chance) {
		if(bLeft == 0)
		{
			ans = aLeft <= aMax ? 1 : 0;
			return ans;
		}
		else {
			int limit = min(aLeft, aMax);

			forab(a, 1, limit) {
				ans += f(aLeft - a, bLeft, !chance);
				ans %= mod;
			}
		}
	}

	else {
		if(aLeft == 0) {
			ans = bLeft <= bMax ? 1 : 0;
		}
		else {
			int limit = min(bLeft, bMax);

			forab(b, 1, limit) {
				ans += f(aLeft , bLeft - b, !chance);
				ans %= mod;
			}
		}
	}


//	Pf("aLeft = %2d, aMax = %2d, bLeft = %2d, bMax = %2d, ans = %2d\n", aLeft, aMax, bLeft, bMax, ans);
	return ans;
}

int main()
{
	int aLeft,  bLeft;

	cin >> aLeft >> bLeft >> aMax >> bMax;
//	cin >> aMax >> bMax >> aLeft >> bLeft;

	int ans = 0;
	CL(Ans, -1);
	ans += f(aLeft, bLeft, true);

	//cout << endl;

//	CL(Ans, -1);
	ans += f(aLeft, bLeft, false);

	cout << ans % mod << endl;


	return 0;
}

