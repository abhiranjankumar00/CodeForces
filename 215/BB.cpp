#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector <int> arr(N);
  for(int i = 0; i < (int)N; ++i) {
    cin >> arr[i];
  }
  vector <int> l(M);
  for(int i = 0; i < (int)M; ++i) {
    cin >> l[i];
    l[i]--;
  }

  vector <int> diff(N);
  set<int> st;
  for(int i = (int)N-1; i >= (int)0; --i) {
    st.insert(arr[i]);
    diff[i] = (int)st.size();
  }

  for(int i = 0; i < (int)M; ++i) {
    cout << diff[l[i]] << "\n";
  }

  return 0;
}

