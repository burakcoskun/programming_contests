#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long mod_num = 998244353;
long long max_n = 1e5+10;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<long long> p2(max_n);
  p2[0] = 1;
  for(int i = 1; i < max_n; ++i) {
    p2[i] = p2[i-1] * 2;
    p2[i] = p2[i] % mod_num;
  }

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for(int i = 0; i < n; ++i)
      cin >> p[i];
    for(int i = 0; i < n; ++i)
      cin >> q[i];

    int p_max = 0;
    int p_max_pos = 0;
    int q_max = 0;
    int q_max_pos = 0;
    for(int i = 0; i < n; ++i) {
      if(p_max < p[i]) {
        p_max = p[i];
        p_max_pos = i;
      }
      if(q_max < q[i]) {
        q_max = q[i];
        q_max_pos = i;
      }
      // cout << p2[p_max] << " " << p2[q[i-p_max_pos]] << endl;
      long long res; 
      if(p_max == q_max) {
        if(q[i-p_max_pos] > p[i-q_max_pos])
          res = p2[p_max] + p2[q[i-p_max_pos]];
        else
          res = p2[q_max] + p2[p[i-q_max_pos]];
      }
      else if(p_max > q_max)
        res = p2[p_max] + p2[q[i-p_max_pos]];
      else
        res = p2[q_max] + p2[p[i-q_max_pos]];
      res = res % mod_num;
      cout << res << " ";
    }
    cout << endl;
  }

  return 0;
}
