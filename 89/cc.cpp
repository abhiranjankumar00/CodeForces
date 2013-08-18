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

#define valid(n)	(n >= 0 && n <= 9)

int main()
{
	int minCost = -1, toChange = -1	;
	int n, k;

	ST st;

	cin >> n >> k >> st;

	int m[10];
	CL(m, 0);

	forn(i, st.length())
		m[st[i]-'0']++;

	forn(i, 10)	if(m[i] >= k)	{
		cout << 0 << endl << st << endl;
		return 0;

	}

	minCost = toChange = -1;

	forab(i, 0, 9) {
		//cout << endl;
		int curCost = 0, count = min(m[i], k);

		forab(j, 1, 9) {

			if(count < k && valid(i - j)) {
				int p = i-j;


				int req = k - count;
				int change = min(req, m[p]);

				assert(change >= 0);

				curCost += j*change;
				count += change;

			//	Pf("i = %d, p = %d, change = %d, costAdd = %d, curCost = %d\n", i, p, change, j*change, curCost);
			}

			if(count < k && valid(i + j)) {
				int p = i+j;

				int req = k - count;
				int change = min(req, m[p]);

				assert(change >= 0);

				curCost += j*change;
				count += change;
			//	Pf("i = %d, p = %d, change = %d, costAdd = %d, curCost = %d\n", i, p, change, j*change, curCost);
			}

			assert(count <= k);

			if(count == k && (minCost == -1 || minCost > curCost)) {
				minCost = curCost;
				toChange = i;
			}
		}
	}

//	cout << minCost << endl << toChange << endl;

	int req = k - m[toChange];

	forab(i, 1, 9) {
		if(req <= 0)	break;

		if(valid (toChange - i)) {
			char p = toChange - i + '0';

//			forn(j, st.length()) {
			rep(j, st.length()-1, 0) {
				if(req <= 0)	break;

				if(st[j] == p) {
					st[j] = toChange + '0';
					req--;
				}
			}
		}
		if(valid (toChange + i)) {
			char p = toChange + i + '0';

//			rep(j, st.length()-1, 0) {
			forn(j, st.length()) {
				if(req <= 0)	break;

				if(st[j] == p) {
					st[j] = toChange + '0';
					req--;
				}
			}
		}

	}
	assert(req == 0);
	cout << minCost << endl << st << endl;

	return 0;
}

