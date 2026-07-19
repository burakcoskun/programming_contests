#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    long long int a, b, n;
    cin >> a >> b >> n;
    int res;
    if(b >= a || n * b <= a)
      res = 1;
    else
      res = 2;
    cout << res << endl;
  }
  return 0;
}
