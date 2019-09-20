#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n;
    vector<ll> a;
    for (int i = 0; i < n; ++i) {
      ll tmp;
      cin >> tmp;
      a.push_back(tmp);
    }

    bool found = false;
    while (1) {
      sort(a.begin(), a.end());

      if (a[0] > 2048)
        break;

      vector<ll> b;
      bool change = false;
      for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 2048) {
          cout << "YES" << endl;
          found = true;
          break;
        }
        if (i < a.size() - 1 && a[i] < 2048 && a[i] == a[i + 1]) {
          b.push_back(a[i] * 2);
          for (int j = i + 2; j < a.size(); ++j)
            b.push_back(a[j]);
          ++i;
          change = true;
          break;
        } else
          b.push_back(a[i]);
      }
      if (!change)
        break;

      a = b;
    }
    if (!found)
      cout << "NO" << endl;
  }
  return 0;
}
