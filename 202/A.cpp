#include <bits/stdc++.h>
using namespace std;


int main()
{
  long long sum = 0, tmp;
  int n;
  cin >> n;
  for(int i = 0; i < (int)n; ++i) {
    cin >> tmp;
    sum += tmp;
  }
  cout << (sum/(n-1)) + (sum%(n-1)>0?1:0)<<"\n";


	return 0;
}

