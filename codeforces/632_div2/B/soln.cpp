#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int n;
const int maxn = 1e5 + 1;
int a[maxn], b[maxn];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  for (int t = 0; t < T; ++t) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    for (int i = 0; i < n; ++i)
      cin >> b[i];

    bool p = false, m = false;
    int res = true;
    for (int i = 0; i < n; ++i) {
      if (a[i] < b[i] && !p) {
        res = false;
        break;
      } else if (a[i] > b[i] && !m) {
        res = false;
        break;
      }

      p = p | (a[i] == 1);
      m = m | (a[i] == -1);
    }

    if (res)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
