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
    map<int,int> possible_cnt;
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
      int k = a[i];
      if(a[i] == 1)
        possible_cnt[2] ++;
      while(k>1 ) {
        possible_cnt[k]++;
        if(k % 2 == 0) 
          k /= 2;
        else
          k += 1;
      }
      for (auto it = possible_cnt.begin(); it != possible_cnt.end(); ) {
          if (it->second != i + 1) {
              it = possible_cnt.erase(it); // returns the next valid iterator
          } else {
              ++it;
          }
      }
    }
    set<int> possible;
    for(auto p_cnt: possible_cnt) {
      if(p_cnt.second == n)
        possible.insert(p_cnt.first);
    }
    // cout << possible_cnt[2] << " sadfas "<< endl;
    possible.insert(1);
    long long res = 1e18;
    for(auto p: possible) {
      long long int cnt = 0;
      int can = true;
      for(int i = 0 ; i < n; ++i) {
        int k = a[i];
        while(k != p && k >= p-1) {
          ++cnt;
          if(k % 2 == 0) 
            k /= 2;
          else
            k += 1;
        }
        if(k != p)
          can = false;
        // cout << p  << "k:" << k << " cnt: "<< cnt << " can:" << can << endl;
      }
      // cout << p << " cnt: "<< cnt << " can:" << can << endl;
      if(can)
        res = min(res, cnt);
    }
    cout << res << endl;
  }
  return 0;
}
