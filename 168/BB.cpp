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
#define endl		("\n")
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define PI		M_PI
#define E 		M_E
#define	eps		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

#if (0 or defined ONLINE_JUDGE)
	#define DEBUG
#else 
	#define DEBUG(x)	cout << #x << " = " << x << "\n"
#endif

const int sz = 51;
int N, M;
string G[sz];

bool isWhiteinRow[sz][sz][sz], isWhiteinCol[sz][sz][sz];

bool whiteInRow(int x, int y1, int y2) {
	assert(x >= 0 && x < N);
	assert(y1 >= 0 );
	assert(y2 >= y1);
	assert(y2 < M);
	return isWhiteinRow[x][y1][y2];
}

bool whiteInCol(int y, int x1, int x2) {
	assert(y >= 0 && y < M);
	assert(x1 >= 0);
	assert(x2 >= x1);
	assert(x2 < N);
	return isWhiteinCol[y][x1][x2];
}

int main()
{
	cin >> N >> M;
	forn(i, N)
		cin >> G[i];

	forn(x, N) {
		forn(i, M) {
			bool isWhite = false;
			forab(j, i, M-1) {
				if(G[x][j] == 'W')
					isWhite = true;
				isWhiteinRow[x][i][j] = isWhite;
			}
		}
	}
	forn(y, M) {
		forn(i, N) {
			bool isWhite = false;
			forab(j, i, N-1) {
				if(G[j][y] == 'W')
					isWhite = true;
				isWhiteinCol[y][i][j] = isWhite;
			}
		}
	}
/*
	forn(i, N)
		cout << G[i] << endl;
	cout << endl;
	forn(x1, N)	forn(y1, M) {
		forab(x2, x1, N-1) {
			Pf("y = %d, x = [%d, %d] -> %s\n", y1, x1, x2, whiteInCol(y1, x1, x2)?"Y" : "N");
		}
	}
*/

	bool isValid = true;
	forn(x1, N)	forn(y1, M)	if(G[x1][y1] == 'B') {
		forn(x2, N)	forn(y2, M)	if(G[x2][y2] == 'B') {
			Pf();
			if(x1 == x2 && y1 == y2)
				;
			else if(x1 == x2) {
				if(whiteInRow(x1, min(y1, y2), max(y1, y2)))
					isValid = false;
			}
			else if(y1 == y2) {
				if(whiteInCol(y1, min(x1, x2), max(x1, x2)))
					isValid = false;
			}
			else {
				bool mnX = min(x1, x2), mxX = max(x1, x2), mnY = min(y1, y2), mxY = max(y1, y2);
				bool f1 = whiteInRow(x2, mnY, mxY) && whiteInCol(y1, mnX, mxX);
				bool f2 = whiteInRow(x1, mnY, mxY) && whiteInCol(y2, mnX, mxX);
				if( f1 && f2)
					isValid = false;
				if(x1 == 0 && y1 == 4 && x2 == 4 && y2 == 0) {
					DEBUG(f1);
					DEBUG(f2);

				}
			}
		}
	}

	cout << (isValid ? "YES" : "NO") << endl;

	return 0;
}

