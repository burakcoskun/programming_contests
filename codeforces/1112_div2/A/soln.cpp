#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i)
      cin >> w[i];
    if (n % 2) {
      cout << "NO" << endl;
      continue;
    }
    int c_min = w[1] + 1, c_max = w[0] - 1;
    for (int i = 2; i < n - 2; i += 2) {
      int current_min = min(w[i], w[i + 1]);
      int current_max = max(w[i], w[i + 1]);
      c_min = max(c_min, current_min + 1);
      c_max = min(c_max, current_max - 1);
      // cout << c_min << " " << c_max << endl;
    }
    c_min = max(c_min, w[n - 1] + 1);
    c_max = min(c_max, w[n - 2] - 1);
    // cout << c_min << " " << c_max << endl;
    if (c_min <= c_max)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
