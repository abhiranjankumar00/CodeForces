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

struct trie {
	int cnt;
	trie *ch[2];
	trie () {
		cnt = 0;
		ch[0] = ch[1] = NULL;
	}

} root;

void insert(int val,  int idx = 30, trie *nd = &root) {
	nd->cnt++;
	if(idx < 0)
		return;
	int id = (val & (1<<idx) ) == 0 ? 0 : 1;

	if(nd->ch[id] == NULL)
		nd->ch[id] = new trie();

	insert(val, idx-1, nd->ch[id]);
}

void erase(int val, int idx = 30, trie *nd = &root) {
	nd->cnt--;

	if(idx >= 0) {
		int id = (val & (1<<idx)) == 0 ? 0 : 1;
		erase(val, idx-1, nd->ch[id]);
	}

	if(nd->cnt == 0)
		delete nd;

}

int find(int val, int idx = 30, trie *nd = &root, int ans = 0) {
	assert(nd != NULL);
	if(idx < 0)
		return ans;

	int id = (val & (1<<idx)) == 0 ? 0 : 1;

	if(nd->ch[1-id] != NULL)
		return find(val, idx-1, nd->ch[1-id], ans | (1<<idx));
	return find(val, idx-1, nd->ch[id], ans);
}

const int sz = 1e5 + 111;
set <int> st;
int N;
int a[sz];

int main()
{
	read(N);
	forn(i, N)
		read(a[i]);

	int mx = max(a[0], a[1]);
	insert(a[0]);
	insert(a[1]);
	int ans = a[0] ^ a[1];

	forab(i, 2, N-1) {
		if(a[i] > mx) {
			st.insert(a[i]);
			insert(a[i]);
			mx = a[i];
		}
	}

	forn(i, N-1) {
		int r = i+1;

		while(r < N && st.find(a[r]) == st.end()) {
			st.insert(a[r]);
			insert(a[r]);
			r++;
		}

		erase(a[i]);
		st.erase(a[i]);
		ans = max(find(a[i]), ans);
	}
	cout << ans << endl;

	return 0;
}

