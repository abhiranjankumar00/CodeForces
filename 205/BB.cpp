#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  N *= 2;
  map <int, vector <int> > idx;

  for(int i = 0; i < (int)N; ++i) {
    int tmp;
    cin >> tmp;

    idx[tmp].push_back(i);
  }

  map <int, int> ans;

  set <int> s[2];
  int s0 = 0, s1 = 0;
  int id = 0;

  for(auto it = (idx).begin(); it != (idx).end(); ++it) 
  {
    int u = it->first;
    vector <int> &v = it->second;
    if(it->second.size() > 1 && it->second.size()%2==1) {
      for(int i = 0; i < (int)it->second.size()-1; ++i) {
        if(i % 2 == 0){
          ans[v[i]] = 1;
          s[0].insert(u);
          s0++;
        }
        else {
          ans[v[i]] = 2;
          s[1].insert(u);
          s1++;
        }
        ans[v.back()] = id+1;
        s[id].insert(u);
        if(id == 0)
          s0++;
        else
          s1++;
        id = 1-id;
      }
    }
    else if(v.size()%2==0) {
      for(int i = 0; i < (int)v.size(); ++i) {
        if(i % 2 == 0) {
          ans[v[i]] = 1;
          s[0].insert(u);
          s0++;
        }
        else {
          ans[v[i]] = 2;
          s[1].insert(u);
          s1++;
        }
      }
    }
  }

  for(auto it = (idx).begin(); it != (idx).end(); ++it) if(it->second.size() == 1){
    if(s1 == s0) {
      ans[it->second.front()] = 1;
      s[0].insert(it->first);
      s0++;
    }
    else {
      ans[it->second.front()] = 2;
      s[1].insert(it->first);
      s1++;
    }
  }

  cout << s[0].size() * s[1].size() << "\n";
  for(auto it = (ans).begin(); it != (ans).end(); ++it) {
    cout << it->second << " ";
  }


  return 0;
}

