#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int T;
int n, k;
int a[200005], pos;

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    ll res = 1e9;
    for (int i = 0; i + k < n; ++i) {
      ll mid = (a[i] + a[i + k]) / 2;
      ll dist = max(mid - a[i], a[i + k] - mid);
      if (res > dist) {
        res = dist;
        pos = mid;
      }
    }
    printf("%d\n", pos);
  }
  return 0;
}
