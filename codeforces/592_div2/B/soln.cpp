#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int n;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n >> s;

    int cnt = 0;
    for (int i = 0; i < n; ++i)
      if (s[i] == '1')
        ++cnt;

    int res = n + cnt;

    int fs = n;
    for (int i = 0; i < n; ++i)
      if (s[i] == '1') {
        fs = i;
        break;
      }
    if (cnt) {
      res = max(res, (fs + 1) * 2);
      res = max(res, (n - fs) * 2);
    }

    int ls = n;
    for (int i = n - 1; i >= 0; --i)
      if (s[i] == '1') {
        ls = i;
        break;
      }
    if (cnt) {
      res = max(res, (ls + 1) * 2);
      res = max(res, (n - ls) * 2);
    }
    cout << res << endl;
  }
  return 0;
}
