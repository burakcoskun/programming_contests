#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5;
int T, n;
int a[maxn];
int res[maxn];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    sort(a, a + n);

    int f = 0, l = n - 1;
    int p = n - 1;

    int w = 0;
    while (f < l) {
      // cout << f << " " << l << endl;
      if (!w) {
        res[p] = a[l];
        --l;
      } else {
        res[p] = a[f];
        ++f;
      }
      --p;
      w = 1 - w;
    }
    res[p] = a[f];
    for (int i = 0; i < n; ++i)
      cout << res[i] << " ";
    cout << "\n";
  }

  return 0;
}
