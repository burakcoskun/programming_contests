#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

ll a, b, q;

ll calc(ll k, ll cnt, ll ek, vector<ll> &count) {
  ll res = 0;
  res += (k / ek) * cnt;

  res += count[(int)(k % ek)];
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  /*
  for (ll i = 100; i <= 200; ++i) {
    ll a = (i % 7) % 10;
    ll b = (i % 10) % 7;

    cout << i << " ";
    cout << a << " " << b << " ";
    if (a == b)
      cout << "yes";
    cout << endl;
  }*/

  ll t;
  cin >> t;
  while (t--) {

    cin >> a >> b >> q;
    ll ek = lcm(a, b);
    vector<ll> count(ek + 1);
    ll cnt = 0;
    for (int i = 1; i <= ek; ++i) {
      if (i % a % b != i % b % a)
        ++cnt;
      count[i] = cnt;
    }
    ll l, r;
    for (ll i = 0; i < q; ++i) {
      cin >> l >> r;

      cout << calc(r, cnt, ek, count) - calc(l - 1, cnt, ek, count) << " ";
    }
    cout << "\n";
  }
  return 0;
}
