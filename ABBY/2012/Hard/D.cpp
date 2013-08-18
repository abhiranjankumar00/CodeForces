//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

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
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

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

int main()
{
	int n;
	cin >> n;
	vi num(n*n);

	forn(i, n*n)
		cin >> num[i];

	int sum[10], sumd[10];
	int sumd0, sumd1;
	sort(all(num));

	do {
		CL(sum, 0);
		CL(sumd, 0);
		sumd0 = sumd1 = 0;

		forn(i,n) {
			forn(j, n)
				sum[i] += num[i*n + j], sumd[j] += num[i*n + j];
			sumd0 += num[n*i + i];
			sumd1 += num[n*i + n-1-i];
		}

			
		bool flag = true;
		forn(i, n) {
//			cout << sum[0] << " " << sum [i] << " " << sumd[i] << endl;
			if(sum[0] != sum[i] || sum[0] != sumd[i]) {
				flag = false;
				break;
			}
		}
//		cout << flag << endl;
		flag &= (sum[0] == sumd0 && sum[0] == sumd1) ? true : false;
/*
		forn(i, n)
			cout << sum[i] << " " << sumd[i] << endl;
		cout << sumd0 << " " << sumd1 << endl; 
*/
		if(flag) {
			cout << sum[0] << endl;
			forn(i, n) {
				forn(j, n)
					cout << num[i*n + j] << " ";
				cout << endl;
			}
			return 0;
		}
		
	} while(next_permutation(all(num)));
	
	return 0;
}

