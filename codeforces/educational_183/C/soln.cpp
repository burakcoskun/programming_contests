#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    string s;
    cin >> n >> s;
    int target = 0;
    vector<int> last_pos(2*n+4, -1);
    last_pos[n] = 0;
    for(int i = 0; i < n; ++i) {
      if(s[i] == 'a')
        ++target;
      else
        --target;
    }
    if(target == 0) {
      cout << 0 << endl;
      continue;
    }

    int cnt = 0;
    int res = n;
    for(int i = 0; i < n; ++i) {
      if(s[i] == 'a')
        ++cnt;
      else
        --cnt;
      
      int need = cnt - target + n;
      if(last_pos[need] != -1)
        res = min(res, i+1 - last_pos[need]);

      last_pos[cnt + n] = i + 1;
    }
    if(res == n)
      res = -1;
    cout << res << endl;
  }
  return 0;
}
