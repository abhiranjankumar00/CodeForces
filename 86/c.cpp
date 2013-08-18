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

void fail() {
	cout << "NO";
	exit(0);
}

bool isMale(const ST & a) {
//	ST t = a.substr(a.length() - 2);
//	if(t == "os" || t == "er" || t == "is")
	if(a == "os" || a == "tr" || a == "is")
		return true;

	if(a == "la" || a == "ra" || a == "es")
		return false;

//	fail();
	assert(false);

	return  false;
}

enum parts {adj, noun, verb};

parts Type(const ST & a) {
	if(a == "os" || a == "la")
		return adj;
	if(a == "tr" || a == "ra")
		return noun;
	if(a == "is" || a == "es")
		return verb;
//	fail();
	assert(false);
	return adj;
}


bool valid(const ST &st) {
	int len = st.length();

	if(len > 3 && st.substr(len - 4) == "lios")
		return true;
	if(len >4 && st.substr(len - 5) == "liala")
		return true;
	if(len > 2 && st.substr(len - 3 ) == "etr")
		return true;
	if(len > 3 && st.substr(len - 4) == "etra")
		return true;
	if(len > 5 && st.substr(len - 6) == "initis")
		return true;
	if(len > 5 && st.substr(len - 6) == "inites")
		return true;
	return false;
}

int main()
{
	ST st;
	bool gender; 
	int cnt= 0;
	parts lst, cur;
	bool f = true;
	int idx = 0;

	while(cin >> st) {
		if(!valid(st))
			fail();

		st = st.substr(st.length() - 2);

		cur = Type(st);
		
		if(cur == noun)
				cnt++;

		if(f) {
			gender = isMale(st);
			lst = cur;
			if(lst == verb)
				fail();

			f = false;
		}
		else {
			if(gender != isMale(st))
				fail();
			if( (lst == adj && cur == verb) || (lst == noun && cur == noun) || ( lst == verb && cur != verb) ) 
				fail();
		}
		lst = cur;
		idx++;
	}

	if(cnt != 1 && idx != 1) 
		fail();

	cout << "YES";

	return 0;
}

