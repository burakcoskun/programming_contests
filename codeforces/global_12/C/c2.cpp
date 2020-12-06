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

    vector<vector<int>> cnt(2, vector<int>(3));
    int tot = 0;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (s[i][j] != '.') {
          int k;
          if (s[i][j] == 'X')
            k = 0;
          else
            k = 1;
          cnt[k][(i + j) % 3]++;
          ++tot;
        }

    int r1, r2, r3, r4;
    for (int i = 0; i < 1; ++i)
      for (int j = 0; j < 3; ++j)
        for (int k = 1; k < 2; ++k)
          for (int l = 0; l < 3; ++l)
            if (j != l && cnt[i][j] + cnt[k][l] <= tot / 3) {
              r1 = i;
              r2 = j;
              r3 = k;
              r4 = l;
            }

    // cout << r2 << " " << r4 << endl;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        if (s[i][j] != '.') {
          if ((i + j) % 3 == r2 && s[i][j] == 'X')
            s[i][j] = 'O';
          else if ((i + j) % 3 == r4 && s[i][j] == 'O')
            s[i][j] = 'X';
        }
      cout << s[i] << "\n";
    }
  }
  return 0;
}
