#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> d(n), l(n), r(n);
    for(int i = 0; i < n; ++i)
      cin >> d[i];
    for(int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i];
    }

    int h = 0;
    bool res = true;
    stack<int> pos;
    for(int i = 0; i < n; ++i) {
      if(d[i] == 1 ) ++h;
      else if(d[i] == -1)
        pos.push(i);
      // cout << "h:"<< h << endl;
      if(h > r[i]) {
        res = false;
        // cout << "hres:"<< h << " " << res << "ll:" << l[i] << " r:" << r[i] << endl;
        break;
      }
      while(h < l[i] && !pos.empty()) {
        ++h;
        d[pos.top()] = 1;
        pos.pop();
      }
      if(h < l[i]) {
        res = false;
        // cout << "hres:"<< h << " " << res << "lll:" << l[i] << " r:" << r[i] << endl;
        break;
      }
      // cout << "hres:"<< h << " " << res << "l:" << l[i] << " r:" << r[i] << endl;
    }
    // cout << res << endl;

    h = 0;
    for(int i = 0 ; i < n; ++i) {
      if(d[i] == 1)
        ++h;
      if(h < l[i] || h > r[i]) {
        res = false;
        break;
      }
    }
    if(res) {
      for (int i = 0; i < n; ++i) {
        if(d[i] == -1)
          cout << 0 << " ";
        else
          cout << d[i] << " ";
      }
      cout << endl;
    }
    else
      cout << -1 << endl;
  }

  return 0;
}
