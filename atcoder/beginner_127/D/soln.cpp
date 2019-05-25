#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n, m;
int a[100005];
vector<pair<int, int>> cb;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for (int i = 0; i < m; ++i) {
    int b, c;
    scanf("%d%d", &b, &c);
    cb.pb(mp(c, b));
  }
  sort(a, a + n);
  sort(cb.begin(), cb.end(), greater<pair<int, int>>());
  int pos = 0, ci = 0;
  while (pos < n) {
    bool check = false;
    for (int i = 0; i < cb[ci].sc && pos < n; ++i) {
      if (a[pos] < cb[ci].fs) {
        a[pos] = cb[ci].fs;
        check = true;
      }
      pos++;
    }
    ci++;
    if (!check)
      break;
  }
  long long res = 0;
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    res += a[i];
  }
  cout << res << endl;
  return 0;
}
