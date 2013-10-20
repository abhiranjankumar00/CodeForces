#include <bits/stdc++.h>
using namespace std;

long long solve(int l, int r, const vector <long long> &arr) {
  int ret = 0;
  for(; l < r; l++, r--){
    ret += arr[l]/1000*1000;
    ret += (arr[l]/1000+1)*1000;
  }
  return ret;
}

bool compare(long long a, long long b) {
  return (a - a/1000*1000) < (b - b/1000*1000);
}

int main()
{
  int N;
  double tmp;
  cin >> N;
  N *= 2;
  vector <long long> a(N);
  for(int i = 0; i < (int)N; ++i) {
    cin >> tmp;
    a[i] = (long long)(tmp*1000+1e-6);
  }
  long long origSum = accumulate(a.begin(), a.end(), 0ll);

  vector <long long> complete, partial;
  for(int i = 0; i < (int)N; ++i) {
    if(a[i] % 1000 == 0)
      complete.push_back(a[i]);
    else
      partial.push_back(a[i]);
  }
  sort(partial.begin(), partial.end(), compare);
  cout << "partial.size() = " << partial.size() << "\n";

  if(partial.size() % 2 == 0) {
    long long curSum = solve(0, partial.size()-1, partial) ;

    cout << "origSum = " << origSum << "\n";
    cout << "curSum = " << curSum << "\n";

    curSum += accumulate(complete.begin(), complete.end(), 0ll);
    cout << "curSum = " << curSum << "\n";

    printf("%0.3lf\n", abs(origSum-curSum)/1000.0);
  }

	return 0;
}

