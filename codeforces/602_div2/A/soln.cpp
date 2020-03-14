#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n;

    int minRight = 1e9 + 7;
    int maxLeft = 0;

    int l, r;
    for (int i = 0; i < n; ++i) {
      cin >> l >> r;
      minRight = min(r, minRight);
      maxLeft = max(l, maxLeft);
    }

    cout << max(0, maxLeft - minRight) << endl;
  }
  return 0;
}
