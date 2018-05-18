#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long int64;

struct Point {
  Point(int64 x, int64 y) : x(x), y(y) {}
  int64 x;
  int64 y;
};
bool operator<(Point const& a, Point const& b) {
  return a.x != b.x ? a.x < b.x : a.y < b.y;
}

struct Cut {
  Cut(Point a, Point b) : a(a), b(b) {}
  Point a;
  Point b;
};
bool operator<(Cut const& lt, Cut const& rt) { return lt.a < rt.a; }

bool IsRight(Cut const& cut, Point const& point) {
  int64 dx1 = cut.a.x - point.x;
  int64 dy1 = cut.a.y - point.y;
  int64 dx2 = cut.b.x - point.x;
  int64 dy2 = cut.b.y - point.y;
  int64 t = dx1 * dy2 - dx2 * dy1;
  return t < 0;
}

int64 BinarySearch(vector<Cut> const& cuts, Point const& point) {
  int lo = 0, hi = cuts.size();
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (IsRight(cuts[mid], point)) hi = mid; else lo = mid + 1;
  }
  return lo;
}

int main() {
  int X, Y;
  scanf("%d%d", &X, &Y);
  vector<Point> Q;
  int nQ;
  scanf("%d", &nQ);
  for (int i = 0; i < nQ; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    Q.push_back(Point(x, y));
  }

  vector<Cut> H;
  int nH;
  scanf("%d", &nH);
  for (int i = 0; i < nH; ++i) {
    int y1, y2;
    scanf("%d%d", &y1, &y2);
    H.push_back(Cut(Point(0, y1), Point(X, y2)));
  }
  sort(H.begin(), H.end());

  vector<Cut> V;
  int nV;
  scanf("%d", &nV);
  for (int i = 0; i < nV; ++i) {
    int x1, x2;
    scanf("%d%d", &x1, &x2);
    V.push_back(Cut(Point(x1, Y), Point(x2, 0)));
  }
  sort(V.begin(), V.end());

  int mx = 0;
  std::unordered_map<int64, int> cnt;
  for (int i = 0; i < nQ; ++i) {
    mx = max(mx, ++cnt[BinarySearch(H, Q[i]) << 32 |  BinarySearch(V, Q[i])]);
  }
  printf("%d\n", mx);
  return 0;
}
