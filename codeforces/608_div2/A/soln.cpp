#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a, b, c, d, e, f;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> c >> d >> e >> f;
  int res;
  if (e > f) {
    int cnt = min(a, d);
    res = cnt * e;
    a -= cnt;
    d -= cnt;
    res += min(b, min(c, d)) * f;
  } else {
    int cnt = min(b, min(c, d));
    res = cnt * f;
    d -= cnt;
    res += min(a, d) * e;
  }
  cout << res << endl;
  return 0;
}
