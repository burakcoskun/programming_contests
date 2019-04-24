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

int n, m;
int c[505][505], res[505], st[505];
int dp[505][1025];

int solve(int row, int num) {
  if (dp[row][num])
    return dp[row][num];

  if (row == n) {
    // cout << num << endl;
    if (num > 0) {
      for (int i = 0; i < n; ++i)
        res[i] = st[i];
      return 1;
    }
    return -1;
  }

  for (int j = 0; j < m; ++j) {
    st[row] = j + 1;
    if (solve(row + 1, num ^ c[row][j]) == 1)
      return dp[row][num] = 1;
  }
  return dp[row][num] = -1;
}

void read_input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf(" %d", &c[i][j]);

  // cout << solve(0, 0);

  if (solve(0, 0) == 1) {
    printf("TAK\n");
    for (int i = 0; i < n; ++i)
      printf("%d ", res[i]);
    printf("\n");
  } else
    printf("NIE\n");
}

int main() {
  read_input();
  return 0;
}
