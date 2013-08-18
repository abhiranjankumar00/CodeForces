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

#define Max 100500
bool pr[Max];
/*
void PreProcess()
{
	CL(pr, );
}
*/
int main()
{
	int n;
	cin >> n;
	int a[n];

	forn(i, n)
		Sf("%d", &a[i]);
/*
	forn(i, n)
		cout << a[i] << endl;
*/
	bool found = false;

/*
	forn(i,n)
		Pf("a[%d] = %d , ", i, a[i]);
	cout << endl << endl;

*/
	rep(i, n, 1)	if(n % i == 0 && n/i >= 3)
	{
//		cout << "Size  : "  << i << endl << endl;

		forn(j, i)
		{

//			cout << "Starts at : "  << j << " -> ";

			bool f = true;
			for(int k = j; k < n; k+= i)
			{

//				Pf("a[%d] = %d , ", k, a[k]);

				if(a[k] == 0)
				{
					f = false;
					break;
				}
			}

			if(f)
			{
				found = true;

//				Pf("Polygon starts at : %d and size is : %d\n", j, i);

				cout << "YES"<< endl;
				return 0;
			}

//			cout << "\n\n";
		}
	}

	cout << "NO\n";

	return 0;
}
m[1] = "H"; 	m[2] = "He"; 	m[3] = "Li"; 	m[4] = "Be"; 	m[5] = "B"; 	m[6] = "C"; 	m[7] = "N"; 	m[8] = "O"; 	m[9] = "F"; 	m[10] = "Ne"; 	m[11] = "Na"; 	m[12] = "Mg"; 	m[13] = "Al"; 	m[14] = "Si"; 	m[15] = "P"; 	m[16] = "S"; 	m[17] = "Cl"; 	m[18] = "Ar"; 	m[19] = "K"; 	m[20] = "Ca"; 	m[21] = "Sc"; 	m[22] = "Ti"; 	m[23] = "V"; 	m[24] = "Cr"; 	m[25] = "Mn"; 	m[26] = "Fe"; 	m[27] = "Co"; 	m[28] = "Ni"; 	m[29] = "Cu"; 	m[30] = "Zn"; 	m[31] = "Ga"; 	m[32] = "Ge"; 	m[33] = "As"; 	m[34] = "Se"; 	m[35] = "Br"; 	m[36] = "Kr"; 	m[37] = "Rb"; 	m[38] = "Sr"; 	m[39] = "Y"; 	m[40] = "Zr"; 	m[41] = "Nb"; 	m[42] = "Mo"; 	m[43] = "Tc"; 	m[44] = "Ru"; 	m[45] = "Rh"; 	m[46] = "Pd"; 	m[47] = "Ag"; 	m[48] = "Cd"; 	m[49] = "In"; 	m[50] = "Sn"; 	m[51] = "Sb"; 	m[52] = "Te"; 	m[53] = "I"; 	m[54] = "Xe"; 	m[55] = "Cs"; 	m[56] = "Ba"; 	m[57] = "La"; 	m[58] = "Ce"; 	m[59] = "Pr"; 	m[60] = "Nd"; 	m[61] = "Pm"; 	m[62] = "Sm"; 	m[63] = "Eu"; 	m[64] = "Gd"; 	m[65] = "Tb"; 	m[66] = "Dy"; 	m[67] = "Ho"; 	m[68] = "Er"; 	m[69] = "Tm"; 	m[70] = "Yb"; 	m[71] = "Lu"; 	m[72] = "Hf"; 	m[73] = "Ta"; 	m[74] = "W"; 	m[75] = "Re"; 	m[76] = "Os"; 	m[77] = "Ir"; 	m[78] = "Pt"; 	m[79] = "Au"; 	m[80] = "Hg"; 	m[81] = "Tl"; 	m[82] = "Pb"; 	m[83] = "Bi"; 	m[84] = "Po"; 	m[85] = "At"; 	m[86] = "Rn"; 	m[87] = "Fr"; 	m[88] = "Ra"; 	m[89] = "Ac"; 	m[90] = "Th"; 	m[91] = "Pa"; 	m[92] = "U"; 	m[93] = "Np"; 	m[94] = "Pu"; 	m[95] = "Am"; 	m[96] = "Cm"; 	m[97] = "Bk"; 	m[98] = "Cf"; 	m[99] = "Es"; 	m[100] = "Fm"; 	m[101] = "Md"; 	m[102] = "No"; 	m[103] = "Lr"; 	m[104] = "Rf"; 	m[105] = "Db"; 	m[106] = "Sg"; 	m[107] = "Bh"; 	m[108] = "Hs"; 	m[109] = "Mt"; 	m[110] = "Ds"; 	m[111] = "Rg"; 	m[112] = "Cn"; 	m[113] = "Uut"; 	m[114] = "Uuq"; 	m[115] = "Uup"; 	m[116] = "Uuh"; 	m[117] = "Uus"; 	m[118] = "Uuo"; 	