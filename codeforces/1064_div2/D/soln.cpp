#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  long long MOD = 998244353;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n+1);
    for(int i = 0 ; i < n; ++i) {
      cin >> a[i];
      ++cnt[a[i]];
    }

    long long all = 1;
    int maxCnt = 0;
    for(int i = 0; i <= n; ++i) {
      if(cnt[i])
        all *= (cnt[i] + 1);
      all %= MOD;
      maxCnt = max(maxCnt, cnt[i]);
    }
    all += MOD;
    --all;
    all %= MOD;

    // cout << all << endl;

    vector<long long> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
      if(cnt[i])
        for(int j = n; j >= cnt[i]; --j) {
          dp[j] += dp[j-cnt[i]]*cnt[i];
          dp[j] %= MOD;
        }
    }
    for(int i = 1; i < maxCnt; ++i) {
      all += MOD;
      all -= dp[i];
      all %= MOD;
    }
    cout << all << endl;
  }
  return 0;
}
