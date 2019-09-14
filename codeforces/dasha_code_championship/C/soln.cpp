#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  for (int t = 0; t < T; ++t) {
    int n;
    string s;
    cin >> n >> s;

    bool found = false;
    for (int c = 0; c < 10; ++c) {
      int one = 0;
      int two = 0;
      bool check = true;
      vector<int> res(n, 0);
      for (int i = 0; i < n; ++i) {
        int d = s[i] - '0';
        if (d > c) {
          if (d < two) {
            check = false;
            break;
          }
          res[i] = 2;
          two = d;
        } else if (d < c) {
          if (d < one) {
            check = false;
            break;
          }
          res[i] = 1;
          one = d;
        } else {
          if (two <= d) {
            two = d;
            res[i] = 2;
          } else {
            one = d;
            res[i] = 1;
          }
        }
      }
      if (check) {
        for (int i = 0; i < n; ++i)
          cout << res[i];
        found = true;
        break;
      }
    }
    if (!found)
      cout << "-";
    cout << endl;
  }
  return 0;
}
