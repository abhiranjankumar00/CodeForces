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

const long long p = 1e9 + 7;

long long  power(long long a, long long b) {
	a %= p;
	if(b == 0)
		return 1ll;
	long long ret = power(a, b/2);
	ret = (ret * ret) % p;
	if(b % 2 == 1ll)
		ret = (ret*a)%p;
	return ret;
}

long long inverse(long long a) {
	return power(a, p-2);
}

int main()
{
	string n;
	int N, K;

	cin >> n >> K;
	N = n.size();

	long long num = (power(2ll, (1ll*K)*N) - 1 + p ) % p;
	long long den = (power(2ll, 1ll*N) - 1 + p) % p;
	den = inverse(den);

	long long ans = 0;

	for(int a = 0; a < N; ++a) {
		if(n[a] == '0' || n[a] == '5')
			ans = (ans + power(2ll, a*1ll)) % p;
	}

	ans *= (num*den)%p;
	ans %= p;
	cout << ans << "\n";


	return 0;
}

