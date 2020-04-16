#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, n, a[200005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  for (int t = 0; t < T; ++t) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    vector<int> oc(n + 1), lu(n + 1), last(n + 1);

    last[a[0]] = 0;
    oc[a[0]] = 1;
    lu[0] = 1;

    int res = n + 1;
    for (int i = 1; i < n; ++i) {
      if (!oc[a[i]])
        lu[i] = lu[i - 1] + 1;
      else {
        int p = (i - 1) - lu[i - 1] + 1;
        if (p <= last[a[i]])
          res = min(res, i - last[a[i]] + 1);
        lu[i] = min(lu[i - 1] + 1, i - last[a[i]]);
      }

      last[a[i]] = i;
      oc[a[i]] = 1;
    }

    if (res > n)
      res = -1;
    cout << res << endl;
  }
  return 0;
}
