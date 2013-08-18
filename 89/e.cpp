#include <iostream>
#include <set>
#include <list>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

#define forab(i, a, b)	for(int i = (a), _loop_ends_here = (b); i <= (_loop_ends_here); (i)++)
#define forn(i, a)	forab(i, 0, (a)-1)
#define mp(a, b)	make_pair((a), (b))
#define read(n)		scanf("%d", &(n))
#define tr(it, v)	for( typeof((v).begin()) it = (v).begin(); it != v.end(); it++ )
#define all(v)		(v).begin(), (v).end()

void dfs(int a, vector < set<int> > &out, list <int> &order, vector <bool> &vis) {
	if(vis[a])
		return;
	vis[a] = true;

	tr(it, out[a])	if(!vis[*it])
		dfs(*it, out, order, vis);
			
	order.push_front(a);
}

void dfs_rev(int a, vector < set<int> > &in, vector <bool> &vis, vector < pair<int, int> > &ans) {
	if(vis[a])	return;

	vis[a] = true;

	tr(it, in[a])	if(!vis[*it])
		dfs_rev(*it, in, vis, ans), 	ans.push_back(mp(a, *it));
}

int main() {
	int n, m;
	cin >> n >> m;
	vector <set<int> > in(n+1), out(n+1);
	vector <bool> vis(n+1, false);
	list <int> order;
			
	forn(i, m) {
		int a, b;
		read(a);
		read(b);
		in[a].insert(b);
		in[b].insert(a);
		out[a].insert(b);
		out[b].insert(a);
	}

	forab(i, 1, n)	if(!vis[i])
		dfs(i, out, order, vis);

	tr(it, order)
		cout << *it << " ";
	cout << endl;

	fill(all(vis), false);
	vector < pair<int, int> > ans;
	ans.clear();

	dfs_rev(order.front(), in, vis, ans);

	forab(i, 1, n)	if(!vis[i]) {
		cout << 0 << endl;
		return 0;
	}

	tr(it, ans) 
		printf("%d %d\n", it->first, it->second);

	return  0;
}
