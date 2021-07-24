#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    for (int i = 0; i < n; ++i)
      cin >> b[i];

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    for (int i = 1; i < n; ++i) {
      a[i] = a[i - 1] + a[i];
      b[i] = b[i - 1] + b[i];
    }

    int l = 0, r = n, m;
    int ans;
    while (l <= r) {
      int m = l + (r - l) / 2;

      int stages = (n + m) - (n + m) / 4;
      long long r1 = 100 * (long long)min(stages, m);
      long long r2 = b[min(stages - 1, n - 1)];
      stages -= min(stages, m);
      r1 += a[stages - 1];
      // cout << r1 << " " << r2 << " " << m << endl;
      if (r1 >= r2) {
        ans = m;
        r = m - 1;
      } else
        l = m + 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
