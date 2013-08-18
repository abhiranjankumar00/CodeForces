//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>	// Don't know why it is here.
#include <numeric>		// +1
#include <cassert>
#include <utility>		// +1
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;

int N, M;
bool valid(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

class State {
public:
	char ch;
	int x, y;
	State(int xx, int yy, char c) : ch(c), x(xx), y(yy) {}
};

int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};

void dfs(int x, int y, vector <string> &G, vector <State> &ans) {
	if(!valid(x, y))
		return;
	if(G[x][y] == '#')
		return;
	G[x][y]  = '#';
	ans.push_back(State(x, y, 'B'));
	for(int i = 0; i < 4; ++i) {
		dfs(x + X[i], y + Y[i], G, ans);
	}
	ans.push_back(State(x, y, 'D'));
	ans.push_back(State(x, y, 'R'));
}

int main()
{
	cin >> N >> M;
	vector <string> G(N);

	for(int i = 0; i < N; ++i) {
		cin >> G[i];
	}

	vector <State> ans;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			if(G[i][j] == '.') {
				dfs(i, j, G, ans);
				ans.pop_back(); ans.pop_back();
			}
		}
	}

	cout << ans.size() << "\n";
	for(auto it = (ans).begin(); it != (ans).end(); ++it) {
		printf("%c %d %d\n", it->ch, it->x+1, it->y+1);
	}

	return 0;
}

