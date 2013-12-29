#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector <int> arr(N+1);
  for(int i = 1; i <= (int)N; ++i) {
    cin >> arr[i];
  }

  vector <int> l(M+1);
  set<int> st;
  vector <int> diff(M+1, 0);
  for(int i = 1; i <= (int)M; ++i) {
    cin >> l[i];
  }

  for(int i = (int)N; i >= (int)1; --i) {
    st.insert(arr[i]);
    diff[i] = (int) st.size();
  }
  for(int i = (int)1; i <= (int)M; ++i) {
    cout << diff[l[i]] << "\n";
  }

  return 0;
}

