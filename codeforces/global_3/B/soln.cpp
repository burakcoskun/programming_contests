#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 200005;

int n, m, ta, tb, k;
vector<ll> a, b;
ll res = 0;

int main() {
  scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
  for (int i = 0; i < n; ++i) {
    ll tmp;
    scanf("%lld", &tmp);
    a.pb(tmp);
  }
  for (int i = 0; i < m; ++i) {
    ll tmp;
    scanf("%lld", &tmp);
    b.pb(tmp);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if (k >= m || k >= n) {
    printf("-1\n");
    return 0;
  }

  for (int cb = 0; cb <= k; ++cb) {
    ll arriveb = a[cb] + ta;
    vector<ll>::iterator departb = lower_bound(b.begin(), b.end(), arriveb);
    if (departb + k - cb >= b.end()) {
      printf("-1\n");
      return 0;
    }
    departb = departb + k - cb;
    ll arrivec = *departb + tb;
    res = max(res, arrivec);
  }
  cout << res << endl;
  return 0;
}
