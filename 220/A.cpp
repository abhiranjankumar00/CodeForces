#include <bits/stdc++.h>
using namespace std;

int n, m, i, j, a, b;

int minMoves(int x1, int y1, int x2, int y2) {
    int dx = abs(x1-x2);
    int dy = abs(y1-y2);
    int mx = dx/a;
    int my = dy/b;
    if(dx == 0 && dy == 0)
        return 0;
    else if(dx == 0 && dy % b == 0 ){
        if(my % 2 == 0 && a <= n)
            return my;
        else
            return 5e8;
    }
    else if(dy == 0 && dx % a == 0 ){
        if(mx % 2 == 0 && b <= m)
            return mx;
        else
            return 5e8;
    }
    else if(dx % a == 0 && dy % b == 0) {
        if(mx % 2 == my % 2)
            return max(mx, my);
        else
            return 5e8;
    }
    else
        return 5e8;
}

int main()
{
    cin >> n >> m >> i >> j >> a >> b;

    int m1 = minMoves(i, j, 1, 1);
    int m2 = minMoves(i, j, 1, m);
    int m3 = minMoves(i, j, n, 1);
    int m4 = minMoves(i, j, n, m);

    int ans = 5e8;
    ans = min(ans, m1);
    ans = min(ans, m2);
    ans = min(ans, m3);
    ans = min(ans, m4);

    if(ans != 5e8) {
        cout << ans << "\n";
    }
    else {
        cout << "Poor Inna and pony!" << "\n";
    }

    return 0;
}

