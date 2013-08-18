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

void printB(int n) {
	rep(i, 7, 0)	
		Pf("%d", (n&(1<<i)) ? 1 : 0 );
}

int reverse(int n) {
	int a = 0;
	rep(i, 7, 0)	if( n & (1 << i))
		a |= (1 << (7-i));
	return a;
}

int main()
{
/*
	cout << "H: " << (int)'H' << " : ";
	printB('H');
	cout << endl;
	cout << "e: "<< (int)'e' << " : ";
	printB('e');
	cout << endl;
*/
	ST st;
//	cin >> st;
	getline(cin, st);
	st = '\0' + st;
	int lst = 0;
//	cout << st << endl << st.size() << endl;

	forab(i, 1, st.size() - 1) {
		int a3 = (int)st[i];
		int t = st[i-1];
		t = reverse(t);

		int a2 = reverse(a3);
		int a1 = ((reverse(st[i-1]) - a2) % 256 +256) % 256;
		cout << a1 << endl ;

	}
	return 0;
}

