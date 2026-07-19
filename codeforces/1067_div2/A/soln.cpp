#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    int r, y;
    cin >> n >> y >> r;
    cout << min(n, r + y / 2) << endl;
  }
  return 0;
}
