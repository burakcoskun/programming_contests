#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int dp[10][10];
int cf[10][10];
const int inf = 1e9;

void calc_dp(int x, int y) {
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
      dp[i][j] = inf;

  for (int a = 0; a < 10; ++a)
    for (int cntx = 0; cntx < 10; ++cntx)
      for (int cnty = 0; cnty < 10; ++cnty) {
        if (cntx == 0 && cnty == 0)
          continue;
        int b = (a + cntx * x + cnty * y) % 10;
        dp[a][b] = min(dp[a][b], cntx + cnty);
      }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  for (int i = 0; i < s.size() - 1; ++i)
    cf[s[i] - '0'][s[i + 1] - '0']++;

  for (int x = 0; x < 10; ++x, cout << endl)
    for (int y = 0; y < 10; ++y) {
      calc_dp(x, y);
      int res = 0;
      for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
          if (cf[i][j]) {
            if (dp[i][j] == inf) {
              res = -1;
              j = 10;
              i = 10;
            } else {
              res += (dp[i][j] - 1) * cf[i][j];
            }
          }
      cout << res << " ";
    }

  return 0;
}
