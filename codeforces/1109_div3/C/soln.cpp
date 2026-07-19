#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    int g = gcd(x, y);
    bool res = true;
    for (int i = 0; i < n; ++i) {
      int d = abs(i + 1 - p[i]);
      if (d % g != 0)
        res = false;
    }
    if (!res)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
