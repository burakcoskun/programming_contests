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

int a[505][505], b[505][505], first[500][500][2];
int n, m;

void read_input() {
  scanf(" %d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf(" %d", &a[i][j]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf(" %d", &b[i][j]);
}

void solve() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] != b[i][j]) {
        a[i][j] ^= 1;
        a[i][0] ^= 1;
        a[0][0] ^= 1;
        a[0][j] ^= 1;
      }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] != b[i][j]) {
        printf("no\n");
        return;
      }
  printf("yes\n");
}

int main() {
  read_input();
  solve();
  return 0;
}
