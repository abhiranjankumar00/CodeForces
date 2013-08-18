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
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl		("\n")
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

bool allNine(const ST &st) {
	bool flag = true;
	forab(i,1, st.size()-1)
		flag &= st[i] == '9';
	return flag || (st.size() == 1);
}

ST nextString( ST st) {
	if(st.size() == 1)
		return st;
	int idx = st.size() - 1;

	while(idx >= 0 && st[idx] == '9')
		idx--;
	st[idx--] = '9';

	while(idx >= 0 && st[idx] == '0')
		st[idx--] = '9';
	st[idx]--;

	if(st[0] == '0')
		st = st.substr(1);

	return st;
}

int64 calcDiff(ST a, ST b) {
	int64 an, bn;
	SS sa(a), sb(b);
	sa >> an ;
	sb >> bn;
	return bn-an;
}

int main()
{
	ST st = "1234";
	int64 diff;

	while(cin >> st >> diff) {
		const ST orig = st;

		while(allNine(st) == false && (calcDiff(nextString(st), orig) <= diff ) ) {
			st = nextString(st);
		}
		cout << st << endl;
//		DEBUG(st);
	}
	return 0;
}

