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

int main()
{
	ST A, B;
	cin >> A >> B;
	ST a, b;
	if(A.length() < B.length())
		a = A, b = B;
	else
		a = B, b = A;


	bool flag = true;

	for(int i = 0; flag && i < a.size(); i++)
		flag &= (a[i] == b[i] ? true: false);

	if(!flag ) {
		cout << 0 << endl;
		return 0;
	}

	int ret = 0;
	for(int i = 1; i <= a.size(); i++)	if(a.size() % i == 0) {
		int blocks = a.size() / i;
		int len = i;

		flag = true;

		if(b.size() % len != 0)
			continue;

		for(int l = 0; flag && l < len; l++) {
			for(int b = 0; flag && b < blocks; b++)
				flag &= (a[l] == a[len*b + l] ? true : false);
		}

		blocks = b.size() / len;
		for(int l = 0; flag && l < len; l++) {
			for(int nb = 0; flag && nb < blocks; nb++)
				flag &= (a[l] == b[len*nb + l]);
		}

//		Pf("len = %d, blocks = %d, flag = %d\n", len, blocks, flag);

		if(flag && b.size() % i == 0)
			ret++;
	}
	
	cout << ret << endl;
	return 0;
}

