#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n, m;
int a[300005], b[300005];

bool find(int x, int y) {
  for (int i = 0; i < m; ++i)
    if (a[i] != x && b[i] != x && a[i] != y && b[i] != y)
      return false;
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i)
    scanf("%d%d", &a[i], &b[i]);
  int x, y;
  for (int i = 0; i < 2; ++i) {
    if (!i)
      x = a[0];
    else
      x = b[0];

    bool check = true;
    int pos;
    for (int j = 1; j < m; ++j) {
      if (a[j] != x && b[j] != x) {
        check = false;
        check = check | find(x, a[j]);
        check = check | find(x, b[j]);
        break;
      }
    }

    if (check) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
