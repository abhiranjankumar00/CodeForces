#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  int bowl = 0, plates = 0;
  for(int i = 0; i < (int)n; ++i) {

    int t ;
    cin >> t;
    if(t == 1)
      bowl++;
    else
      plates++;
  }
  int ans = 0;

  if(bowl >= m){
    ans = (bowl-m);
    m = 0;
  }
  else {
    m-= bowl;
  }
  ans += max(0,plates- (k+m) );
  cout << ans ;

  return 0;
}

