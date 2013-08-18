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
#ifdef __cplusplus
	#undef __cplusplus
	#define __cplusplus 199712L
#endif
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

const int sz = 1e7 + 100;
int par[sz];
int N, M;
int A[sz], B[sz];
int comA[sz], comB[sz];

void factorize(int sz, int AA[], int count[]) {
	forn(i, sz) {
		int x = AA[i];
		while(x != par[x]) {
			count[par[x]]++;
			x /= par[x];
		}
		if(x != 1)
			count[x]++;
	}
}

void Reduce(int sz, int Arr[], int count[]) {
	forn(i, sz) {
		int x = Arr[i];

		while(x > 1) {
			if(count[par[x]]) {
				count[par[x]]--;
				Arr[i] /= par[x];
			}
			x /= par[x];
		}
	}
}

int main()
{
	forn(i, sz)
		par[i] = i;
	for(int i = 2; i*i < sz; i ++)		
		if(par[i] == i)
			for(int j = i+i; j < sz; j+=i)
				par[j] = i;

	read(N);
	read(M);
#ifdef DEBUG
	#undef DEBUG
	#define DEBUG
#endif

	DEBUG(N);
	DEBUG(M);
	forn(i, N)	
		read(A[i]);
	DEBUG(A[0]);
	forn(i, M)
		read(B[i]);
	DEBUG(B[0]);
	

	factorize(N, A, comA);
	DEBUG("fact(A)");
	factorize(M, B, comB);
	forn(i, sz)
		comA[i] = comB[i] = min(comA[i], comB[i]);


	Reduce(N, A, comA);
	Reduce(M, B, comB);

	cout << N << " " << M << endl;
	forn(i, N)
		write(A[i]);
	cout << endl;
	forn(i, M)
		write(B[i]);
	cout << endl;

	return 0;
}

