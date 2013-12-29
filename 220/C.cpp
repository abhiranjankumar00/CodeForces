#include <bits/stdc++.h>
using namespace std;

int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, -1, 1};

int N, M;
const int sz = 1e3 + 11;
char G[sz][sz];
const string name = "DIMA";
int vis[sz][sz];
int cnt[sz][sz];
bool flag = false;

bool valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int dfs(int x, int y) {
    if(vis[x][y] == 1)
        return cnt[x][y];
    if(vis[x][y] == 0) {
        flag = true;
    }
    if(flag)
        return -1;
    vis[x][y] = 0;
    int &len = cnt[x][y];
    if(G[x][y] == 'A')
        len = 1;
    else
        len = 0;

    for(int i = 0; i < (int)4; ++i) {
        int xx = x + X[i];
        int yy = y + Y[i];
        if(!valid(xx, yy))
            continue;
        for(int j = 0; j < (int)4; ++j) {
            if(name[j] == G[x][y] && name[(j+1)%4] == G[xx][yy]) {
                if(G[xx][yy] == 'D')
                    len = max(len, dfs(xx, yy)+1);
                else
                    len = max(len, dfs(xx, yy));
            }
        }
    }

    vis[x][y] = 1;
    return len;
}

int main()
{
    memset(vis, -1, sizeof(vis));
    cin >> N >> M;
    for(int i = 0; i < (int)N; ++i) {
            cin >> G[i];
    }
    for(int i = 0; i < (int)N; ++i) {
        for(int j = 0; j < (int)M; ++j) {
            if(G[i][j] == 'D')
                dfs(i, j);
        }
    }
/*
    for(int i = 0; i < (int)N; ++i) {
        for(int j = 0; j < (int)M; ++j) {
            printf("%2c ", G[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";

    for(int i = 0; i < (int)N; ++i) {
        for(int j = 0; j < (int)M; ++j) {
            printf("%2d ", cnt[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "flag = " << flag << "\n";
*/
    if(flag) {
        cout << "Poor Inna!" << "\n";
        return 0;
    }
    int mx = 0;
    for(int i = 0; i < (int)N; ++i) {
        for(int j = 0; j < (int)M; ++j) {
            if(G[i][j] == 'A')
                mx = max(mx, cnt[i][j]);
        }
    }
    if(mx == 0) {
        cout << "Poor Dima!" << "\n";
    }
    else
        cout << mx << "\n";

    return 0;
}

