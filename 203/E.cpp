#include <bits/stdc++.h>
using namespace std;

const int oo = 1e5;

int main()
{
  int dist1[333][333], dist2[333][333];
  int N, M, K;
  vector <int> a;
  vector <pair <int, int> > edges;

  cin >> N >> M >> K;
  a.resize(K);
  for(int i = 0; i < (int)K; ++i) {
    cin >> a[i];
  }

  for(int i = (int)1; i <= (int)N; ++i) {
    for(int j = (int)1; j <= (int)N; ++j) {
      dist1[i][j] = dist2[i][j] = i==j?0:oo;
    }
  }
  for(int i = (int)1; i <= (int)N-1; ++i) {
    dist1[i][i+1] = dist2[i][i+1] = 1;
    dist1[i+1][i] = dist2[i+1][i] = 1;
    M--;
  }

  for(int i = (int)1; i <= (int)N; ++i) {
    for(int j = (int)i+2; j <= (int)N; ++j) {
      edges.push_back(make_pair(i, j));
    }
 
  reverse(edges.begin(), edges.end());
  for(int i = 0; i < (int)edges.size() && M > 0; ++i, M--) {
    int u = edges[i].first, v = edges[i].second;
    dist1[u][v] = dist1[v][u] = 1;
    dist2[u][v] = dist2[v][u] = 1;
  }

  for(int i = (int)1; i <= (int)N; ++i) {
    int v = i;
    for(int j = (int)1; j <= (int)N; ++j) {
      for(int r = (int)1; r <= (int)N; ++r) {
        dist1[j][r] = min(dist1[j][r], dist1[j][v] + dist1[v][r]);
      }
    }
  }

  for(int i = (int)0; i <= (int)K-1; ++i) {
    int v = a[i];
    for(int j = (int)1; j <= (int)N; ++j) {
      for(int r = (int)1; r <= (int)N; ++r) {
        dist2[j][r] = min(dist2[j][r], dist2[j][v] + dist2[v][r]);
      }
    }
  }

  for(int i = (int)1; i <= (int)N; ++i) {
    for(int j = (int)1; j <= (int)N; ++j) {
      printf("%d ", dist1[i][j]);
    }
    cout << "\n";
  }
  cout << "\n";

  for(int i = (int)1; i <= (int)N; ++i) {
    for(int j = (int)1; j <= (int)N; ++j) {
      printf("%d ", dist2[i][j]);
    }
    cout << "\n";
  }
  cout << "\n";

	return 0;
}

