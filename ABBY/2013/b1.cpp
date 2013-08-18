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
#include <functional>	// Don't know why it is here.
#include <numeric>		// +1
#include <cassert>
#include <utility>		// +1
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;

int N;
vector <int> arr;
vector <int> idx;
vector <int> tmp1, tmp2;

int delta(const vector <int> &v) {
	int ans = 0;
	for(int i = 1; i <= v.size()-1; ++i) {
		if(v[i] < v[i-1])
			ans++;
	}
	return ans;
}

int main()
{
	cin >> N;
	arr.resize(N);
	idx.resize(N);

	for(int i = 0; i < N; ++i) {
		cin >> arr[i];
		arr[i]--;
		idx[arr[i]] = i;
	}

	int Q;
	cin >> Q;

	int cnt = 1;
	int id = 1;
	while(id < N) {
		if(idx[id] > idx[id-1])
			;
		else
			cnt++;
		id++;
	}

	while(Q--) {
		int p, x, y;
		cin >> p >> x >> y;
		x--;y--;

		if(p == 1) {
			cout << cnt << endl;
		}
		else {
			tmp1.clear();	tmp2.clear();
			int v = arr[x];
			if(v > 0) {
				tmp1.push_back(idx[v-1]);
				tmp2.push_back(idx[v-1]);
			}
			tmp1.push_back(x);
			tmp2.push_back(y);
			if(v != N-1) {
				tmp1.push_back(idx[v+1]);
				tmp2.push_back(idx[v+1]);
			}

			cnt += (delta(tmp2) - delta(tmp1));

			tmp1.clear();	tmp2.clear();
			v = arr[y];
			if(v > 0) {
				tmp1.push_back(idx[v-1]);
				tmp2.push_back(idx[v-1]);
			}
			tmp1.push_back(y);
			tmp2.push_back(x);
			if(v != N-1) {
				tmp1.push_back(idx[v+1]);
				tmp2.push_back(idx[v+1]);
			}

			cnt += (delta(tmp2) - delta(tmp1));

			swap(arr[x], arr[y]);
			idx[arr[x]] = x;
			idx[arr[y]] = y;

		}
	}
	cout << endl;

	return 0;
}

