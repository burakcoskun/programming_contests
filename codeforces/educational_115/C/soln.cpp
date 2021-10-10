#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> cnt;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
      cnt[a[i]]++;
    }
    sum *= 2;
    if (sum % n != 0) {
      cout << "0\n";
      continue;
    }
    ll goal = sum / n;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
      ll r = goal - a[i];
      if (r == a[i])
        res += cnt[r] - 1;
      else
        res += cnt[r];
      // cout << goal << " " << r << " " << res << endl;
    }
    cout << res / 2 << "\n";
  }
  return 0;
}
