#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, x, y;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> x >> y;

    if (x > 3 || ((x == 2 || x == 3) && y <= 3)) {
      cout << "yes" << endl;
    } else if (y <= x) {
      cout << "yes" << endl;
    } else
      cout << "no" << endl;
  }
  return 0;
}
