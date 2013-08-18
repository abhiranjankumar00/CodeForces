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
	int n, day[7], sum = 0;

	cin >> n;
	forn(i, 7) {
		cin >>  day[i];
		sum += day[i];
	}

	while(true) {
		if(n - sum <= 0)	break;
		n -= sum;
	}

	forn(i, 7) {
		if(n - day[i] <= 0) {
			cout << i+1 << endl;
			break;
		}
		else
			n -= day[i];
	}

	return 0;
}

