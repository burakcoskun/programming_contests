#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int x, y;
    cin >> x >> y;
    int diff = max(x,y) - min(x,y);

    int res = 0;
    for(int i = 1; i * i <= diff;++i) {
      if(diff % i == 0) {
        ++res;
        if(i*i != diff)
          ++res;
      }
    }
    if(res == 0)
      ++res;
    cout << res << endl;
    for(int i = 0; i < x; ++i)
      cout << 1 << " ";
    for(int i = 0; i < y; ++i)
      cout << -1 << " ";
    cout << endl;
  }
  return 0;
}
