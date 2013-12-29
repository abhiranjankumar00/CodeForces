#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 111;
vector <int> g[sz];
bool has[sz] = {};
set <pair <int, int> >st;
vector <int> ans;

void put(int u, int v) {
  if(u > v) swap(u, v);
  st.insert(make_pair(u, v));
}
bool get(int u, int v) {
  if(u > v) swap(u, v);
  return st.find(make_pair(u, v)) != st.end();
}

void dfs(int u, int p) {
  bool &have = has[u];

  for(auto it = (g[u]).begin(); it != (g[u]).end(); ++it) if(*it != p){
    dfs(*it, u);
//    printf("u = %d, *it = %d, has = %d\n", u, *it, has[*it]);

    if(get(*it, u)) {
      have = true;
      if(has[*it]){
        continue;
      }
      else {
        ans.push_back(*it);
        put(*it, u);
        has[*it] = true;
      }
    }
    have |= has[*it];
  }
}

int main()
{
  int N;
  cin >> N;
  for(int i = 0; i < (int)N-1; ++i) {
    int u, v, t;
    cin >> u >> v >> t;
    if(t == 2)
      put(u, v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, -1);
  cout << ans.size() << "\n";
  for(auto it = (ans).begin(); it != (ans).end(); ++it) {
    printf("%d ", *it);
  }

  return 0;
}

