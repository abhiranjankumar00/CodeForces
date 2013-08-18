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

int main()
{
	const int N = 1e7;
	vector <bool> isPrime(N, true);
	vector <int> prime;
	isPrime[0] = isPrime[1] = false;

	for(int i = 2; i* i < N; i++) if(isPrime[i]) {
		for(int j = i+i; j < N; j+=i)
			isPrime[j]  = false;
	}
	for(int i = 0; i < N; ++i) {
		if(isPrime[i])
			prime.push_back(i);
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		printf("%d ", prime[i]);
	}

	return 0;
}

