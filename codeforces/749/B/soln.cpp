#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {

    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), c(m), used(n);
    for (int i = 0; i < m; ++i) {
      cin >> a[i] >> b[i] >> c[i];
      --a[i];
      --b[i];
      --c[i];
      used[b[i]] = 1;
    }

    int p;
    for (int i = 0; i < n; ++i)
      if (!used[i])
        p = i;
    for (int i = 0; i < n; ++i)
      if (p != i)
        cout << p + 1 << " " << i + 1 << "\n";
  }
  return 0;
}
