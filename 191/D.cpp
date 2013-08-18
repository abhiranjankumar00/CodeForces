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
	State(int xx, int yy, char c) : ch(c), x(xx), y(yy){}
};

class Triplet {
public:
	int x, y, d;
	Triplet(int _x, int _y, int _d): x(_x), y(_y), d(_d) {}
	const bool operator < (const Triplet &ob) const {
		return this->d < ob.d;
	}
};

void dfs(int x, int y, int d, vector <string> &G, vector <Triplet> &comp, vector <State> &ans) {
	if(!valid(x, y))
		return;
	if(G[x][y] == '#')
		return;
	G[x][y]  = '#';
	comp.push_back(Triplet(x, y, d));
	ans.push_back(State(x, y, 'B'));
	dfs(x+1, y, d+1, G, comp, ans);
	dfs(x, y+1, d+1, G, comp, ans);
	dfs(x, y-1, d+1, G, comp, ans);
	dfs(x-1, y, d+1, G, comp, ans);
}

int main()
{
	cin >> N >> M;
	vector <string> G(N);

	for(int i = 0; i < N; ++i) {
		cin >> G[i];
	}

	vector < vector<Triplet> > comp;
	vector <State> ans;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			if(G[i][j] == '.') {
				comp.push_back(vector <Triplet>());
				dfs(i, j, 0, G, comp.back(), ans);
				sort(comp.back().begin(), comp.back().end());
				reverse(comp.back().begin(), comp.back().end());
				for(int i = 0; i < comp.back().size()-1; ++i) {
					ans.push_back(State(comp.back()[i].x, comp.back()[i].y, 'D'));
					ans.push_back(State(comp.back()[i].x, comp.back()[i].y, 'R'));
				}
			}
		}
	}

	cout << ans.size() << "\n";
	for(auto it = (ans).begin(); it != (ans).end(); ++it) {
		printf("%c %d %d\n", it->ch, it->x+1, it->y+1);
	}

	return 0;
}

