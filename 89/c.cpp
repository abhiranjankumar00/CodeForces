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

#define valid(i)	(i >= 0 && i <= 9)

int main()
{
	int n, k, ans = -1, cost , m[10];
	CL(m, 0);
	ST st;

	cin >> n >> k >> st;

	forn(i, st.length())
		m[st[i] - '0']++;

	int toChange = -1;
	int minCost = -1;

	forn(i, 10)	if(m[i] >= k) {
		cout << 0 << endl << st << endl;
		return 0;
	}

	forn(i, 10)
		Pf("%d -> %d\n", i, m[i]);

	forn(i, 10) {
		int cnt = m[i];
		int cost = 0;

		forab(j, 1, 9) {

			Pf("i=%d, j = %d, k= %d, cnt = %d, cost = %d, mincost = %d\n", i, j, k, cnt, cost, minCost);

			if(cnt >= k)
				if(minCost == -1 || minCost > cost) {
					minCost = cost;
					toChange = i;
					break;
				}

			if(valid(i + j)) {
				int p = i+j;
				int f = min(k - cnt, m[p] - cnt);

				if(cnt + m[p] >= k) {
					f = k - cnt;
					cnt = k;
				}
				else
				{
					cnt += m[p];
					f = m[p];
				}


				assert(f >= 0);
				cnt += f;
				cost += j*f;
			}

			if(valid(i - j)) {
				int p = i-j;

				int f = min(k - cnt, m[p] - cnt);
				if(cnt + m[p] >= k) {
					f = k - cnt;
					cnt = k;
				}
				else
				{
					cnt += m[p];
					f = m[p];
				}

				assert(f >= 0);
				cnt += f;
				cost += j*f;
			}
		}
	}

	cout << minCost << endl << toChange << endl;

	return 0;
}

