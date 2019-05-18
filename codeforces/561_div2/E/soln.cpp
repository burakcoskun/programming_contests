#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int d[55][10005], m, n;

int main() {
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &d[i][0]);
    for (int j = 1; j <= d[i][0]; ++j)
      scanf("%d", &d[i][j]);
  }

  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      vector<bool> used(n + 1);
      for (int k = 1; k <= d[i][0]; ++k)
        used[d[i][k]] = true;
      bool found = false;
      for (int k = 1; k <= d[j][0]; ++k)
        found |= used[d[j][k]];
      if (!found) {
        printf("impossible\n");
        return 0;
      }
    }
  }
  printf("possible\n");
  return 0;
}
