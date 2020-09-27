#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }

    vector<int> l(n, -1), maxD(n, 0);
    for (int i = 0; i < n; ++i) {
      int d = i - l[a[i]];
      if (d > maxD[a[i]])
        maxD[a[i]] = d;
      l[a[i]] = i;
    }
    for (int c = 0; c < n; ++c) {
      int d = n - l[c];
      if (d > maxD[c])
        maxD[c] = d;
      // cout << d << endl;
    }

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
      p[i].first = maxD[i];
      p[i].second = i;
    }
    sort(p.begin(), p.end());

    int res = -1, pos = 0;
    for (int i = 0; i < n; ++i) {
      while (pos < n && p[pos].first <= i + 1) {
        if (res == -1)
          res = p[pos].second + 1;
        res = min(res, p[pos].second + 1);
        ++pos;
      }
      cout << res << " ";
    }
    cout << "\n";
  }
  return 0;
}
