#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i)
      cin >> s[i];

    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (s[i][j] == 'X') {
          if ((i + j) % 3 == 0)
            ++c1;
          else if ((i + j) % 3 == 1)
            ++c2;
          else
            ++c3;
        }

    int k;
    if (c1 <= c2 && c1 <= c3)
      k = 0;
    else if (c2 <= c1 && c2 <= c3)
      k = 1;
    else
      k = 2;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        if (s[i][j] == 'X' && (i + j) % 3 == k)
          s[i][j] = 'O';
      cout << s[i] << "\n";
    }
  }
  return 0;
}
