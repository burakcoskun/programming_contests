#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 1;
int T;
ll n, x;
ll a[maxn];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    sort(a, a + n, greater<int>());

    ll sum = 0;
    ll p = 0;
    while (p < n && a[p] >= x) {
      sum += a[p];
      ++p;
    }
    while (p < n) {
      ll nsum = sum + a[p];
      if (nsum >= (p + 1) * x) {
        sum = nsum;
        ++p;
      } else
        break;
    }
    cout << p << "\n";
  }
  return 0;
}
