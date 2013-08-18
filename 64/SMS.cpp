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
	int n, ret = 1, idx = 0;
	bool f = false, newWord = true;
	ST st, word, tmp;
	vs sen;

	Sf("%d\n", &n);
	getline(cin, st);

	SS ss(st);

	st.clear();
	tmp.clear();
	word.clear();

//	vs :: iterator it = sen.begin();

	while(ss >> st)
	{

		if(st.length() > n)
		{
			f = true;
			break;
		}

		if(newWord)
		{
//			cout << "#1" << endl;

			newWord = false;
			sen.pb(st);
//			it++;
//			cout << "#2" << endl;
		}
		else
		{
//			cout << "#3" << endl;

			int i = SZ(sen)-1;

			sen[i] = sen[i] + " " + st;

//			*it = *it + " " + st;
//			cout << "#4\n";
		}
		
		char ch = st[st.length() -1];

		if(ch == '.' || ch == '?' || ch == '!')
			newWord = true;

//		cout << st.length() << " -> " << st << " ->" << ch << endl;
	}
/*
	tr(it, sen)
		cout << *it << endl;
*/

	int len = 0;
	st.clear();
	tmp.clear();

//	cout << n << endl;

	if(!f)	tr(it, sen)
	{
		tmp = st + " " + *it;

//		cout << tmp << endl;

		if(tmp.length() > n)
		{
//			cout << st << endl;

			ret++;
			st.clear();
			st = *it;
		}
		else if(st.length() == 0)
			st = st + *it;
		else
			st = st + " " + *it;
		if(st.length() > n)
		{
			f = true;
			break;
		}
	}

	if(st.length() > n)
		f = true;

//	cout << st << endl;

//	if(!f) tr(it, sen)
//		cout << it->length() << " -> " << *it << endl;

	if(f)
		cout << "Impossible\n";
	else
		cout << SZ(sen) << endl;


	return 0;
}
