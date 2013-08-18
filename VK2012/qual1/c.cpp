//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defence Force

#include <iostream>
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
#ifdef __cplusplus
	#undef __cplusplus
	#define __cplusplus 199712L
#endif
*/

#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif

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

vs path;

void printpath() {
	if(path.size() == 0) {
		cout << "/\n";
		return;
	}
	for(auto &s: path)
		cout << "/" << s;
	cout << "/\n";
}

void cd(char st[]) {
	if(st[0] == '/') 
		path.clear();
	char *p = strtok(st, "/");
	if(p != nullptr) {
		ST s(p);
		if(s == ".");
		else if (s == "..")
			path.pop_back();
		else
			path.pb(s);
	}
	while( (p = strtok(nullptr, "/") ) != nullptr) {
		ST s(p);
		if(s == ".");
		else if (s == "..")
			path.pop_back();
		else
			path.pb(s);
	}
}

int main()
{
	char st[1111], *p, delim[] = "/";
	path.clear();

	int n ;
	cin >> n;
	while(n--) {
		ST s1;
		cin >> s1;
		if(s1 == "pwd")
				printpath();
		else {
			cin >> st;
			cd(st);
		}
	}
/*
	while(cin >> st) {
		cout << st << "  ->  ";
		p = strtok(st, delim);
		if(p != nullptr)
			cout << p << " ";
		while( (p = strtok(nullptr, delim)) != nullptr )
			cout << p << " ";
		cout << endl;

	}
*/	
	return 0;
}

