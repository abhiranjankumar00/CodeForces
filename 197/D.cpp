#include <bits/stdc++.h>
using namespace std;

int tree[1<<20] ;

bool update(int id, int val, int node, int l, int r) {
	if(l == r) {
		tree[node] = val;
		return true;
	}
	int mid = (l+r)/2;
	bool isOr = id <= mid ? update(id, val, 2*node, l, mid):update(id, val, 2*node+1, mid+1, r);
	tree[node] = isOr? tree[2*node]|tree[2*node+1] : tree[2*node]^tree[2*node+1];
	return !isOr;
}

int main()
{
	int N, M, p, v;
	cin >> N >> M;
	N = 1 << N;
	for(int i = 1; i <= N+M; ++i) {
		if(i <= N) {
			cin >> v;
			p = i;
		}
		else 
			cin >> p >> v;
		update(p, v, 1, 1, N);
		if(i > N)
			cout << tree[1] << "\n";
	}
	return 0;
}
