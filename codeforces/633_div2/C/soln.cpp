#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 1;
int T;
int n;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    int lmax = a[0];
    int maxd = 0;
    for (int i = 1; i < n; ++i) {
      maxd = max(maxd, lmax - a[i]);
      lmax = max(lmax, a[i]);
    }

    ll pow = 1;
    ll res = 0;
    while (pow <= maxd) {
      pow *= 2;
      ++res;
    }
    cout << res << "\n";
  }

  return 0;
}
