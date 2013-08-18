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


#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG


int64 Sqrt(int64 n) {
	int64 sq = sqrt(n);
	sq--;
	if(sq*sq==n)
		return sq;
	sq++;
	if(sq*sq == n)
		return sq;
	sq++;
	if(sq*sq == n)
		return sq;
	return -1;
}

const int sz = 1e6 + 111;
bool isPrime[sz];

void inline yes() {	Pf("YES\n") ;	}
void inline no() {	Pf("NO\n");	}

int main()
{
	CL(isPrime, 1);
	isPrime[1] = false;
	isPrime[0] = false;

	for(int i = 0; i*i <= sz; i++)	if(isPrime[i]) {
		for(int j = i+i; j < sz; j+=i)
			isPrime[j] = false;
	}

	int N;
	cin >> N;

	while(N--) {
		int64 tmp;
		cin >> tmp;
		int64 sol = Sqrt(tmp);
		DEBUG(tmp);
		DEBUG(sol);
		DEBUG("\n");

		if(sol < 0)
			no();
		else if(isPrime[sol] == false)
			no();
		else
			yes();
	}	

	return 0;
}

