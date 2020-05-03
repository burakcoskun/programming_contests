#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, x, y;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> x >> y >> a >> b;

    ll res = 0;
    if (b >= 2 * a) {
      res = x * a + y * a;
    } else {
      ll minD = min(x, y);
      res = minD * b;
      res += (x - minD) * a + (y - minD) * a;
    }

    cout << res << "\n";
  }
  return 0;
}
