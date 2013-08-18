#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9
#define	Sf		scanf
#define	Pf		printf

#define pb		push_back
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

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

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;

#define	all(c)		(c).begin(), (c).end()
#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

void print(ST& num, ST & dec) {
	cout << "$" << num << "." << dec ;
}

void print(ST &num, ST &dec, bool neg) {
	if(neg) {
		cout << "(";
		print(num, dec);
		cout << ")";
	}
	else
		print(num, dec);
}

int main()
{
	ST st;
	bool neg = false;
	char num[1000] ={}, dec[1000] = {};
	
	Sf("%[^.\n]", num);
	if(num[0] == '-') {
		st =  string(num+1);
		neg = true;
	}
	else
		st = string(num);

	ST ans = "";
	reverse(all(st));

	forn(i, st.size()) {
		ans += st[i];
		if((i+1)%3==0 && i+1 != st.size())
			ans += ",";
	}
	reverse(all(ans));
//	cout << ans << endl;

	Sf("%[^\n]", dec);
	ST d;
	if(strlen(dec+1)==0) {
		d = "00";
	}
	else {
		d = string(dec+1);
		if(d.size() > 2)
			d = d.substr(0, 2);
		if(d.size() == 1)
			d += "0";
	}

	print(ans, d, neg);

//	cout << dec+1 << endl << strlen(dec+1);

//	cout << dec << endl;




	

	return 0;
}

