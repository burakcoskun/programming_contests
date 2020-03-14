#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
vector<int> dp(100005);
const int inf = 1e9 + 7;
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  n = s.size();

  for (int i = 0; i < n; ++i)
    if (s[i] == 'w' || s[i] == 'm') {
      cout << 0 << endl;
      return 0;
    }

  dp[n] = 1;
  dp[n - 1] = 1;
  for (int i = n - 2; i >= 0; --i) {
    dp[i] = dp[i + 1];

    if (s[i] == 'n' && s[i + 1] == 'n')
      dp[i] += dp[i + 2];
    else if (s[i] == 'u' && s[i + 1] == 'u')
      dp[i] += dp[i + 2];

    dp[i] %= inf;
  }
  cout << dp[0] << endl;

  return 0;
}
