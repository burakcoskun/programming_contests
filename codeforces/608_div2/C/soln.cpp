#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, sx, sy;
vector<pair<int, int>> p;
long long ans = 0;
int ansx, ansy;

void find(int x, int y) {
  long long c = 0;
  for (int i = 0; i < n; ++i) {
    long long minc = abs(sx - p[i].first) + abs(sy - p[i].second);

    long long shoarma = 1 + abs(x - p[i].first) + abs(y - p[i].second);
    if (minc == shoarma)
      ++c;
  }
  if (c > ans) {
    ans = c;
    ansx = x;
    ansy = y;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> sx >> sy;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    p.push_back(make_pair(x, y));
  }

  find(sx - 1, sy);
  find(sx, sy - 1);
  find(sx + 1, sy);
  find(sx, sy + 1);
  cout << ans << endl;
  cout << ansx << " " << ansy << endl;
  return 0;
}
