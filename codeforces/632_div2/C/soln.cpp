#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
const int maxn = 1e5 + 1;
int a[maxn * 2];
ll sum[maxn * 2];
ll res[maxn * 2];
map<ll, queue<ll>> s, l;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  ll c = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    c += a[i];
    s[c].push(i);
  }

  c = 0;
  for (int i = 0; i < n; ++i) {
    if (s.find(c) == s.end() || s[c].empty()) {
      res[i] = n;
      // cout << "a" << endl;
      // cout << res << endl;
    } else {
      while (!s[c].empty() && s[c].front() < i) {
        s[c].pop();
      }
      res[i] = s[c].front();
      // cout << "b" << endl;
      // cout << res << endl;
    }
    c += a[i];
    s[c].pop();
  }
  for (int i = n - 2; i >= 0; --i)
    res[i] = min(res[i], res[i + 1]);
  ll ans = 0;
  for (int i = 0; i < n; ++i)
    ans += res[i] - i;

  cout << ans << endl;
  return 0;
}
