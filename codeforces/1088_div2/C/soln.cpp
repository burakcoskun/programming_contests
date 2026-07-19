#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int k, n;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<int> dup(n+1);
    int overlap = 2 * k - n;
    int overlap_start = n - k;
    int overlap_end = k-1;
    bool ans = true;
    for(int i = 0; i < n; ++i)
      cin >> a[i];
    for(int i = 0; i < n; ++i) {
      cin >> b[i];
      if(b[i] != -1 && dup[b[i]])
        ans = false;
      if(b[i] != -1)
        dup[b[i]] = 1;
      if(overlap > 1 && i >= overlap_start && i <= overlap_end)
        continue;
      if(k!= n && b[i] != -1 && b[i] != a[i])
        ans = false;
    }
    if(overlap > 1) {
      // cout << ans << endl;
      vector<int> a_cnt(n+1);
      vector<int> b_cnt(n+1);
      for(int i = overlap_start; i <= overlap_end; ++i) {
        a_cnt[a[i]]++;
        if(b[i] != -1)
          b_cnt[b[i]++];
      }
      for(int i = 1; i<=n; ++i)
        if(b_cnt[i] > a_cnt[i]) {
          ans = false;
          // cout << "not found: "<< b_elem << endl;
        }
      // cout << ans << endl;
    }
    if(ans == false) {
      cout << "NO" << endl;
    }
    else
      cout << "YES" << endl;

  }
  return 0;
}
