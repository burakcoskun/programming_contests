#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n,x,y;
    cin >> n >> x >> y;
    x = abs(x);
    y = abs(y);
    string s;
    cin >> s;
    vector<int> cnt(2);
    for(int i = 0; i < n; ++i) {
      if(s[i] == '4')
        ++cnt[0];
      else
        ++cnt[1];
    }
    bool res = true;
    if(cnt[0] + cnt[1] < max(x,y))
      res = false;
    if(cnt[0] + cnt[1]*2 < x + y)
      res = false;
    if(!res)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
