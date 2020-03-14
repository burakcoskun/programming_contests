#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int n;
int a, b, c;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;

    int a1 = 0, b1 = 0, c1 = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'R')
        ++a1;
      else if (s[i] == 'P')
        ++b1;
      else
        ++c1;
    }

    int res = min(a, c1) + min(b, a1) + min(c, b1);

    int ea = a - min(a, c1);
    int eb = b - min(b, a1);
    int ec = c - min(c, b1);

    if (res >= (n + 1) / 2) {
      cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') {
          if (b) {
            cout << "P";
            --b;
          } else {
            if (ea) {
              cout << "R";
              --ea;
            } else if (ec) {
              cout << "S";
              --ec;
            }
          }
        }
        if (s[i] == 'S') {
          if (a) {
            cout << "R";
            --a;
          } else {
            if (eb) {
              cout << "P";
              --eb;
            } else if (ec) {
              cout << "S";
              --ec;
            }
          }
        }
        if (s[i] == 'P') {
          if (c) {
            cout << "S";
            --c;
          } else {
            if (eb) {
              cout << "P";
              --eb;
            } else if (ea) {
              cout << "R";
              --ea;
            }
          }
        }
      }
    } else
      cout << "NO";
    cout << endl;
  }
  return 0;
}
