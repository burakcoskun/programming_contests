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

    if(n % 3 == 0)
      cout << 0 << endl;
    else {
      cout << 3 - (n % 3) << endl;
    }
  }
  return 0;
}
