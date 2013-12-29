#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st;
    cin >> st;
    int len = st.size();

    int cnt[10] = {0};
    cnt[1] = cnt[6] = cnt[8] = cnt[9] = 1;
    int p = 0;

    string ret = "";
    int ten = 1;

    for(int i = 0; i < (int)len; ++i) {
        int id = st[i] - '0';

        if(cnt[id] == 0){
            ret += st[i];
            ten = (ten*10) % 7;
            p = (p*10 + id) % 7;
        }
        else {
            cnt[id]--;
        }
    }

    string tmp = "1689";

    do{
        int m = (atoi(tmp.c_str()) * ten)% 7;
        m = (m+p)%7 ;
        if(m == 0) {
            cout << tmp << ret << "\n";
            return 0;
        }
    }while(next_permutation(tmp.begin(), tmp.end()));

    cout << 0 << "\n";

    return 0;
}

