#include <bits/stdc++.h>
using namespace std;

bool compare(double a, double b) {
  return a - floor(a) < b - floor(b);
}

double solve(int l, int r, vector <double> &a) {
  double ret = 0;
  for(; l < r; l++, r--) {
    double s1 = ceil(a[l]) + floor(a[r]);
    double s2 = ceil(a[r]) + floor(a[l]);
    if(abs(s1 - a[l] - a[r]) < abs(a[r] + a[l] - s2))
      ret += s1;
    else
      ret += s2;
  }
  return ret;
}

int main()
{
  int N;
  cin >> N;
  N <<= 1;
  vector <double> a;
  double origSum = 0, tmp, curSum = 0;
  
  for(int i = 0; i < (int)N; ++i) {
    cin >> tmp;
    origSum += tmp;
    if(tmp - floor(tmp) > 1e-6) {
      a.push_back(tmp);
    }
    else {
      curSum += tmp;
    }
  }

  sort(a.begin(), a.end(), compare);
  if(a.size() % 2 == 0){
    curSum += solve(0, a.size()-1, a);
    printf("%0.3lf\n", abs(origSum - curSum));
  }
  else {
    double s1 = curSum + solve(1, a.size()-1, a);
    double s2 = curSum + solve(0, a.size()-2, a);
    s1 -= origSum;
    double s11 = abs(s1 + ceil(a[0]) - a[0]);
    double s12 = abs(s1 + a[0] - floor(a[0]));
    s1 = min(s11, s12);

    s2 -= origSum;
    int m = a.size()-1;
    double s21 = abs(s2 + ceil(a[m]) - a[m]);
    double s22 = abs(s2 + a[m] - floor(a[m]));
    s2 = min(s21, s22);

    printf("%0.3lf\n", min(abs(s1), abs(s2)));
  }


  return 0;
}

