#include <bits/stdc++.h>

using namespace std;

long long bad(long long x) {
    long long res = 0;
    res += (x/2 + x/3 + x/5 + x/7);
    res -= (x/(2*3) + x/(2*5) + x/(2*7) + x/(3*5) + x/(3*7) + x/(5*7));
    res += (x/(2*3*5) + x/(2*3*7) + x/(2*5*7) + x/(3*5*7));
    res -= (x/(2*3*5*7));
    return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    long long l, r;
    cin >> l >> r;
    
    long long bad_l = bad(l-1);
    long long bad_r = bad(r);
    long long bad_between = bad_r - bad_l;
    long long result = (r-(l-1)) - bad_between;
    cout << result << endl;
  }
  return 0;
}
