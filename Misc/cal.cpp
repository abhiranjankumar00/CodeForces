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
	ST d, st[10010];
	set <ST> s[15], ret;
	set <ST> :: iterator it, jt;
	int totLen = 0, lenPerLIne;

	cin >> n;

	forn(i, n)
	{
		cin >> st[i];

		totLen += st[i].length();
		s[st[i].length()].insert(st[i]);
	}

	lenPerLIne = totLen*2/n;

	cin >> d;
	
	forab(i, 1, (lenPerLIne)/2)
	{
		int j = lenPerLIne - i;
		if(i == j)	continue;

		it = s[i].begin();
		jt = s[j].begin();

		while(it != s[i].end() && jt != s[j].end())
		{
//			ST st1 = (*it) + d + (*jt), st2 = (*jt) + d + (*it);
//			cout << st1 << " \t " << st2 << endl;

			if( (*it) + d + (*jt) < (*jt) + d + (*it) )
				ret.insert( (*it) + d + (*jt) );
			else
				ret.insert( (*jt) + d + (*it) );
			it++;
			jt++;
		}

	}

	if( lenPerLIne % 2 == 0)
	{
		int i = lenPerLIne / 2;

		it = s[i].begin();
		jt = it;
		jt++;

		while(it != s[i].end() && jt != s[i].end())
		{
			ret.insert((*it) + d + (*jt));
			it++;
			it++;
			jt++;
			jt++;
		}
	}

//	forab(i, 1, lenPerLIne - 1)
	{
//		tr(it, s[i])
//			cout << *it << ' ';
//		cout << endl;
	}
	
	tr(it, ret)
		cout << *it << endl;

	return 0;
}
