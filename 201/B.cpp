#include <bits/stdc++.h>
using namespace std;

int len[111][111][111];
string a, b, c;

/*
int solve(int i, int j, int l) {
  if(i < 0 || j < 0 || k < 0)
    return 0;
  int &ret = len[i][j][k];
  if(ret > -1)
    return ret;
  if(i == 0 || j == 0)
    return ret = 0;
  ret = max(solve(i-1, j, k), solve(i, j-1, k));

  if(a[i]==b[j]) {
    if(k+1 < (int)c.size() && solve(i, j, k+1)>0)
      return 0;
    if(a[i] == c[k]) {
      if(k == 0) {
        return ret = 0;
      }
      else {
        return ret = max(ret, solve(i-1, j-1, k-1)+1);
      }
    }
    else {
      return ret = max(ret, solve(i-1, j-1, k)+1);
    }
  }

  return ret;
}
*/
int solve(int i, int j, int l) {
  if(i == 0 || j == 0 || l == 0)
    return 0;
  int &ret = len[i][j][l];
  ret = max(solve(i-1, j, l), solve(i-1, j, l));

  if(a[i] == b[j]) {
    int k = solve(i-1, j-1, l-1);
    if(a[i] == c[k])
      return k+1;
    else 
      return k;
  }

  return ret;
}

void printPath(int i, int j, int k) {/*{{{*/
  int curLen = solve(i, j, k);
  if(curLen == 0)
    return;
  int lAns = solve(i-1, j, k), tAns = solve(i, j-1, k);
  if(curLen == lAns) {
    printPath(i-1, j, k);
    return;
  }
  if(curLen == tAns) {
    printPath(i, j-1, k);
    return;
  }
  if(a[i] == c[k]) {
    printPath(i-1, j-1, k-1);
    printf("%c", a[i]);
    return;
  }
  else {
    printPath(i-1, j-1, k);
    printf("%c", a[i]);
    return;
  }
}/*}}}*/

int main()
{
  memset(len, -1, sizeof(len));
  cin >> a >> b >> c;
  a = "-" + a;
  b = "-" + b;
  c = "-" + c;

  cout << "a = " << a << "\n";
  cout << "b = " << b << "\n";
  cout << "c = " << c << "\n";

  int aLen = a.size(), bLen = b.size(), cLen = c.size();
  int ans = 0;
  int aIdx=-1, bIdx=-1, cIdx=-1;

  for(int i = 0; i < (int)aLen; ++i) {
    for(int j = 0; j < (int)bLen; ++j) {
      for(int l = 0; l < (int)min(aLen, bLen); ++l) {
        if(solve(i, j, l)  < cLen && ans < l) {
          ans = l;
          aIdx = i, bIdx = j, cIdx = l;
        }
        printf("(%d, %d, %d: %d), ", i, j, l, solve(i, j, l));
      }
    }
  }
  cout << "ans = " << ans << "\n";
  printf("%d, %d, %d: %d\n", aIdx, bIdx, cIdx, ans);

  if(ans == 0)
    cout << ans << "\n";
  else 
    printPath(aIdx, bIdx, cIdx);

	return 0;
}

