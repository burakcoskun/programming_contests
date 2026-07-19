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
    for(int i = 0; i < n; ++i)
      cin >> a[i];
    
    int c_max = 0, inc = 0;
    vector<int> incr_pos;
    set<int> incr_pos_set;
    int nd_start = 0;
    for(int i = 0; i < n; ++i) {
      if(a[i] < c_max){
        incr_pos.push_back(i);
        incr_pos_set.insert(i);
        inc = max(inc, c_max - a[i]);
      }
      c_max = max(c_max, a[i]);
    }
    bool res = true;
    for(int i = 0; i < incr_pos.size(); ++i)
      a[incr_pos[i]] += inc;
    for(int i = 1; i < n; ++i) {
      if(a[i] < a[i-1] && incr_pos_set.find(i) == incr_pos_set.end())
        a[i] += inc;
      // cout << a[i] << " ";
    }
    // cout << endl;
    for(int i = 1; i < n; ++i)
      if(a[i] < a[i-1])
        res = false;
    if(res)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
