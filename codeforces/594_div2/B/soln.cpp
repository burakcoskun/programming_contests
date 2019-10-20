#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll a[100005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a+n);


  ll s1 = 0, s2 = 0;
  for(int i = 0; i < n / 2; ++i)
    s1 += a[i];
  for(int i = n /2 ; i < n; ++i)
    s2 += a[i];
  cout << s1*s1 + s2*s2 << endl;

  return 0;
}
