#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

#define maxn 1002

int mod = 1e9 + 7;
int n;
int dp[maxn * 2][maxn * 2][2];

int solve(int d, int c, int p) {
  // cout << d << " " << c << " " << endl;
  if (c < 0 || c > n)
    return -1;

  if (dp[d][c][p] != -2)
    return dp[d][c][p];

  if (d == 2 * n) {
    if (c == 0)
      return 0;
    return -1;
  }

  int res1 = -1, res2 = -1;
  int sol1 = solve(d + 1, c + 1, 0);
  int sol2 = solve(d + 1, c - 1, 0);

  res1 = max(sol1, sol2);
  if (sol1 != -1 && sol2 != -1)
    res1 = max(res1, sol1 + sol2);

  if (!p) {
    int sol3 = solve(d + 1, c + 1, 1);
    int sol4 = solve(d + 1, c - 1, 1);

    if (sol3 != -1)
      res1 = max(res1, sol3 + 1);
    if (sol1 != -1 && sol4 != -1)
      res1 = max(res1, sol1 + sol4 + 1);
    if (sol2 != -1 && sol3 != -1)
      res1 = max(res1, sol2 + sol3 + 1);
    if (sol4 != -1)
      res1 = max(res1, sol4 + 1);
  }

  if (res1 < 0)
    return dp[d][c][p] = -1;
  return dp[d][c][p] = res1 % mod;
}

int main() {
  cin >> n;
  for (int i = 0; i <= 2 * n; ++i)
    for (int j = 0; j <= 2 * n; ++j)
      for (int k = 0; k < 2; ++k)
        dp[i][j][k] = -2;
  cout << solve(0, 0, 0) << endl;
  return 0;
}
