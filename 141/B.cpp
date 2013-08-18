//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force
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
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl		("\n")
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define	Sf		scanf
#define	Pf		printf
#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

char A[55][55], B[55][55];
int na, ma;
int nb, mb;

int solve(int x, int y){
	int sum = 0;
	forab(i, 1, na) {
		forab(j, 1, ma) {
			if(i+x >= 1 && i+x <= nb && j+y >= 1 && j+y <= mb) {
				sum += (A[i][j] - '0') * (B[i+x][j+y] - '0');
			//	if(x == -1 && y == -1)
			//		Pf("i = %d, j = %d, x = %d, y = %d", i, j, x, y);
			}
		}
	}
//	if(x == -1 && y == -1)
//		DEBUG(sum);
	return sum;
}

int main()
{
	Sf("%d %d\n", &na, &ma);

	forab(i, 1, na)
		forab(j, 1, ma)
			cin >> A[i][j];

/*
	forab(i, 1, na) {
		forab(j, 1, ma)
			cout << A[i][j];
		cout << endl;
	}
*/
	cin >> nb >> mb;
	forab(i, 1, nb) {
		forab(j, 1, mb)
			cin >> B[i][j];
	}
/*
	forab(i, 1, nb) {
		forab(j, 1, mb)
			cout << B[i][j] ;
		cout << endl;
	}
*/
	int xAns = 0, yAns = 0, sumAns = -1;

	forab(x, -50, 50) {
		forab(y, -50, 50) {
			int sum = solve(x, y);
			
//			if(x > -2 && x < 2 && y > -2 && y < 2)
//			if(sum != 0)
//			Pf("(%d, %d), sum = %d, sumAns = %d\n", x, y, sum, sumAns);
			if(sum > sumAns) {
				xAns = x;
				yAns = y;
				sumAns = sum;
			}
		}
	}
	cout << xAns << " " << yAns ;

	return 0;
}

