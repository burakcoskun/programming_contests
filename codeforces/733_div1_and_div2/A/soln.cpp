#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    int res = 1;
    while (n) {
      res = max(res, n % 10);
      n /= 10;
    }
    cout << res << "\n";
  }
  return 0;
}
