#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    vector<pair<int, int>> pos(n + 1, {-1, -1});
    for (int i = 1; i <= 2 * n; ++i) {
      cin >> a[i];
      pos[a[i]].second = i;
      if (pos[a[i]].first == -1)
        pos[a[i]].first = i;
    }

    vector<long long> dp(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) {
      dp[i] = dp[i - 1] + 1;
      if (pos[a[i]].second == i) {
        long long len = pos[a[i]].second - pos[a[i]].first + 1;
        dp[i] = max(dp[i], len * len + dp[pos[a[i]].first - 1]);
      }
    }
    cout << dp[2 * n] << endl;
  }
  return 0;
}
