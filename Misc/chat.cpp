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
	ST s, h = "hello";

	while(cin >> s)
	{
		int j = 0;

		forn(i, s.length())
		{
			if(j == 5)	break;
			if(s[i] == h[j])	j++;
		}

		if(j == 5)	cout << "YES\n";
		else		cout << "NO\n";
	}
	

	return 0;
}
