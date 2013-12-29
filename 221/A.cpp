#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st;
    cin >> st;
    int len = st.size();
    int idx = -1;
    long long fl = 0, fr = 0;
    for(int i = 0; i < (int)len; ++i) {
        if(st[i] == '^')
            idx = i;
    }
    for(int dist = 1, i = (int)idx-1; i >= (int)0; --i, dist++) {
        if(st[i] != '=') {
            int w = st[i] - '0';
            fl += w*dist;
        }
    }
    for(int dist = 1, i = (int)idx+1; i < (int)len; ++i, dist++) {
        if(st[i] != '=') {
            int w = st[i] - '0';
            fr += w*dist;
        }
    }
    if(fr == fl)
        cout << "balance" << "\n";
    else if(fl > fr)
        cout << "left" << "\n";
    else
        cout << "right" << "\n";

    return 0;
}

