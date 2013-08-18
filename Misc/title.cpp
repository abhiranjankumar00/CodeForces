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


void Print(int k, int vis[])
{
	forab(i, 0, k)
		cout << i << " : " << vis[i] << endl;
	cout << endl;
}

int main()
{
	int vis[30];
	int k;
	ST st;

	while(cin >> k)
	{
//		cout << endl << endl;
		cin >> st;
//		cout << st << endl;
		--k;

		forn(i, 28)	vis[i] = 0;
		int len = st.length();

//		Print(k, vis);
		forn(i, len)	if(st[i] != '?')
		{
			int idxx = st[i] - 'a';
			vis[ idxx]  = 1;
		}

//		Print(k, vis);

		int idx = 0;

		bool f = true;
		
		idx = 0;

		rep(j, k , 0)	if(!vis[j])
		{
			idx = j;
		//	vis[idx] = 1;
			break;
		}

		if(f && len % 2 == 1 && st[len/2] == '?')
		{
			st[len/2] = idx + 'a';
			vis[idx] = 1;
		}

		rep(i, len/2 - 1, 0)
		{
			//cout << st << endl;
//			Print(k, vis);

			idx = 0;

			rep(j, k , 0)	if(!vis[j])	
			{
				idx = j;
				break;
			}

			if(st[i] == '?')
			{
				if(st[len - i - 1 ] == '?')
					st[len-i-1] = idx + 'a';
				st[i] = st[len-i-1] ;
				vis[idx] = 1;
			}
			else if(st[len-i-1] == '?')
			{
				st[len-i-1] = st[i];
			}
			else if( st[i] != st[len-i-1] )
			{
				f = false;
				break;
			}

		}


		if(f)	forab(i, 0, k)	if(!vis[i])
		{
			f = false;
			break;
		}

		if(f)
			cout << st << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}

	

	return 0;
}
