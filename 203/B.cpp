#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 111;

int deg[sz], pred[sz];
int isHotel[sz];

int dfs(int u, bool show) {
  if(u ==0 || deg[u] > 1)
    return 0;
  int ret = 1 + dfs(pred[u], show);
  if(show)
    printf("%d ", u);
  return ret;
}

int main()
{
  int N;
  cin >> N;
  for(int i = 1; i <= (int)N; ++i) {
    cin >> isHotel[i];
  }
  for(int i = 1; i <= (int)N; ++i) {
    cin >> pred[i];
    deg[pred[i]]++;
  }

  int mxLen = 0, curIdx = -1;

  for(int i = 1; i <= (int)N; ++i) if(isHotel[i]){
    int len = dfs(i, false);
    if(len > mxLen) {
      curIdx = i;
      mxLen = len;
    }
  }
  cout << mxLen << "\n";
  dfs(curIdx, true);

	return 0;
}

