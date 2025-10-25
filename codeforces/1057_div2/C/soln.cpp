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
    sort(a.begin(), a.end());
    vector<int> odd_sticks;
    long long len_pairs = 0;
    int tot_size = 0 ;
    for(int i = 0; i < n ; ++i) {
      if(i < n - 1 && a[i] == a[i+1]) {
        ++i;
        len_pairs += a[i]*2;
        tot_size += 2;
      }
      else
        odd_sticks.push_back(a[i]);
    }
    long long max_odd_sticks = 0;
    // cout << "len:" << len_pairs << endl;
    for(int i = 0 ; i < odd_sticks.size(); ++i) {
      if(odd_sticks[i] < len_pairs) {
        tot_size++;
        max_odd_sticks = max(max_odd_sticks, (long long)odd_sticks[i]);
      }
      if(i > 0 && (odd_sticks[i] - odd_sticks[i-1]) < len_pairs) {
        tot_size++;
          max_odd_sticks = max(max_odd_sticks, (long long)odd_sticks[i] + (long long)odd_sticks[i-1]);
      }

    }
    // cout << tot_size << " " << "odd_sticks:" << odd_sticks.size() << endl;
    if(tot_size >= 3)
      cout << len_pairs + max_odd_sticks << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
