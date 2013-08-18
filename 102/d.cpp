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

int main()
{
	bool arr[1001][1001] = {};
	CL(arr, -1);
	int ans = 0;
	int n, m;
	cin >> n >> m;
	if(n < m)
		swap(n, m);

	int X[] = { 1,  1, -1, -1,  2,  2, -2, -2};
	int Y[] = { 2, -2,  2, -2,  1, -1,  1, -1};

	forn(x, n) {
		forn(y, m) {
			Pf("(%d, %d) = %d -> ", x, y, (arr[x][y] ? 1  : 0));
			if(arr[x][y]) {
				ans++;
				forn(i, 8) {
					if(x + X[i] >= 0 && x + X[i] < n && y + Y[i] >= 0 && y + Y[i] < m) {
						arr[x+X[i]][y + Y[i]] = false;
						Pf("(%d, %d) ", x + X[i], y + Y[i]);
					}
				}
			}
			cout << endl;
		}
	}

	cout << endl;
	forn(x, n) {
		forn(y, m) {
			cout << (arr[x][y] ? 1 : 0 ) << " ";
		}
		cout << endl;
	}

	cout << ans << endl;

	return 0;
}

