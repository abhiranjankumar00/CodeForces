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

int dig[10] = {}, a[10] = {}, b[10] = {};

int count() {
	int ans = 0;
	forn(i, 10) {
		int j = 9-i;
		if(i+j == 9 && a[i] && b[j]) {
			ans += min(a[i], b[j]);
/*
			int t = min(a[i], b[j]);
			a[i] -= t;	b[j] -= t;
	
			ans+= t;

			a[i] += t;	b[j] += t;
*/
		}
	}
	return ans;
}

int main()
{
	ST st;
	ST aa = "", bb = "";

	cin >> st;
	forn(i, st.size()) {
		int id = st[i] - '0';
		dig[id] ++;	a[id]++;	b[id]++;
	}
	int ans = 0;

	forn(i, 10)	forn(j, 10)	if(i+j == 10 && a[i] && b[j]) {
		a[i]--;	b[j]--;

		int t = 1;
		t += count();

		if(t > ans)
			ans = t;

		a[i]++;	b[j]++;
	}

	aa = st;	bb = st;
	forn(i, 10)	forn(j, 10)	if(i+j == 10 && a[i] && b[j]) {
		a[i]--;		b[j]--;
		int t = 1;
		t += count();

		if(t == ans) {
			aa = "";		bb = "";
			aa += char('0' + i);
			bb += char('0' + j);

			forn(i, 10) {
				int j = 9-i;
				if(i+j == 9 && a[i] && b[j]) {
					int t = min(a[i], b[j]);
					aa += char('0' + i);
					bb += char('0' + j);
					a[i] -= t;
					b[j]-= t;
/*
					int t = min(a[i], b[j]);
					a[i] -= t;	b[j] -= t;
	
					ans+= t;

					a[i] += t;	b[j] += t;
*/
				}
			}

			forn(i, 10) {
				forn(_l, a[i])
					aa += char('0' + i);
				forn(_l, b[i])
					bb += char('0' + i);
			}

			break;
		}
	}
	reverse(all(aa));
	reverse(all(bb));

	cout << aa << endl << bb ;

	return 0;
}

