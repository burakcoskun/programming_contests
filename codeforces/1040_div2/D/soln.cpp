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
    vector<int> a(n), pos(n+1);
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    int res = 0;
    for(int cur = 1; cur <= n; ++cur) {
      int big = 2 * n - cur;
      int inv_cur = 0, inv_big = 0;
      for(int i = 0; i < n; ++i){
        if(a[i] != cur) {
          if(i < pos[cur]) {
            if(a[i] > cur)
              ++inv_cur;
            if(a[i] > big)
              ++inv_big;
          }
          else {
            if(cur > a[i])
              ++inv_cur;
            if(big > a[i])
              ++inv_big;
          }
        }
      }
      res += min(inv_big, inv_cur);
      if(inv_big < inv_cur)
        a[pos[cur]] = big;
    }
    cout << res/2 << endl;
  }
  return 0;
}
