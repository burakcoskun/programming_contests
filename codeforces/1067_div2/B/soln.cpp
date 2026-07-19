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
    vector<int> cnt(2*n+1);
    for(int i = 0; i < 2 * n; ++i) {
      int a;
      cin >> a;
      ++cnt[a];
    }

    int num_odds = 0;
    int direct_evens = 0;
    int more_evens = 0;

    int res = 0;
    for(int i = 1 ; i <= 2*n; ++i) {
      if(cnt[i] > 0 ){
          if(cnt[i] % 2)
            ++num_odds;
          else if((cnt[i]/2) % 2)
            ++direct_evens;
          else
            ++more_evens;
      }
    }
    res = num_odds;
    if(more_evens % 2 ) {
      if(num_odds)
        res+=2;
      --more_evens;
    }
    res += more_evens*2;

    res += direct_evens*2;
    cout << res << endl;
  }
  return 0;
}
