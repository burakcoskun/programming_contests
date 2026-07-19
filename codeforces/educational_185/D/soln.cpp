#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cnt_minus_one = 0;
    int cnt_one = 0;
    int cnt_double = 0;
    for(int i = 0; i < n - 1; ++i) {
      if(s[i] == '?' && (s[i+1] == 'X' || s[i+1] == 'V'))
        ++cnt_minus_one;
      else if(s[i] == '?' && s[i+1] == 'I')
        ++cnt_one;
      else if(s[i] == '?' && s[i+1] == '?') {
        ++cnt_double;
        ++i;
      }
    }
    int res = 0;
    for(int i = 0; i < n; ++i) {
      if(s[i] == 'X')
        res += 10;
      else if(s[i] == 'V')
        res += 5;
      else if(s[i] == 'I') {
        if(i+1 == n)
          res += 1;
          
      }
    }
    for(int i = 0; i < q; ++i) {
      int X, V, I;
      cin >> X >> V >> I;
    }

  }
  return 0;
}
