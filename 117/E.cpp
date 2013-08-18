//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
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
#ifdef __cplusplus
	#undef __cplusplus
	#define __cplusplus 199712L
#endif
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

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

const int mod = 1e9 + 7;

int board[111][2];
int n, l;

int Ans[110][3010][110];

int cal (int idx, int len, int lst = -1) {
//	Pf("idx = %d, len = %d, lst = %d\n", idx, len, lst);
	if(len == 0)
		return 1;
	if(len < 0)
		return 0;

	assert(idx >= -1 && idx <= 100);
	assert(lst >= -1 && lst <= 100);
	assert(len >= 0 && len <= 3000);

	int rret = 0;
	if(lst == -1) {
//		cout << "#a\n";
		forn(i, n) {
			if(len - board[i][0] >= 0)
				rret = (rret + cal(i, len-board[i][0], board[i][1])) % mod;
			if(len - board[i][1] >= 0 && board[i][0] != board[i][1])
				rret = (rret + cal(i, len-board[i][1], board[i][0])) % mod;
		}
		return rret;
	}

	int &ret = Ans[idx][len][lst];

	if(ret > -1)
		return ret;

	ret = 0;


	forn(i, n) 	if(i != idx) {
		if(board[i][0] == lst) {
			ret = (ret + cal(i, len - lst, board[i][1])) % mod;
		}
		else if(board[i][1] == lst)
			ret = (ret + cal(i, len-lst, board[i][0])) % mod;
	}
	return ret;
}

int main()
{
	CL(Ans, -1);
	Sf("%d %d", &n, &l);
//	Pf("n = %d, l = %d\n", n, l);
	forn(i, n)
		Sf("%d %d", &board[i][0], &board[i][1]);
	
//	cout << "#2" << endl;
	cout << cal(-1, l, -1) << endl;

	return 0;
}

