#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
const int maxn = 1e5 + 1;
int T;

ll find_a(ll k) { return k / 3; }

ll find_b(ll k) {
  ll res = 0;
  k = k / 3;
  while (k) {
    ll pow = 1;
    while (pow <= k)
      pow *= 4;
    pow /= 4;
    if (k >= pow && k < pow * 2) {
      res += pow * 2;
      k -= pow;
    } else if (k >= pow * 2 && k < pow * 3) {
      res += pow * 3;
      k -= pow * 2;
    } else {
      res += pow;
      k -= pow * 3;
    }
    // cout << res << " " << k << " " << pow << endl;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while (T--) {
    cin >> n;

    ll pow = 1;
    while (pow <= n) {
      pow *= 4;
    }
    pow /= 4;

    if (n % 3 == 1)
      cout << find_a(n - (pow - 1)) + pow << "\n";
    else if (n % 3 == 2)
      cout << find_b(n - (pow - 1)) + pow * 2 << "\n";
    else {
      ll a = find_a(n - 2 - (pow - 1)) + pow;
      ll b = find_b(n - 1 - (pow - 1)) + pow * 2;
      cout << (a ^ b) << "\n";
    }
  }
  return 0;
}
