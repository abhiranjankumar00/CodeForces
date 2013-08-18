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

ST board[8];
vector <ii> pos;
bool vis[100][8][8];

bool inline valid(int x, int y)		{	return x >= 0 && x < 8 && y >= 0 && y < 8;		}
bool wayFound = false;

void findWay(int row = 7, int col = 0, int step = 0) { 
	if(step >= 50)
		return;
	if(!valid(row, col))
		return;
	if(vis[step][row][col])
		return;
	vis[step][row][col] = true;
/*
	tr(it, pos) 
		if(it->first + step == row && it->second == col)
			return;
*/
//	Pf("(%d: %d, %d)  ", step, row, col);
	if(row == 0 && col == 7)
		wayFound = true;

	forab(i, -1, 1) {
		forab(j, -1, 1) {
			bool validMove = true;
			tr(it, pos)
				if(it->second == col + j && (it->first + step == row+i || it->first + step+1 == row+i))
					validMove = false;
			if(validMove)
				findWay(row+i, col+j, step+1);
		}
	}
}

int main()
{
	CL(vis, 0);
	forn(i, 8)
		cin >> board[i];
	forn(i, 8)
		forn(j, 8)
			if(board[i][j] == 'S')
				pos.pb(mp(i, j));
/*
	forn(i, 8)
		cout << board[i] << endl;
	tr(it, pos)
		Pf("(%d, %d) " ,it->first, it->second );
	cout << endl;
*/
	findWay();
	cout << (wayFound ? "WIN" : "LOSE") ;

	return 0;
}

