#include <bits/stdc++.h>
using namespace std;

void solve(const vector <int> &v, int q, int p, int M, set<int> &ans, map <int, int> &cnt, int totalCount) {
  /*
  for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it) {
     printf("%d ", *it);
  }
  cout << "\n";
  */

  if((int)v.size() < M)
    return;

  map <int, int> cur;
  cur.clear();

  int l = 0, r = 0;
  int req = 0;
  while(r < M) {
    int t = v[r];
    cur[t]++;

    if(cur[t] == cnt[t])
      req++;
    else if(cnt[t] > 0 && cur[t] == cnt[t]+1)
      req--;
    r++;
  }

  if(req == totalCount)
    ans.insert(q+0*p);

  /*
  printf("(%d, %d): req = %d -> ", 0, M, req);
  for(__typeof((cur).begin()) it = (cur).begin(); it != (cur).end(); ++it) {
     printf("(%d, %d) ", it->first, it->second);
  }
  cout << "\n";
  */

  while(r < (int)v.size()) {
    int t = v[l];
    l++;
    cur[t]--;
    if(cnt[t] > 0 && cur[t] == cnt[t])
      req++;
    else if(cur[t] == cnt[t]-1)
      req--;

    t = v[r];
    r++;
    cur[t]++;
    if(cur[t] == cnt[t])
      req++;
    else if(cnt[t] > 0 && cur[t] == cnt[t]+1)
      req--;

    if(req == totalCount)
      ans.insert(q+l*p);

    /*
    printf("(%d, %d): req = %d -> ", l, r, req);
    for(__typeof((cur).begin()) it = (cur).begin(); it != (cur).end(); ++it) {
      printf("(%d, %d) ", it->first, it->second);
    }
    cout << "\n";
    */
  }

  //cout << "\n";
}

int main()
{
  int N, M, P;
  cin >> N >> M >> P;

  //printf("N = %d, M = %d, P = %d\na: ", N, M, P);

  vector <int> a(N);
  for(int i = 0; i < (int)N; ++i) {
    cin >> a[i];
    //printf("%d ", a[i]);
  }
  
  //printf("\nb: ");

  map <int, int> cnt;
  for(int i = 0; i < (int)M; ++i) {
    int t;
    scanf("%d", &t);
    //printf("%d ", t);
    cnt[t]++;
  }
  int totalCount = (int)cnt.size();

  /*
  cout << "\ncnt: ";
  for(__typeof((cnt).begin()) it = (cnt).begin(); it != (cnt).end(); ++it) {
    printf("(%d, %d) ", it->first, it->second);
  }
  cout << "\n\n";
  */

  vector <int> v;
  set <int> ans;

  for(int q = 0; q < (int)P; ++q) {
    v.clear();
    for(int i = 0; q + i*P < N; i++) {
      v.push_back(a[q+i*P]);
    }
    solve(v, q, P, M, ans, cnt, totalCount);
  }

  cout << ans.size() << "\n";
  for(__typeof((ans).begin()) it = (ans).begin(); it != (ans).end(); ++it) {
     printf("%d ", *it+1);
  }

  return 0;
}

