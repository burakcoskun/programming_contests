#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int d, m;

ll get_closest(ll k) {
  ll res = 1;
  while (res <= k) {
    res *= 2;
  }
  return res / 2;
}

ll f(ll k, vector<int> &dp) {
  ll p = 0;
  ll tmp = 1;
  while (tmp < k) {
    tmp *= 2;
    ++p;
  }

  if (dp[p] != -1)
    return dp[p];
  ll res = 0;
  ll c = k;
  while (c * 2 <= d) {
    res += (c)*f(c * 2, dp);
    res %= m;
    res += c;
    res %= m;
    c *= 2;
  }
  res += d - c + 1;
  res %= m;
  return dp[p] = res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> d >> m;

    vector<int> dp(50, -1);
    cout << f(1, dp) << endl;
  }
  return 0;
}
