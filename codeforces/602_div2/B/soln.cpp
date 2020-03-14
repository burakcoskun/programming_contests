#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    vector<int> q(n);
    vector<int> res(n);
    vector<int> v(n + 1);
    for (int i = 0; i < n; ++i)
      cin >> q[i];

    res[0] = q[0];
    v[res[0]] = 1;
    for (int i = 1; i < n; ++i)
      if (q[i] > q[i - 1]) {
        res[i] = q[i];
        v[res[i]] = 1;
      }

    bool no = false;
    int first = 1;
    int pos = 0;
    int cmax = 0;
    while (pos < n) {
      while (pos < n && res[pos] >= 1) {
        cmax = max(cmax, res[pos]);
        ++pos;
      }
      if (pos == n)
        break;

      while (first <= n && v[first] == 1)
        ++first;
      if (first == n + 1 || first > cmax) {
        no = true;
        break;
      }

      res[pos] = first;
      v[first] = 1;
      ++pos;
    }

    if (no)
      cout << -1 << endl;
    else {
      for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
      cout << endl;
    }
  }
  return 0;
}
