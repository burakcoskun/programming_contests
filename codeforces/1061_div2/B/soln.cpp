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

    int check = false;
    for(int i = 0; i< n; ++i)
      if(s[i] == 'B')
        check = true;
    for(int i = 0 ; i < q; ++i) {
      int a;
      cin >> a;
      if(!check) 
        cout << a << endl;
      else {
        int res = 0;
        int step = 0;
        while(a) {
          if(s[step] == 'A')
            a--;
          else
            a/=2;
          ++res;
          step+= 1;
          step %= n;
        }
        cout << res << endl;
      }
    }
  }
  return 0;
}
