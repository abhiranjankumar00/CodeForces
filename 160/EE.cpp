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
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

bool isPow2(int64 n) {
	return (n& (n-1) )== 0 ? true : false;
}

int64 sqrt_(int64 a) {
	int64 ret = sqrt(a);
	if(ret*ret == a)
		return ret;
	if( (ret-1) * (ret-1) == a)
		return ret-1;
	if( (ret+1) * (ret+1) == a)
		return ret+1;
	return ret;
}

int bin_length(int64 n){
	int len = 0;
	while((1ll << (len+1)) <= n)
		len++;
	return len;
}

int64 C[64][64];
int64 nCr(int n, int r) {
	if(r < 0 || r > n)
		return 0;
	return C[n][r];
}

int solve(int64 n, int T) {

}

int main()
{
	forn(i, 64) {
		C[i][0] = C[i][i] = 1;
		forab(j, 1, i-1)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}

	int64 N, T;
	cin >> N >> T;
	N++;

	if(!isPow2(T)) {
		cout << 0 << endl;
		return 0;
	}

	int m = sqrt_(T);
	DEBUG(T);
	DEBUG(m);
	int len = bin_length(T)+1;
	DEBUG(len);


	return 0;
}

