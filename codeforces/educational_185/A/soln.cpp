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
    int res = 0;
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j) {
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int cost = i*n + j + 1;
        for(int k = 0; k < 4; k++) {
          int x = i + dir[k][0];
          int y = j + dir[k][1];
          if(x >= 0 && y >=0 && x < n && y < n)
            cost += x * n + y + 1;
        }
        res = max(res, cost);
      }
    cout << res << endl;
  }
  return 0;
}
