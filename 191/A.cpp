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

int cntElements(int l, int r, const vector <int> &arr) {
	return  r < l ? 0 : ((l == 0 ? 0 : -arr[l-1]) + arr[r]);
}

int main()
{
	int N;
	cin >> N;
	vector <int> arr(N);
	vector <int> cntZero(N, 0), cntOne(N, 0);

	for(int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	(arr[0] == 0 ? cntZero[0] : cntOne[0]) = 1;
	for(int i = 1; i <= N-1; ++i) {
		cntOne[i] = cntOne[i-1];
		cntZero[i] = cntZero[i-1];
		(arr[i] == 0 ? cntZero[i] : cntOne[i])++;
	}

	int mx = cntZero.back();
	for(int i = 0; i < N; ++i) {
		for(int j = i; j <= N-1; ++j) {
			mx = max(mx, cntElements(0, i-1, cntOne) + cntElements(i, j, cntZero) + cntElements(j+1, N-1, cntOne));
		}
	}
	cout << mx << "\n";

	return 0;
}

