#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, x;
    vector<int> a, b;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
      int d, h;
      cin >> d >> h;
      b.push_back(d);
      a.push_back(d - h);
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    if (b[0] >= x) {
      cout << 1 << endl;
      continue;
    }

    x -= b[0];
    int res = 1;

    if (a[0] <= 0)
      cout << -1 << endl;
    else {
      res += x / a[0];
      if (x % a[0])
        ++res;
      cout << res << endl;
    }
  }
  return 0;
}
