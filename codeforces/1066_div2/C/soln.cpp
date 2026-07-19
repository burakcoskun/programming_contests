#include <bits/stdc++.h>

using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> res(n);
    vector<int> w(n);
    for(int i = 0; i < q; ++i) {
      int c, l ,r ;
      cin >> c >> l >> r;
      for(int j = l-1; j < r ; ++j) {
        if(w[j] == 0 || w[j] == c)
          w[j] = c;
        else
          w[j] = 3;
      }
    }
    int cnt = 0;
    for(int i = 0; i <n ; ++i) {
      if(w[i] == 0 || w[i] == 3)
        res[i] = k + 1;
      else if(w[i] == 1)
        res[i] = k;
      else {
        res[i] = cnt % k;
        ++cnt; 
      }
    }
    for(int i = 0; i < n; ++i)
      cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}
