#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int x, n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while (t--) {
    cin >> x >> n >> m;

    while (x > 20 && n) {
      x = x / 2 + 10;
      --n;
    }
    while (x > 0 && m) {
      x -= 10;
      --m;
    }
    if (x <= 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
