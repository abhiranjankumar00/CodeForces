#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M, P;
  cin >> N >> M >> P;
  vector <int> a(N);
  for(int i = 0; i < (int)N; ++i) {
    cin >> a[i];
  }

  map <int, int> mp;
  for(int i = 0; i < (int)M; ++i) {
    int t;
    cin >> t;
    mp[t]++;
  }

  vector <vector<int> > seq(P);
  
  for(int q = 0; q < (int)P; ++q) {
    for(int i = 0; q+i*P < N; i++)
      seq[q].push_back(a[q+i*P]);
  }

  set <int> ans;
  for(int q = 0; q < (int)P; ++q) {
/*
    for(auto it = (seq[q]).begin(); it != (seq[q]).end(); ++it) {
      printf("%d ", *it);
    }
    cout << "\n";
*/

    if(seq[q].size() < M)
      continue;

    map <int, int> cur;
    cur.clear();
    int cnt = 0;

    for(int i = 0; i < (int)M; ++i) {
      int t = seq[q][i];
      cur[t]++;
      if(cur[t] == mp[t])
        cnt++;
      else if(cur[t] == mp[t]+1)
        cnt--;
    }

//    cout << "cnt = " << cnt << "\n";
    if(cnt == (int)mp.size())
      ans.insert(q);

    int l = 0, r = M;
/*
    printf("(%d, %d) -> ", l, r);
    for(auto it = (cur).begin(); it != (cur).end(); ++it) {
      printf("(%d: %d) ", it->first, it->second);
    }
    cout << "\n";
*/

    while(r < seq[q].size()) {
      int t = seq[q][l];
      cur[t]--;
      if(cur[t] == mp[t]-1)
        cnt--;
      else if(cur[t] == mp[t])
        cnt++;
      l++;

      t = seq[q][r];
      cur[t]++;
      if(cur[t] == mp[t])
        cnt++;
      else if(cur[t] == mp[t]+1)
        cnt--;
      r++;
/*
      printf("(%d, %d) -> ", l, r);
      for(auto it = (cur).begin(); it != (cur).end(); ++it) {
        printf("(%d: %d) ", it->first, it->second);
      }
      cout << "cnt = " << cnt << "\n";
*/

      if(cnt == mp.size())
        ans.insert(q + l*P);
    } 
  }

  cout << ans.size() << "\n";
  for(auto it = (ans).begin(); it != (ans).end(); ++it) {
    printf("%d ", (*it)+1);
  }

  return 0;
}

