#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, n, a, b, x;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n >> x >> a >> b;
    cout << min(n - 1, abs(a - b) + x) << endl;
  }
  return 0;
}
