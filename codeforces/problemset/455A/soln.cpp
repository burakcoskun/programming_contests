#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll>> dp(1e5 + 1, vector<ll>(2));
int n;
vector<ll> cnt(1e5 + 1);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cnt[a]++;
  }

  dp[0][0] = dp[0][1] = 0;
  for (int i = 1; i <= 1e5; ++i) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    dp[i][1] = dp[i - 1][0] + cnt[i] * i;
  }

  cout << max(dp[1e5][0], dp[1e5][1]) << endl;
  return 0;
}
