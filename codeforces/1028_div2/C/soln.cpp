#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int gcd(int a, int b){
  if(a == 0)
    return b;
  return gcd(b % a, a);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; ++i)
      cin >> a[i];
    int min_gcd = 5000;
    int min_x, min_y;
    for(int i = 0; i <n; ++i)
      for(int j = i+1; j < n; ++j) {
        int cur_gcd = gcd(a[i], a[j]);
        if(cur_gcd < min_gcd) {
          min_x = i;
          min_y = j;
          min_gcd = cur_gcd;
        }
      }
    int res = 0;
    for(int i = 0; i < n; ++i) {
      if(a[i] != min_gcd) {
        ++res;
      }
    }
    cout << res << endl;
  }
  return 0;
}
