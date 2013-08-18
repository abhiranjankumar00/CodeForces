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

const int sz = 1e6 + 111;
int ways[sz];
int main()
{
	ways[0] = 0;
	for(int i = 1; i <= sz-1; ++i) {
		int v = i;
		ways[i] = 1e9;
		while(v > 0) {
			int s = v%10;
			v/=10;
			if(s == 0)
				continue;
			ways[i] = min(ways[i], ways[i-s] + 1);
		}
	}
	int len = 1;
	int sum = 0;
	printf("0," );
	for(int i = 1; i < 1000; ++i) {
		if(ways[i] != ways[i-1]) {
			sum += len;
			printf("%d,", sum );
	//		printf("(%d: %d), ", ways[i], len);
			len = 1;
		}
		else
			len++;
	}
	return 0;
	int N;
	cin >> N;
	cout << ways[N];

	return 0;
}

