#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> q(n), r(n);
    for(int i = 0; i < n; ++i)
      cin >> q[i];
    for(int i = 0; i < n; ++i)
      cin >> r[i];
    sort(r.begin(), r.end());
    sort(q.begin(), q.end(), greater<long long>());

    int point_q = 0;
    int point_r = 0;
    int res = 0;
    while(point_q < n && point_r < n) {
      long long min_y = r[point_r] + 1;
      while(point_q < n) {
        long long cur_x = q[point_q] * min_y + r[point_r];
        if(cur_x <= k)
          break;
        ++point_q;
      }
      if(point_q < n)
        ++res;
      ++point_q;
      ++point_r;
    }
    cout << res << endl;
  }
  return 0;
}
