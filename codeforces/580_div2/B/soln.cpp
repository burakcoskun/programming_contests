#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
const int maxn = 100005;
ll dp[maxn][2];
ll a[maxn];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  dp[0][0] = abs(1 - a[0]);
  dp[0][1] = abs(-1 - a[0]);
  // cout << dp[0][0] << " " << dp[0][1] << endl;

  for (int i = 1; i < n; ++i) {
    dp[i][0] = min(dp[i - 1][0] + abs(1 - a[i]), dp[i - 1][1] + abs(-1 - a[i]));
    dp[i][1] = min(dp[i - 1][0] + abs(-1 - a[i]), dp[i - 1][1] + abs(1 - a[i]));

    // cout << dp[i][0] << " " << dp[i][1] << endl;
  }

  cout << dp[n - 1][0] << endl;

  return 0;
}
