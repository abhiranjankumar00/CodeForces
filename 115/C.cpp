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

struct Node {
	int64 cnt, cost;
	Node(int64 _cnt, int64 _cost) {
		cnt = _cnt;
		cost = _cost;
	}
};

bool operator < (const Node &a, const Node &b) {
	return a.cost < b.cost;
}

int main()
{
	vector <Node> obj;

	int64 n;
	cin >> n;
	forn(_n, n) {
		int64 a, b;
		cin >> a >> b;
		obj.pb(Node(a, b));
	}
	sort(all(obj));

	int64 t;
	cin >> t;
	vector <int64> p;
	forn(_t, t) {
		int64 tmp;
		cin >> tmp;
		p.pb(tmp);
	}
	sort(all(p));
/*
	for(auto &x: obj)
		cout << x.cnt << " " << x.cost << endl;
	cout <<  endl;
	for(auto &x: p)
		cout << x << " ";
	cout << endl << endl;
*/
	int64 ret = 0, f = 1ll;

	int j = 0, i = 0;

	while(i < obj.size()) {
/*		Pf("p[%d] = %lld, x%lld\n", j, p[j], f);
		forab(k, i, obj.size() - 1)
			Pf("(%lld, %lld) ", obj[k].cnt, obj[k].cost);
		cout << endl;
*/
		if(obj[i].cnt == 0) {
//			Pf("#0\n");
			i++;
		}
		else if(j == p.size()) {
//			Pf("#1\n");
			ret += obj[i].cnt * obj[i].cost * f;
			obj[i].cnt = 0;
			i++;
		}
		else if(obj[i].cnt >= p[j]) {
//			Pf("#2\n");
			ret += obj[i].cost * p[j] * f;
			obj[i].cnt -= p[j];
			p[j] = 0;
			j++;
			f++;
		}
		else {		// obj[i].cnt < p[j]
//			Pf("#3\n");
			ret += obj[i].cnt * obj[i].cost * f;
			p[j] -= obj[i].cnt;
			obj[i].cnt = 0;
			i++;
		}
//		cout << ret << endl << endl;
	}
//	cout << endl;
	
	cout << ret << endl;

	return 0;
}

