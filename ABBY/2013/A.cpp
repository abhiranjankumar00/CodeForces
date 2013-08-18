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

long long Sum(int l, int r, const vector <long long> &sum) {
	return sum[r] - sum[l-1];
}

int main()
{
	int N;
	cin >> N;
	vector <long long> arr(N+1);
	vector <long long> sum(N+1);
	map <long long, long long> fstIdx, lstIdx;
	vector <long long> sol;
	sum[0] = 0;

	for(int i = 1; i <= N; ++i) {
		cin >> arr[i];
		sum[i] = sum[i-1] + max(0ll, arr[i]);

		if(fstIdx.count(arr[i]) == 0)
			fstIdx[arr[i]] = i;

		lstIdx[arr[i]] = i;

		if(lstIdx[arr[i]] != fstIdx[arr[i]])
			sol.push_back(arr[i]);
	}
	sort(sol.begin(), sol.end());
	sol.erase(unique(sol.begin(), sol.end()), sol.end());

	long long mxSum = -1e18;
	long long solVal = -1e18;
	for(auto it = (sol).begin(); it != (sol).end(); ++it) {
		long long v = *it;
		long long add = Sum(fstIdx[v]+1, lstIdx[v]-1, sum);
		add += 2ll*v;
		if(add > mxSum) {
			mxSum = add;
			solVal = v;
		}
	}
	vector <int> pos;
	int l = (int)fstIdx[solVal], r = (int)lstIdx[solVal];

	for(int i = 1; i < l; ++i) {
		pos.push_back(i);
	}
	for(int i = l+1; i <= r-1; ++i) {
		if(arr[i] < 0ll)
			pos.push_back(i);
	}
	for(int i = r+1; i <= N; ++i) {
		pos.push_back(i);
	}

	cout << mxSum << " " << pos.size() << "\n";
	for(auto it = (pos).begin(); it != (pos).end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}

