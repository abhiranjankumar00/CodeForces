#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  N*=2;
  set <pair <int, int> > val;
  map <int, int> cnt;
  for(int i = 0; i < (int)N; ++i) {
    int tmp;
    cin >> tmp;
    cnt[tmp]++;
    val.insert(make_pair(tmp, i));
  }

  set <int> a, b;
  map <int, int> m;

  for(auto it = val.begin(); it != val.end(); ) {
    a.insert(it->first);
    m[it->second] = 1;
    it++;
    b.insert(it->first);
    m[it->second] = 2;
    it++;
  }

  int ans = 0;
  for(auto it = (cnt).begin(); it != (cnt).end(); ++it) {
    if(it->second==1)
      ans++;
    else 
      ans+=2;
  }
  cout << (ans/2)*((ans+1)/2) << "\n";
//  cout << a.size() * b.size() << "\n";
  for(int i = 0; i < (int)N; ++i) {
    cout << m[i] << " ";
  }

	return 0;
}

