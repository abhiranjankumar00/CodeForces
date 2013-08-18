//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
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
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater than 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
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

#if (0 or defined ONLINE_JUDGE)
	#define DEBUG
#else 
	#define DEBUG(x)	cout << #x << " = " << x << "\n"
#endif

const int sz = 2e5 + 111;

int64 tree[4*sz];
int N;
int64 arr[sz];
int64 new_arr[sz], sum[sz];
int freq[sz];
vector < ii > v, q;

void update(int i, int j, int add = 1,  int node = 1, int l = 0, int r = N-1) {
	assert(l <= r);
	if(l >= i && r <= j) {
		tree[node]++;
		return;
	}
	if(r < i)
		return;
	if(l > j)
		return;
	int mid = (l+r)/2;
	update(i, j, add, 2*node, l, mid);
	update(i, j, add, 2*node+1, mid+1, r);
}

void purge(int sum = 0, int node = 1, int l = 0, int r = N-1) {
	sum += tree[node];
	assert(l <= r);
	if(l == r) {
		freq[l] +=  sum;
		v.pb(mp(freq[l], l));
		return;
	}
	int mid = (l+r)/2;
	purge(sum, 2*node, l, mid);
	purge(sum, 2*node+1, mid+1, r);
}

int main()
{
	int Q;
	cin >> N >> Q;

	forn(i, N)
		cin >> arr[i];
	sort(arr, arr+N, greater <int64>());

	while(Q--) {
		int a, b;
		cin >> a >> b;
		q.pb(mp(a-1, b-1));
		update(a-1, b-1);
	}

	purge();
	sort(all(v), greater < ii > ());
/*
	cout << "arr: ";
	forn(i, N)
		cout << arr[i] << " ";
	cout << endl;
*/
	int id = 0;
	tr(it, v) {
		int idx = it->second, val = it->first;
		new_arr[idx] = arr[id++];
//		cout << idx << " - " << val << endl;
	}
//	cout << endl;
/*
	cout << "arr: ";
	forn(i, N)
		cout << new_arr[i] << " ";
	cout << endl;
*/
	forn(i, N) {
		if(i == 0)
			sum[i] = new_arr[i];
		else
			sum[i] = sum[i-1]+new_arr[i];
	}

	int64 ans = 0;
	tr(it, q) {
		int l = it->first, r = it->second;
		ans += sum[r];
		if(l > 0)
			ans -= sum[l-1];
	}
	cout << ans << endl;

	return 0;
}

