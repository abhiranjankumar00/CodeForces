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

bool is[110];
bool used[110];

bool find(int curSum, int sum)


int main()
{
	map<int, string>m;
	map<string, int>mm;
	
	m[1] = "H"; 	m[2] = "He"; 	m[3] = "Li"; 	m[4] = "Be"; 	m[5] = "B"; 	m[6] = "C"; 	m[7] = "N"; 	m[8] = "O"; 	m[9] = "F"; 	m[10] = "Ne"; 	m[11] = "Na"; 	m[12] = "Mg"; 	m[13] = "Al"; 	m[14] = "Si"; 	m[15] = "P"; 	m[16] = "S"; 	m[17] = "Cl"; 	m[18] = "Ar"; 	m[19] = "K"; 	m[20] = "Ca"; 	m[21] = "Sc"; 	m[22] = "Ti"; 	m[23] = "V"; 	m[24] = "Cr"; 	m[25] = "Mn"; 	m[26] = "Fe"; 	m[27] = "Co"; 	m[28] = "Ni"; 	m[29] = "Cu"; 	m[30] = "Zn"; 	m[31] = "Ga"; 	m[32] = "Ge"; 	m[33] = "As"; 	m[34] = "Se"; 	m[35] = "Br"; 	m[36] = "Kr"; 	m[37] = "Rb"; 	m[38] = "Sr"; 	m[39] = "Y"; 	m[40] = "Zr"; 	m[41] = "Nb"; 	m[42] = "Mo"; 	m[43] = "Tc"; 	m[44] = "Ru"; 	m[45] = "Rh"; 	m[46] = "Pd"; 	m[47] = "Ag"; 	m[48] = "Cd"; 	m[49] = "In"; 	m[50] = "Sn"; 	m[51] = "Sb"; 	m[52] = "Te"; 	m[53] = "I"; 	m[54] = "Xe"; 	m[55] = "Cs"; 	m[56] = "Ba"; 	m[57] = "La"; 	m[58] = "Ce"; 	m[59] = "Pr"; 	m[60] = "Nd"; 	m[61] = "Pm"; 	m[62] = "Sm"; 	m[63] = "Eu"; 	m[64] = "Gd"; 	m[65] = "Tb"; 	m[66] = "Dy"; 	m[67] = "Ho"; 	m[68] = "Er"; 	m[69] = "Tm"; 	m[70] = "Yb"; 	m[71] = "Lu"; 	m[72] = "Hf"; 	m[73] = "Ta"; 	m[74] = "W"; 	m[75] = "Re"; 	m[76] = "Os"; 	m[77] = "Ir"; 	m[78] = "Pt"; 	m[79] = "Au"; 	m[80] = "Hg"; 	m[81] = "Tl"; 	m[82] = "Pb"; 	m[83] = "Bi"; 	m[84] = "Po"; 	m[85] = "At"; 	m[86] = "Rn"; 	m[87] = "Fr"; 	m[88] = "Ra"; 	m[89] = "Ac"; 	m[90] = "Th"; 	m[91] = "Pa"; 	m[92] = "U"; 	m[93] = "Np"; 	m[94] = "Pu"; 	m[95] = "Am"; 	m[96] = "Cm"; 	m[97] = "Bk"; 	m[98] = "Cf"; 	m[99] = "Es"; 	m[100] = "Fm"; 	m[101] = "Md"; 	m[102] = "No"; 	m[103] = "Lr"; 	m[104] = "Rf"; 	m[105] = "Db"; 	m[106] = "Sg"; 	m[107] = "Bh"; 	m[108] = "Hs"; 	m[109] = "Mt"; 	m[110] = "Ds"; 	m[111] = "Rg"; 	m[112] = "Cn"; 	m[113] = "Uut"; 	m[114] = "Uuq"; 	m[115] = "Uup"; 	m[116] = "Uuh"; 	m[117] = "Uus"; 	m[118] = "Uuo"; 	
	mm["H"] = 1; 	mm["He"] = 2; 	mm["Li"] = 3; 	mm["Be"] = 4; 	mm["B"] = 5; 	mm["C"] = 6; 	mm["N"] = 7; 	mm["O"] = 8; 	mm["F"] = 9; 	mm["Ne"] = 10; 	mm["Na"] = 11; 	mm["Mg"] = 12; 	mm["Al"] = 13; 	mm["Si"] = 14; 	mm["P"] = 15; 	mm["S"] = 16; 	mm["Cl"] = 17; 	mm["Ar"] = 18; 	mm["K"] = 19; 	mm["Ca"] = 20; 	mm["Sc"] = 21; 	mm["Ti"] = 22; 	mm["V"] = 23; 	mm["Cr"] = 24; 	mm["Mn"] = 25; 	mm["Fe"] = 26; 	mm["Co"] = 27; 	mm["Ni"] = 28; 	mm["Cu"] = 29; 	mm["Zn"] = 30; 	mm["Ga"] = 31; 	mm["Ge"] = 32; 	mm["As"] = 33; 	mm["Se"] = 34; 	mm["Br"] = 35; 	mm["Kr"] = 36; 	mm["Rb"] = 37; 	mm["Sr"] = 38; 	mm["Y"] = 39; 	mm["Zr"] = 40; 	mm["Nb"] = 41; 	mm["Mo"] = 42; 	mm["Tc"] = 43; 	mm["Ru"] = 44; 	mm["Rh"] = 45; 	mm["Pd"] = 46; 	mm["Ag"] = 47; 	mm["Cd"] = 48; 	mm["In"] = 49; 	mm["Sn"] = 50; 	mm["Sb"] = 51; 	mm["Te"] = 52; 	mm["I"] = 53; 	mm["Xe"] = 54; 	mm["Cs"] = 55; 	mm["Ba"] = 56; 	mm["La"] = 57; 	mm["Ce"] = 58; 	mm["Pr"] = 59; 	mm["Nd"] = 60; 	mm["Pm"] = 61; 	mm["Sm"] = 62; 	mm["Eu"] = 63; 	mm["Gd"] = 64; 	mm["Tb"] = 65; 	mm["Dy"] = 66; 	mm["Ho"] = 67; 	mm["Er"] = 68; 	mm["Tm"] = 69; 	mm["Yb"] = 70; 	mm["Lu"] = 71; 	mm["Hf"] = 72; 	mm["Ta"] = 73; 	mm["W"] = 74; 	mm["Re"] = 75; 	mm["Os"] = 76; 	mm["Ir"] = 77; 	mm["Pt"] = 78; 	mm["Au"] = 79; 	mm["Hg"] = 80; 	mm["Tl"] = 81; 	mm["Pb"] = 82; 	mm["Bi"] = 83; 	mm["Po"] = 84; 	mm["At"] = 85; 	mm["Rn"] = 86; 	mm["Fr"] = 87; 	mm["Ra"] = 88; 	mm["Ac"] = 89; 	mm["Th"] = 90; 	mm["Pa"] = 91; 	mm["U"] = 92; 	mm["Np"] = 93; 	mm["Pu"] = 94; 	mm["Am"] = 95; 	mm["Cm"] = 96; 	mm["Bk"] = 97; 	mm["Cf"] = 98; 	mm["Es"] = 99; 	mm["Fm"] = 100; 	mm["Md"] = 101; 	mm["No"] = 102; 	mm["Lr"] = 103; 	mm["Rf"] = 104; 	mm["Db"] = 105; 	mm["Sg"] = 106; 	mm["Bh"] = 107; 	mm["Hs"] = 108; 	mm["Mt"] = 109; 	mm["Ds"] = 110; 	mm["Rg"] = 111; 	mm["Cn"] = 112; 	mm["Uut"] = 113; 	mm["Uuq"] = 114; 	mm["Uup"] = 115; 	mm["Uuh"] = 116; 	mm["Uus"] = 117; 	mm["Uuo"] = 118; 	

	bool is[110];

	CL(is, 0);

	int n, k;
	cin >> n >> k;

	ST st;
	map<int, string> :: iterator it;

	forn(i, n)
	{
		cin >> st;
		
		it = m.find(st);
		is[it->first] = 1;

	}
	
	forn(_k, k)
	{
		cin >> st;
		CL(used, 0);
		
		if(!Find(0, mm[st]))
			cout << "NO\n";
	}

	return 0;
}
