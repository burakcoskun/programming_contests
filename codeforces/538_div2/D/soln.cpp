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

int dp[2][5005][5005];
bool found[2][5005][5005];
int n, a[5005], res = 1e7;

int calc(int a, int b) {
  if (a == b)
    return 0;
  return 1;
}

int solve(int w, int l, int r) {
  if (found[w][l][r])
    return dp[w][l][r];
  found[w][l][r] = 1;
  if (l == 0 && r == n - 1)
    return 0;
  int color;
  if (!w)
    color = a[l];
  else
    color = a[r];
  if (l == 0)
    return dp[w][l][r] = solve(1, l, r + 1) + calc(a[r + 1], color);
  if (r == n - 1)
    return dp[w][l][r] = solve(0, l - 1, r) + calc(a[l - 1], color);
  return dp[w][l][r] = min(solve(0, l - 1, r) + calc(a[l - 1], color),
                           solve(1, l, r + 1) + calc(a[r + 1], color));
}

void read_input() {
  scanf(" %d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %d", &a[i]);
  }

  for (int i = 0; i < n; ++i)
    res = min(res, solve(0, i, i));
  cout << res << endl;
}

int main() {
  read_input();
  return 0;
}
