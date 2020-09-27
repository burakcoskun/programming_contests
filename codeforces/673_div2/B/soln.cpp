#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, T;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> T;
    vector<pair<ll, ll>> a(n);
    vector<int> res(n);
    map<ll, ll> cnt;
    for (int i = 0; i < n; ++i) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n;) {
      if (cnt[a[i].first]) {
        res[a[i].second] = cnt[a[i].first] - 1;
      } else {
        res[a[i].second] = 0;
        cnt[a[i].first] = 1;
        cnt[T - a[i].first] = 2;
      }
      int cur = cnt[a[i].first] == 1;
      int j = i + 1;
      if (a[i].first * 2 == T) {
        for (; j < n && a[j].first == a[i].first; ++j) {
          cur = 1 - cur;
          res[a[j].second] = cur;
        }
      }
      i = j;
    }
    for (int i = 0; i < n; ++i)
      cout << res[i] << " ";
    cout << "\n";
  }
  return 0;
}
