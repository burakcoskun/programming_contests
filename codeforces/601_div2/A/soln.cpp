#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int a, b;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  for (int t = 0; t < T; ++t) {
    cin >> a >> b;

    int d = abs(a - b);
    int res = 0;
    res += d / 5;
    d %= 5;
    res += d / 2;
    d %= 2;
    res += d;
    cout << res << endl;
  }
  return 0;
}
