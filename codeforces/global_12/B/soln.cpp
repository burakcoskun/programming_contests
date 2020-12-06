#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dist(int a, int b, vector<pair<int, int>> &p) {
  return abs(p[a].first - p[b].first) + abs(p[a].second - p[b].second);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; ++i)
      cin >> p[i].first >> p[i].second;

    bool f = false;
    for (int i = 0; i < n; ++i) {
      bool check = true;
      for (int j = 0; j < n; ++j)
        if (dist(i, j, p) > k)
          check = false;

      if (check)
        f = true;
    }

    if (f)
      cout << 1 << "\n";
    else
      cout << -1 << "\n";
  }
  return 0;
}
