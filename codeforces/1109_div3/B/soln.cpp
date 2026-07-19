#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    bool res = true;
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
      if (res && sum < (i + 1) * (i + 2) / 2) {
        res = false;
        cout << "NO" << endl;
      }
    }
    if (res)
      cout << "YES" << endl;
  }
  return 0;
}
