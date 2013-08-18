//%%%%%%%%%%%%
//%%%%lost%%%%
//%%%%%%%%%%%%

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

typedef long long  int64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef string ST;
typedef stringstream SS;

#define Pf	printf
#define	Sf	scanf

#define	ep	1e-9
#define	CL(a, b)	memset(a, b, sizeof(a))

#define pb	push_back
#define mp	make_pair
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0; i < n; i++)
#define forab(i, a, b)	for(int i = a; i <= b; i++)
#define rep(i, a, b)	for(int i = a; i>=b; i--)

int main()
{
	int n;

	while(cin >> n)
	{
		int x = n;
		if(n == 1)
		{
			cout << 1 << endl;
			continue;
		}

		map < int, int > m;

		forab(i, 2, n)
		{
			while(n % i == 0)
			{
				m[i]++;
				n /= i;
			}
		}

		int mx = 0, el = 1;

//		cout << "For n = " << x << endl;

		tr(it, m)
		{
//			Pf("%d ->  %d \t ", it->first, it->second);

			if(it->second > mx)
			{
				mx = it->second;
				el = it->first;
			}
			else if(it->second == mx)
				el = max(el, it->first);
		}

//		Pf("\nElement = %d , occurance = %d\n\n", el, mx);

		int num = el;

		while(num * el <= x)
			num *= el;

		if(num != x)
			cout << x << ' ';

		while(num >= 1)
		{
			cout << num << ' ';
			num /= el;
		}

		cout << endl;

	}

	return 0;
}
