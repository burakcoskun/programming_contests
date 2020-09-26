#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; --i) {
      dp[i][0] = max(dp[i + 1][0], a[i] + dp[i + 1][1]);
      dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] - a[i]);
    }

    cout << dp[0][0] << "\n";
  }
  return 0;
}
