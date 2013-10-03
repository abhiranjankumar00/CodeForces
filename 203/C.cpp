#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5;

class Point {
  public:
    int x, y;
    Point(int _x, int _y): x(_x), y(_y){}
    bool operator <(const Point &ob) const {
      return abs(x) + abs(y) < abs(ob.x) + abs(ob.y);
    }
};

int main()
{
  int N;
  cin >> N;
  int x, y;
  vector <Point> pts; 

  for(int i = 0; i < (int)N; ++i) {
    cin >> x >> y;
    pts.push_back(Point(x, y));
  }
  sort(pts.begin(), pts.end());

  vector <pair <int, char> > move;

  for(auto it = (pts).begin(); it != (pts).end(); ++it) {
    int xx = it->x, yy = it->y;

    if(xx > 0) {
      move.push_back(make_pair(xx, 'R'));
    }
    else if(xx < 0){
      move.push_back(make_pair(-xx, 'L'));
    }

    if(yy > 0) {
      move.push_back(make_pair(yy, 'U'));
    }
    else if(yy < 0){
      move.push_back(make_pair(-yy, 'D'));
    }

    move.push_back(make_pair(2, '\0'));

    if(xx > 0) {
      move.push_back(make_pair(xx, 'L'));
    }
    else if(xx < 0){
      move.push_back(make_pair(-xx, 'R'));
    }
    if(yy > 0) {
      move.push_back(make_pair(yy, 'D'));
    }
    else if(yy < 0){
      move.push_back(make_pair(-yy, 'U'));
    }
    move.push_back(make_pair(3, '\0'));
  }

  cout << move.size() << "\n";
  for(int i = 0; i < (int)move.size(); ++i) {
    if(move[i].second == '\0')
      printf("%d\n", move[i].first);
    else
      printf("1 %d %c\n", move[i].first, move[i].second);
  }



  return 0;
}

