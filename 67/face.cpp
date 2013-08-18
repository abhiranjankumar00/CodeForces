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
typedef vector< vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<string> vs;

#define Pf	printf
#define	Sf	scanf

#define PI M_PI
#define E M_E
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

int main()
{
	ST name, n1, n2, tmp;
	int n;
	map<ST, int>m;

	cin >> name >> n;

	forn(_n, n) {
		cin >> n1 >> tmp;
		if(tmp[0] == 'l') {
			cin >> n2 >> tmp;
			n2 = n2.substr(0, n2.length()-2);
			if(n1 == name || n2 == name)
				m[n1] += 5, m[n2] += 5;
			else
				m[n1] = m[n1], m[n2] = m[n2];
		}
		else if(tmp[0] == 'c') {
			cin >> tmp >> n2 >> tmp;
			n2 = n2.substr(0, n2.length()-2);
			if(n2 == name || n1 == name)
				m[n1] += 10, m[n2] += 10;
			else
				m[n1] = m[n1], m[n2] = m[n2];
		}
		else
		{
			cin >> tmp >> n2 >> tmp;
			n2 = n2.substr(0, n2.length()-2);
			if(n1 == name || n2 == name)
				m[n1] += 15, m[n2] += 15;
			else
				m[n1] = m[n1], m[n2] = m[n2];
		}
	}
/*
	tr(it, m)	
		cout << it->first << " " << it->second << endl;

*/
	map <int, vector<ST>,  greater<int>  > mm;

	tr(it, m)
	{
		int n = it->second;
		ST t = it->first;
		if(present(n, mm)) 
			mm[n].pb(t);
		else
		{
			mm[n] = vector<ST> ();
			mm[n].pb(t);
		}

	}

	tr(it, mm)
	{
//		cout << it->first << " ";
		vector <ST> vvs = it->second;
		sort(all(vvs));
		tr(jt, vvs) 	if(*jt != name)
			cout << *jt << endl;
	}


	return 0;
}
