#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    long long n,c;
    cin >> n >> c;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    int res = 0;
    sort(a.begin(), a.end());
    while( a[n-1] != 0) {
      // cout << a[n-1] << endl;
      // for(int i = 0; i< n; ++i)
      //   cout << a[i] << " ";
      sort(a.begin(), a.end());
      bool found = false;
      for(int i = n-1; i>=0; --i){
        if(a[i] <= c && a[i] != 0) {
          a[i] = 0;
          found = true;
          break;
        }
      }
        if(found == false) {
          a[n-1] = 0;
          ++res;
        }
        for(int i = 0; i <n ; ++i)
          if(a[i] <= c)
            a[i] = a[i] * 2;
        sort(a.begin(), a.end());
    }
    cout << res << endl;
  }

  return 0;
}
