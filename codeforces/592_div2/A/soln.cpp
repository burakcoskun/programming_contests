#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int a, b, c, d, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {

    cin >> a >> b >> c >> d >> k;

    int x = a / c;
    if (a % c)
      ++x;
    int y = b / d;
    if (b % d)
      ++y;

    if (x + y <= k)
      cout << x << " " << y << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
