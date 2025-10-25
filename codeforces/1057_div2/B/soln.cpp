#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int x, y, z;
    cin >> x >> y >> z;
    bool yes = true;
    while(x || y || z) {
      int x_b = x % 2;
      int y_b = y % 2;
      int z_b = z % 2;

      if(x_b + y_b + z_b == 2) {
        yes = false;
        break;
      }
      x /= 2;
      y /= 2;
      z /= 2;
    }
    if(yes)
      cout << "YES" << endl;
    else 
      cout << "NO" << endl;
  
  }
  return 0;

}