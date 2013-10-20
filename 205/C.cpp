#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5+111;
int N;
int a[sz], sum[sz];
string binary;

int main()
{
  cin >> N;
  for(int i = 0; i < (int)N; ++i) {
    cin >> a[i];
  }
  cin >> binary;
  reverse(a, a+N);
  reverse(binary.begin(), binary.end());

  sum[N-1] = a[N-1];
  for(int i = (int)N-2; i >= (int)0; --i) {
    sum[i] = a[i] + sum[i+1];
  }

  long long ret = 0, curSum = 0;

  for(int i = 0; i < (int)N; ++i) {
    if(binary[i] == '1') {
      long long tmpSum = curSum + sum[i+1];
      ret = max(ret, tmpSum);
      curSum += a[i];
    }
    ret = max(curSum, ret);
  }
  cout << ret << "\n";


	return 0;
}

