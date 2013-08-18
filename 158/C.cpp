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

int main()
{
	int64 N, X, arr[(int)1e5 + 111];
	cin >> N >> X;
	X--;
	forn(i, N)
		cin >> arr[i];

	int id_zero = -1, cnt_zero = 0;
	forn(i, N) if(arr[i] == 0) {
		cnt_zero++;
		id_zero = i;
	}

	assert(cnt_zero < 2);

	if(cnt_zero == 1) {
//		arr[id_zero] = 1;
		int add = 1, tmp = 0;

		while(true) {
			arr[(id_zero + add ) % N]--;
			tmp++;
			if((id_zero + add) % N == X)
				break;
			add++;
		}
		arr[id_zero] += tmp;
		forn(i, N)
			cout << arr[i] << " ";
		cout << endl;
		return 0;
	}

	if(arr[X] > 1) {
		int id = (X + N-1) % N;
		arr[id]++;
		arr[X]--;
		forn(i, N)
			cout << arr[i] << " ";
		cout << endl;

		return 0;
	}
	arr[X] += N-1;

	forn(i, N)	if(i != X) {
		arr[i] --;
		assert(arr[i] > arr[i] > 00);
	}

	forn(i, N)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}

