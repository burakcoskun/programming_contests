#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n, m;
int a[300005], b[300005];

bool ok(int k) {
  for (int i = 0; i < n; ++i)
    b[i] = a[i];
  if (b[0] + k >= m)
    b[0] = 0;
  for (int i = 1; i < n; ++i) {
    int req = b[i - 1] + m - b[i];
    if (req <= k)
      b[i] = b[i - 1];
    else if (b[i] < b[i - 1] && b[i - 1] - b[i] <= k)
      b[i] = b[i - 1];
  }
  for (int i = 1; i < n; ++i) {
    if (b[i] < b[i - 1])
      return false;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  int l = 0, r = m - 1, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (ok(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", r + 1);

  return 0;
}
