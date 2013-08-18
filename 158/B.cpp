//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

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
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl		("\n")
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)
// /*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
// */

string date;
map <string, int> m;
int mx = 0;

bool isValid(const string & d) {
	if(d.size() != 10)
		return false;
	
	forn(i, 10) {
		if(i == 2 || i == 5) {
			if(d[i] != '-')
				return false;
		}
		else {
			if(d[i] < '0' || d[i] > '9')
				return false;
		}
	}
	string dd = d.substr(0, 2), mm = d.substr(3, 2), yy = d.substr(6);
	int ddd = atoi(dd.c_str());
	int mmm = atoi(mm.c_str());
	int yyy = atoi(yy.c_str());

	if(yyy < 2013 || yyy > 2015)
		return false;
	if(mmm < 1 || mmm > 12)
		return false;

	if(mmm == 2) {
		if(ddd < 1 || ddd > 28)
			return false;
	}
	 else if((mmm <= 7 && mmm % 2 == 1 ) || (mmm >= 8 && mmm % 2 == 0)) {
		if(ddd < 1 || ddd > 31)
			return false;
	}
	else {
		if( ddd < 1 || ddd > 30)
			return false;
	}

	DEBUG(d);
	DEBUG(ddd);
	DEBUG(mmm);
	DEBUG(yyy);
	m[d] ++;
	mx = max(mx, m[d]);
}

int main()
{
	cin >> date;
	DEBUG(date);

	forn(i, date.size()) {
		isValid(date.substr(i, 10));
	}

	//cout << endl;
	//tr(it, m)
	//	cout << it->first << ": " << it->second << endl;

	tr(it, m)	if(it->second == mx)
		cout << it->first << endl;

	return 0;
}

