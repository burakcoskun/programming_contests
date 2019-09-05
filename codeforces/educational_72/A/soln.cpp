#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int s, in, ex;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  for (int t = 0; t < T; ++t) {
    cin >> s >> in >> ex;

    int a = ex - s + in;
    int f = a / 2 + 1;
    if (a < 0)
      f = 0;
    int res = ex - f + 1;
    if (res > 0)
      cout << res << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
