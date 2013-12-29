#include <bits/stdc++.h>
using namespace std;

const int sz = 5002;

int dp[sz][sz];

int main()
{
    int N, M;
    cin >> N >> M;
    string st;
    for(int i = 0; i < (int)N; ++i) {
        cin >> st;

        int len = 0;
//        cout << st << "\n";
        for(int i = 0; i < (int)M; ++i) {
            if(st[i] == '0')
                continue;
            else{
                len++;
                if(i == M-1 || st[i+1] == '0') {
                    dp[i-len+1][i]++;
                    len = 0;
                }
            }
        }
    }
    /*
    cout << "\n";
    for(int i = 0; i < (int)M; ++i) {
        for(int j = (int)i; j <= (int)M-1; ++j) {
            printf("%d-%d:%d\n", i, j, dp[i][j]);
        }
    }
    cout << "\n";
    */

    for(int d = (int)M; d >= (int)0; --d) {
        for(int x = 0 ; x < (int)M; ++x) {
            int y = x+d;
            if(y >= M)
                continue;
            int &ret = dp[x][y];
            if(y+1 < M)
                ret += dp[x][y+1];
            if(x-1 >= 0)
                ret += dp[x-1][y];
            if(y+1 < M && x-1 >= 0)
                ret -= dp[x-1][y+1];
        }
    }

    long long mxArea = 0;
    for(int i = 0; i < (int)M; ++i) {
        for(int j = (int)i; j <= (int)M-1; ++j) {
//            printf("%d-%d:%d\n", i, j, dp[i][j]);
            mxArea = max(mxArea, (j-i+1ll)*(dp[i][j]));

        }
    }
//    cout << "\n";

    cout << mxArea << "\n";


    return 0;
}

