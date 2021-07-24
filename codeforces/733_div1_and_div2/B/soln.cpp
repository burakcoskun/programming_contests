#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int h, w;
    cin >> h >> w;
    vector<vector<vector<int>>> res(2, vector<vector<int>>(h, vector<int>(w)));
    int i, j;

    vector<int> cnt(2);
    for (int k = 0; k < 2; ++k) {
      cnt[k] = 0;
      res[k][0][0] = k;
      for (int j = 1; j < w; ++j)
        if (res[k][0][j - 1] == 0) {
          res[k][0][j] = 1;
          ++cnt[k];
        }
      for (int i = 1; i < h; ++i)
        if (res[k][i - 1][w - 1] == 0 && res[k][i - 1][w - 2] == 0) {
          res[k][i][w - 1] = 1;
          ++cnt[k];
        }

      for (int j = w - 2; j >= 0; --j)
        if (res[k][h - 1][j + 1] == 0 && res[k][h - 2][j + 1] == 0) {
          res[k][h - 1][j] = 1;
          ++cnt[k];
        }
      for (int i = h - 2; i > 0; --i) {
        if (res[k][i + 1][0] == 0 && res[k][i + 1][1] == 0 &&
            res[k][i - 1][1] == 0 && res[k][i - 1][0] == 0) {
          res[k][i][0] = 1;
          ++cnt[k];
        }
      }
    }

    int result;
    if (cnt[0] > cnt[1])
      result = 0;
    else
      result = 1;

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j)
        cout << res[result][i][j];
      cout << "\n";
    }
    cout << "\n";
  }
  return 0;
}
