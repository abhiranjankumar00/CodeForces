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
	int n, m;

	cin >> n >> m;
	if(n == 1 || m == 1)
		cout << n*m << endl;
	else if(n <= 2 && m <= 2)
		cout << n*m << endl;
	else if((n % 2 == 1  || m % 2 == 1) && (n*m)%2==0 )
		cout << n*m/2+1 << endl;
//		cout << (n%2==0 ? n : n+1) * (m%2==0 ? m : m+1)/2 << endl;
	else if((n*m) % 2 == 0)
		cout << n*m/2 << endl;
	else
		cout << (n*m+1)/2 << endl;
//		cout << (n+1)/2*(m+1)/2 + (n-1)/2*(m-1)/2 << endl;
	return 0;
}

