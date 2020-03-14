#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;

int find_min(vector<int> &a, int n) {
  int res;
  int minc = 1e9;
  for (int i = 0; i < n; ++i)
    if (minc > a[i]) {
      minc = a[i];
      res = i;
    }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, m;

    cin >> n >> m;
    vector<int> a(n);
    vector<int> v(n);
    vector<pair<int, int>> res;
    int cost = 0;

    for (int i = 0; i < n; ++i)
      cin >> a[i];

    if (m < n || n <= 2) {
      cout << -1 << endl;
      continue;
    }

    int node = 0;
    for (int cnt = 0; cnt < n; ++cnt) {

      v[node] = 1;
      int f, minc = 1e9;
      for (int i = 0; i < n; ++i) {
        if (!v[i] && a[i] < minc) {
          minc = a[i];
          f = i;
        }
      }
      if (cnt == n - 1)
        f = 0;
      res.push_back(make_pair(node + 1, f + 1));
      cost += a[node];
      cost += a[f];
      node = f;
    }

    m -= n;
    ll lastcost = 0;
    int m1 = find_min(a, n);
    lastcost = a[m1];
    a[m1] = 1e9;
    int m2 = find_min(a, n);
    lastcost += a[m2];

    cost += m * lastcost;
    for (int i = 0; i < m; ++i)
      res.push_back(make_pair(m1 + 1, m2 + 1));

    cout << cost << endl;
    for (int i = 0; i < res.size(); ++i)
      cout << res[i].first << " " << res[i].second << endl;
  }
  return 0;
}
