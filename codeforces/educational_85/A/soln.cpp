#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n;
    vector<pair<int, int>> l(n);
    bool res = true;
    for (int i = 0; i < n; ++i) {
      cin >> l[i].first >> l[i].second;
      if (l[i].second > l[i].first)
        res = false;

      if (i > 0) {
        int incP = l[i].first - l[i - 1].first;
        int incC = l[i].second - l[i - 1].second;
        if (incP < 0 || incC < 0)
          res = false;
        if (incC > incP)
          res = false;
      }
    }

    if (res)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
