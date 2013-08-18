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

typedef long long int64;

struct Node {
 int64 idx, y;
 double len;
 bool operator < (const Node &ob) const { return this->y < ob.y; }
};
vector <Node> A, B;

int64 inline sq(int64 a) {return a*a;}
double inline dist(int64 x1, int64 y1, int64 x2, int64 y2) {return sqrt(1.0*sq(x1-x2) + 1.0*sq(y1 - y2));}

int64 a, b;
int N, M;

void optimise(vector <Node>::iterator itA, vector <Node>::iterator itB, int& l, int& r) {
 double d1 = dist(a, A[l].y, b, B[r].y);
 double d2 = dist(a, itA->y, b, itB->y);
 d1 += A[l].len + B[r].len;
 d2 += itA->len + itB->len;
 if(d2 <= d1) {
  l = itA - A.begin();
  r = itB - B.begin();
 }
}

int main()
{
 cin >> N >> M >> a >> b;
 A = vector <Node> (N);
 B = vector <Node> (M);

 for(int i = 0, lets_stop_here = (int)N; i < lets_stop_here; i++) {
  cin >> A[i].y;
  A[i].idx = i+1;
  A[i].len = dist(0, 0, a, A[i].y);
 }
 for(int i = 0, lets_stop_here = (int)M; i < lets_stop_here; i++) {
  cin >> B[i].y;
  B[i].idx = i+1;
 }
 for(int i = 0, lets_stop_here = (int)M; i < lets_stop_here; i++)
  cin >> B[i].len;

 sort((A).begin(), (A).end());
 sort((B).begin(), (B).end());

 Node toSearch;
 int l = 0, r = 0;
 for(__typeof((B).begin()) itB = (B).begin(); itB != (B).end(); itB++) {
  int64 y = (itB->y * a) / b;
  toSearch.y = y;

  auto itA = lower_bound((A).begin(), (A).end(), toSearch);
  auto it = itA;

  it = itA;
  for(int lll = 0, lets_stop_here = (int)2; lll < lets_stop_here; lll++) if(it != A.begin()) {
   it--;
   optimise(it, itB, l, r);
  }
  it = itA;
  for(int jjj = 0, lets_stop_here = (int)3; jjj < lets_stop_here; jjj++) if(it != A.end()) {
   optimise(it, itB, l, r);
   it++;
  }
 }

 cout << A[l].idx << " " << B[r].idx << ("\n");

 return 0;
}
