#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    long long res = (long long)n*(n+1)*(n+2)/6;
    for(int i = 0; i < n; ++i) {
      if(a[i] < a[i+1])
        res -= (long long)(i+1) * (n-(i+1));
    }
    cout << res << endl;
  }
  return 0;
}
