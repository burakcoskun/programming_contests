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
    vector<int> a(n), b(n), cnta(n), cntb(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
      --a[i];
      --b[i];
      cnta[a[i]]++;
      cntb[b[i]]++;
    }

    ll res = (ll)n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; ++i)
      res -= (ll)(cnta[a[i]] - 1) * (cntb[b[i]] - 1);
    cout << res << "\n";
  }
  return 0;
}
