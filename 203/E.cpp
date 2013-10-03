#include <bits/stdc++.h>
using namespace std;

const int inf = 1e5;

int N, M, K;
vector <int> a;
vector <vector<int> > dist1, dist2;

int main()
{
  cin >> N >> M >> K;
  dist2  = vector <vector<int> > (N+1, vector <int> (N+1, inf));
  dist2  = vector <vector<int> > (N+1, vector <int> (N+1, inf));

  for(int i = 0; i < (int)K; ++i) {
    int u;
    cin >> u;
    a.push_back(u);
  }

  map <int, int> idx;
  int k = 1;
  for(int i = 0; i < (int)K; ++i) {
    idx[a[i]]=k;
    k++;
  }
  for(int i = 1; i <= N; i++)
    if(idx.count(i) == 0)
      idx[i] = k++;


  for(int i = (int)1; i <= (int)N; ++i) {
    for(int j = (int)1; j <= (int)N; ++j) {
      if(i==j)
        dist2[i][j] = dist2[i][j] = 0;
      else
        dist2[i][j] = dist2[i][j] = inf;
    }
  }

  set<pair <int, int> > st;
  vector <pair <int, int> > id;

  for(int i = 1; i < (int)N-1; ++i) {
    K--;
    st.insert(make_pair(i,i+1));
  }

  for(int i = (int)1; i <= (int)N; ++i) {
    for(int j = (int)i+1; j <= (int)N; ++j) {
      if(st.find(make_pair(i, j)) != st.end())
        id.push_back(make_pair(i, j));
    }
  }

  for(int i = id.size()-1; K>0 &&i >= 0; i--){
    st.insert(id[i]);
    K--;
  }

  for(int i = 0; i < (int)K; ++i) {
    int v = a[i];
    for(int j = (int)1; j <= (int)N; ++j) {
      for(int r = (int)1; r <= (int)N; ++r) {
        dist2[j][r] =min(dist2[j][r], dist2[j][v]+dist2[v][r]);
      }
    }
  }

  for(int i = 0; i < (int)N; ++i) {
    int v = i+1;
    for(int j = (int)1; j <= (int)N; ++j) {
      for(int r = (int)1; r <= (int)N; ++r) {
        dist2[j][r] =min(dist2[j][r], dist2[j][v]+dist2[v][r]);
      }
    }
  }
  for(int i = (int)1; i <= (int)N; ++i) {
    for(int j = (int)1; j <= (int)N; ++j) {
      printf("%d ", dist1[i][j]);
    }
    cout << "\n";
  }

  for(int i = (int)1; i <= (int)N; ++i) {
    for(int j = (int)1; j <= (int)N; ++j) {
      printf("%d ", dist2[i][j]);
    }

    cout << "\n";
  }
  if(dist1 == dist2){
    printf("-1\n");
  }

	return 0;
}

