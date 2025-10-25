#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n), check(105);
    int g = 100, m = 0;
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
      g = gcd(g, a[i]);
      m = max(m, a[i]);
    }
    int k = m / g;
    int res = k;
    for(int i = 0; i < n; ++i)
      if(a[i] != m)
        check[k-(a[i]/g)] = 1;
    for(int i = 0; i < 101; ++i)
      res += check[i];
    cout << res << endl;
  }
  return 0;
}
