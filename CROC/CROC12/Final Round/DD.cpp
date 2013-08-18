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
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

struct Node {
	int64 idx, y;
	double len;
	bool operator < (const Node &ob) const {	return this->y < ob.y;	}
	void display() {	Pf("%2lld: %2lld -> %3lf\n", idx, y, len);	}
};
vector <Node> A, B;

int64 inline sq(int64 a)	{return a*a;}
double inline dist(int64 x1, int64 y1, int64 x2, int64 y2)	{return sqrt(1.0*sq(x1-x2) + 1.0*sq(y1 - y2));}

int64 a, b;
int N, M;

double optimise(vector <Node>::iterator itA, vector <Node>::iterator itB, int& l, int& r) {
	double d1 = dist(a, A[l].y, b, B[r].y);
	double d2 = dist(a, itA->y, b, itB->y);
	d1 += A[l].len + B[r].len;
	d2 += itA->len + itB->len;
	if(d2 <= d1) {
		l = itA - A.begin();
		r = itB - B.begin();
	}
	return d2;
}

int main()
{
	cin >> N >> M >> a >> b;
	A = vector <Node> (N);
	B = vector <Node> (M);

	forn(i, N) {
		cin >> A[i].y;
		A[i].idx = i+1;
		A[i].len = dist(0, 0, a, A[i].y);
	}
	forn(i, M) {
		cin >> B[i].y;
		B[i].idx = i+1;
	}
	forn(i, M)
		cin >> B[i].len;

	sort(all(A));
	sort(all(B));
/*
	Pf("West Bank\n");
	tr(it, A)	it->display();		cout << endl;
	Pf("East Bank\n");
	tr(it, B)	it->display();		cout << endl;
*/
	Node toSearch;
	int l = 0, r = 0;
	tr(itB, B) {
		int64 y = (itB->y * a) / b;
		toSearch.y = y;

		auto itA = lower_bound(all(A), toSearch);
/*
		Pf("West Side: ");
		itB->display();
		DEBUG(y);
*/
//		Pf("East Side:\n");
		auto it = itA;
		if(itA != A.end()) {
			optimise(itA, itB, l, r);
//			itA->display();
		}

		it = itA;
		forn(lll, 2)	if(it != A.begin()) {
			it--;
			optimise(it, itB, l, r);
//			it->display();
		}
		it = itA;
		it++;
		if(itA != A.end()) forn(jjj, 2)	if(it != A.end()) {
			optimise(it, itB, l, r);
//			it->display();
			it++;
		}
//		cout << endl;
	}

	double d = dist(a, A[l].y, b, B[r].y) + A[l].len + B[r].len;
//	A[l].display();
//	B[r].display();
//	DEBUG(d);
	cout << A[l].idx << " " << B[r].idx << endl; 

	return 0;
}

