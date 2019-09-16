#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
int a[200005];
ll dp[200005];
ll res;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  dp[0] = (a[0] < 0);
  for (int i = 1; i < n; ++i) {
    if (a[i] > 0)
      dp[i] = dp[i - 1];
    else {
      pos = i - dp[i - 1];
      dp[i] = pos + 1;
    }
  }

  for (int i = 0; i < n; ++i)
    res += dp[i];
  ll r2 = n * (n + 1) / 2 - res;
  cout << res << " " << r2 << endl;

  return 0;
}
