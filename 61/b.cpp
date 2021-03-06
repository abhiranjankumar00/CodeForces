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
typedef string ST;
typedef stringstream SS;
typedef vector<vi> vvi;
typedef vector<ST> vs;
typedef pair<int,int> ii;

#define Pf	printf
#define	Sf	scanf

//#define PI	3.141592653589793
//#define E	2.718281828459045
#define PI	(2*acos(0))
#define E	(exp(1))
#define	ep	1e-9

#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp	make_pair

#define pb	push_back
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0; i < n; i++)
#define forab(i, a, b)	for(int i = a; i <= b; i++)
#define rep(i, a, b)	for(int i = a; i>=b; i--)

int n, ht[2000], water[2000];

void Process(int idx)
{
	water[idx] = 1;

	rep(i, idx-1, 0)
	{
		if(ht[i] <= ht[i+1])
			water[idx]++;
		else
			break;
	}
	forab(i, idx+1, n-1)
	{
		if(ht[i] <= ht[i-1])
			water[idx]++;
		else
			break;
	}
}


int main()
{

	while(cin >> n)
	{
		CL(water, 0);
		forn(i, n)	cin >> ht[i];

		forn(i, n)
			Process(i);

		cout << *max_element(water, water+n) << endl;
	}
	

	return 0;
}
