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
    vector<long long> presum(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (i == 0)
        presum[i] = a;
      else
        presum[i] = presum[i - 1] + a;
    }
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
      --b[i];
    }
    sort(b.begin(), b.end(), greater<int>());

    long long res = presum[n - 1] - presum[b[0]];
    // cout << res << endl;
    for (int i = 0; i < m; ++i) {
      long long left = presum[b[i]];
      long long right = i < (m - 1) ? presum[b[i + 1]] : 0;
      res += abs(left - right);
      // cout << res << " b[i]:" << b[i] << endl;
    }
    cout << res << endl;
  }
  return 0;
}
