#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st;
    cin >> st;
    vector <int> len;
    int lst = 10;
    int sz = st.size();
    int cur = 0;
    long long ans = 1ll;
//    cout << st << "\n";
    for(int i = 0; i < (int)sz; ++i) {
        if(st[i] - '0' + lst == 9) {
            cur++;
        }
        else {
            if(cur>1 && cur%2 == 1){
                ans *= 2;
            }
            cur = 1;
        }
        lst = st[i] - '0';
//        printf("%d", cur);
    }
//    cout << "\n";
    if(cur>1 && cur%2 == 1)
        ans*=2;
    cout << ans << "\n";

    return 0;
}

