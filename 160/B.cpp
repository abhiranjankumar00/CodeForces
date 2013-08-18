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

int main()
{
	int N, K;
	cin >> N >> K;

	vi pos, neg;

	forn(i, N) {
		int tmp;
		cin >> tmp;
		if(tmp >= 0)
			pos.pb(tmp);
		else
			neg.pb(tmp);
	}
	sort(all(pos));
	sort(all(neg));
/*
	tr(it, pos)
		write(*it);
	cout << endl;
	tr(it, neg)
		write(*it);
	cout << endl;
*/
	for(int i = 0; i < neg.size() && K > 0; i++) {
		neg[i] = -neg[i];
		K--;
	}

	if(K % 2 == 1) {
		if(neg.size() > 0 && pos.size() > 0) {
			if(neg.back() < pos.front())
				neg.back() *= -1;
			else
				pos.front() *= -1;
		}
		else if(pos.size() > 0)
			pos.front() *= -1;
		else
			neg.back() *= -1;
	}

/*	
	tr(it, pos)
		write(*it);
	cout << endl;
	tr(it, neg)
		write(*it);
	cout << endl;
*/
	int ans = 0;
	tr(it, pos)
		ans += *it;
	tr(it, neg)
		ans += *it;

	cout <<  ans << endl;


	return 0;
}

