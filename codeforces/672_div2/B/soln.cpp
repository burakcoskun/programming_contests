#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int calc(int k) {
  int p = 1, res = 0;
  while (p < k) {
    p *= 2;
    ++res;
  }
  if (p != k)
    --res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(33);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      b[calc(a[i])]++;
    }

    ll res = 0;
    for (int i = 0; i < 33; ++i) {
      if (b[i]) {
        // cout << i << " " << b[i] << endl;
        res += (ll)b[i] * (b[i] - 1) / 2;
      }
    }
    cout << res << endl;
  }
  return 0;
}
