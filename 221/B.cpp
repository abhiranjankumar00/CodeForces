#include <bits/stdc++.h>
using namespace std;

int g[101][101];

int main()
{
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < (int)M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        g[u][v] = c;
    }
    int ans = 0;

    for(int i = 0; i < (int)N; ++i) {
        for(int j = 0; j < (int)N; ++j) {
            for(int k = 0; k < (int)N; ++k) {
                if(g[j][i] > 0  && g[i][k] > 0) {
                    int flow = min(g[j][i], g[i][k]);

                    g[j][i]-=flow;

                    g[i][k]-=flow;

                    g[j][k]+=flow;
                }
            }
        }
    }


    vector <int> balance(N, 0);
    for(int i = 0; i < (int)N; ++i) {
        for(int j = 0; j < (int)N; ++j) {
            balance[j] += g[i][j];
        }
    }

    for(int i = 0; i < (int)N; ++i) {
        ans += abs(balance[i]);
    }

    cout << ans << "\n";


    return 0;
}

