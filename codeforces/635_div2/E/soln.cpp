#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s, t;

int dp[3005][3005];
const int mod = 998244353;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> t;

  for (int i = 0; i <= s.size(); ++i)
    dp[0][i] = 1;

  for (int i = 1; i <= s.size(); ++i)
    for (int j = 0; j < s.size() - i + 1; ++j) {
      // cout << i << " " << j << " " << dp[i][j] << endl;
      if (j >= t.size() || s[i - 1] == t[j]) {
        dp[i][j] += dp[i - 1][j + 1];
        dp[i][j] %= mod;
      }
      // cout << i << " " << j << " " << dp[i][j] << endl;
      if (i + j > t.size() || s[i - 1] == t[i + j - 1]) {
        dp[i][j] += dp[i - 1][j];
        dp[i][j] %= mod;
      }
      // cout << i << " " << j << " " << dp[i][j] << endl;
    }

  ll res = 0;
  for (int i = t.size(); i <= s.size(); ++i) {
    res += dp[i][0];
    res %= mod;
  }
  cout << res << "\n";
  return 0;
}
