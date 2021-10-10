#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> s(n, vector<int>(5));

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < 5; ++j)
        cin >> s[i][j];

    bool res = false;

    for (int i = 0; i < 5; ++i)
      for (int j = i + 1; j < 5; ++j) {
        int l = 0, r = 0, b = 0;
        bool check = true;

        for (int k = 0; k < n; ++k) {
          if (s[k][i] && s[k][j])
            ++b;
          else if (s[k][i])
            ++l;
          else if (s[k][j])
            ++r;
          else
            check = false;
        }

        if (check) {
          int less = min(l, r);
          int more = max(l, r);

          if (b >= more - less && ((b - (more - less)) % 2 == 0))
            res = true;
        }
      }
    if (res)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
