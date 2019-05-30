#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n, a, x, b, y;

int main() {
  scanf("%d%d%d%d%d", &n, &a, &x, &b, &y);

  while (a != x && b != y) {
    if (a == b) {
      printf("YES\n");
      return 0;
    }
    if (a < n)
      ++a;
    else
      a = 1;
    if (b > 1)
      --b;
    else
      b = n;
  }
  if (a == b)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
