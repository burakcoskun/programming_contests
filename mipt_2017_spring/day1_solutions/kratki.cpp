#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

const int MAX = 5050;
const int inf = 2e9;

int f[MAX][MAX];
int g[MAX][MAX];
int a[MAX];
int s[MAX]; // s[i] = suma prvih i elemenata niza a

int calc(int x, int y) {
  int m = (x + y) / 2;
  return s[y] - s[m] - (s[m] - s[x]) + a[m]*((m-x) - (y-m));
}

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  sort(a, a + n);
  for (int i = 0; i < n; ++i)
    s[i + 1] = s[i] + a[i];

  for (int j = 1; j <= n; ++j)
    for (int i = 0; i < n; ++i) {
      if (j == 1) {
        f[j][i] = calc(i, n);
        g[j][i] = n;
      } else {
        f[j][i] = inf;
        for (int ni = i == 0 ? 0 : g[j][i-1]; ni <= g[j-1][i]; ++ni) {
          int nf = calc(i, ni) + f[j-1][ni];
          if (nf < f[j][i]) f[j][i] = nf, g[j][i] = ni;
        }
      }
    }
  
  for (int k = 1; k <= n; ++k) {
    printf("%d", f[k][0]);
    putchar(k < n ? ' ' : '\n');
  }
  return 0;
}
