#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int c, x, m;

bool ok(int num) {
  if (num > c || num > m)
    return false;

  ll nx = x + (c - num) + (m - num);
  if (num > nx)
    return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> c >> m >> x;

    int left = 0, right = min(c, m);
    int res;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (ok(middle)) {
        res = middle;
        left = middle + 1;
      } else
        right = middle - 1;
    }
    cout << res << endl;
  }

  return 0;
}
