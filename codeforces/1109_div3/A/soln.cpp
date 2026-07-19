#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '#')
        ++cnt;
      else
        cnt = 0;
      res = max(res, (cnt + 1) / 2);
    }
    cout << res << endl;
  }
  return 0;
}
