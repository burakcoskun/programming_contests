#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
  if (y == 0)
    return x;
  return gcd(y, x % y);
}

const int maxn = 200005;
int n, m;
int a[maxn], b[maxn];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < m; ++i)
    cin >> b[i];

  ll res = a[0];
  for (int i = 1; i < n; ++i)
    res = gcd(res, a[i]);

  for (int i = 0; i < m; ++i)
    cout << gcd(res, b[i]) << " ";
  cout << "\n";

  return 0;
}
