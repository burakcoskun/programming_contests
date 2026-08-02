#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    for (int i = 0; i < m; ++i)
      cin >> b[i];
    if (m >= n) {
      cout << "NO" << endl;
      continue;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int left = 0, right = n - m;
    int cnt = 0;
    while (cnt < m && left < n - m && right < n) {
      if (a[left] <= b[cnt] && a[right] >= b[cnt])
        ++cnt;
      else
        break;
      ++left;
      ++right;
    }
    if (cnt == m)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
