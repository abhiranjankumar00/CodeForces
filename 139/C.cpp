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

const int sz = 1e3 + 100;

ST picture[sz];
int N, M, X, Y;
int hashc[sz], zero[sz];

int cntHash(int l, int r) {
//	if(l < 0 || l > r || r > M-1)
//		return 0;
	l = max(0, l);
	r = min(r, M-1);
	if(l == 0)
		return hashc[r];
	return hashc[r] - hashc[l-1];
}

int cntZero(int l, int r) {
//	if(l < 0 || l > r || r > M-1)
//		return 0;
	l = max(0, l);
	r = min(r, M-1);
	if(l == 0)
		return zero[r];
	return zero[r] - zero[l-1];
}

int colorHash(int l, int r) {
	int cnt = cntHash(0, l-1) + cntZero(l,r) + cntHash(r+1, M-1);
	return cnt;
}	

int colorZero(int l, int r) {
	int cnt = cntZero(0, l-1) + cntHash(l,r) + cntZero(r+1, M-1);
	return cnt;
}

int dpHs[sz], dpZero[sz];

int main()
{
	cin >> N >> M >> X >> Y;
	forn(i, N)
		cin >> picture[i];

	forn(i, M) {
		int cnt = 0;
		forn(j, N) {
			if(picture[j][i] == '#')
				cnt++;
		}
		hashc[i] = (i == 0 ? 0 : hashc[i-1]) + cnt;
		zero[i] = (i == 0 ? 0 : zero[i-1]) + (N-cnt);
	}

/*
	forn(i, N) {
		forn(j, M)
			Pf("%2c ", picture[i][j]);
		cout << endl;
	}
	cout << endl;
	forn(i, M)
		Pf("%2d ", hashc[i]);
	cout << endl;
	forn(i, M)
		Pf("%2d ", zero[i]);
	cout << endl;
	cout << endl;
*/
	CL(dpHs, -1);
	CL(dpZero, -1);
	forn(i, sz)
		dpHs[i] = dpZero[i] = 1e7;
	forab(i, X-1, Y-1) {
		dpHs[i] = cntZero(0, i);
		dpZero[i] = cntHash(0, i);
	}

	forn(i, M) {
		forab(j, X, Y) if(i - j >= 0) {
			dpZero[i] = min(dpZero[i], dpHs[i-j] + cntHash(i-j+1, i));
			dpHs[i] = min(dpHs[i], dpZero[i-j] + cntZero(i-j+1, i));
		}
	}
	cout << (min(dpZero[M-1], dpHs[M-1]));
	return 0;


	forab(i, X-1, M-1) {
		forab(j, X, Y) 	if(i + j < M) {
			if(dpHs[i+j] < 0)
				dpHs[i+j] = dpZero[i] + cntZero(i+1, i+j);
			else
				dpHs[i+j] = min(dpHs[i+j], dpZero[i] + cntZero(i+1, i+j));

			if(dpZero[i+j] < 0)
				dpZero[i+j] = dpHs[i] + cntHash(i+1, i+j);
			else
				dpZero[i+j] = min(dpZero[i+j], dpHs[i] + cntHash(i+1, i+j) );
		}
		Pf("i = %d, dpHs = %d, dpZero = %d, cntHs = %d, cntZero = %d", i, dpHs[i], dpZero[i], cntHash(i, i), cntZero(i, i));
		cout << endl;
	}

	cout << min(dpHs[M-1], dpZero[M-1]) << endl;
	return 0;

	int ans = 1e9;

	forn(l, M) {
		forab(r, l, M-1)	if(r-l+1 >= X && r-l +1<= Y) {
			int cnt = colorHash(l, r);
//			int dotsLeft = cntZero(0, l-1);
//			int dotsRights = cntZero(r+1, M-1);
//			int hs = cntHash(l, r);
//			Pf("[%d, %d] = %d\n", l, r, cnt);
//			Pf("dotsLeft = %d, hash = %d, dotsRight = %d\n", dotsLeft, hs, dotsRights);
//			cout << endl;
			ans = min(ans, cnt);
		}
	}
	cout << ans << endl;
//	DEBUG(ans);
	return 0;
}

