#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iterator>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<string> vs;
ST a, b;
int ans = 0;

void process(char cl, char cr) {
	int l = 0, r = a.size() - 1;
	int len = a.size();

	while(l < len && r >= 0) {
		if(a[l] == b[l])
			l++;
		else if(a[r] == b[r])
			r--;
		else if(a[l] != cl)
			l++;
		else if(a[r] != cr)
			r--;
		else {
			swap(a[l], a[r]);
			l++;
			r--;
			ans++;
		}
	}
}

int main()
{
	cin >> a >> b;
	process('4', '7');
	process('7', '4');

	for(int i = 0, lets_stop_here = (int)a.size(); i < lets_stop_here; i++)
		if(a[i] != b[i])
			ans++;
	printf("%d\n", ans);

	return 0;
}
