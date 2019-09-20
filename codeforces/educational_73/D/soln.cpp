#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int n;
ll a[300005], b[300005];
const ll inf = 1e18 + 1;

void solve() {
  vector<vector<ll>> dp(n + 1, vector<ll>(3, inf));
  dp[0][0] = 0;
  dp[0][1] = b[0];
  dp[0][2] = b[0] * 2;

  for (int i = 1; i < n; ++i)
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 3; ++k) {
        if (a[i - 1] + j == a[i] + k)
          continue;
        else
          dp[i][k] = min(dp[i][k], dp[i - 1][j] + k * b[i]);
      }
  ll res = min(dp[n - 1][0], dp[n - 1][1]);
  res = min(res, dp[n - 1][2]);
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> a[i] >> b[i];
    solve();
  }
  return 0;
}
