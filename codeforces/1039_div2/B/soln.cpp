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
    
    int l = 0, r = n -1;
    string res;
    bool maxFirst = true;
    while(l < r) {
      if(maxFirst) {
        if(a[l] > a[r]) {
          res.push_back('L');
          res.push_back('R');
          l++;
          r--;
        }
        else {
          res.push_back('R');
          res.push_back('L');
          r--;
          l++;
        }
        maxFirst = false;
      }
      else {
        if(a[l] < a[r]) {
          res.push_back('L');
          res.push_back('R');
          l++;
          r--;
        }
        else {
          res.push_back('R');
          res.push_back('L');
          r--;
          l++;
        }
        maxFirst = true;
      }
    }
    if(l == r)
      res.push_back('L');
    cout << res << endl;
  }
  return 0;
}
