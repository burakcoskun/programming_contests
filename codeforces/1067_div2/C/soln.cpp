#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    for(int i = 0 ; i < n; ++i)
      cin >> a[i];
    for(int i = 0; i < n; ++i)
      cin >> b[i];
    
    vector<long long> left_sum(n), right_sum(n);
    long long current_sum = 0;
    for(int i = 0; i < n; ++i){
      current_sum += a[i];
      if(current_sum > 0)
        left_sum[i] = current_sum;
      else
        current_sum = 0;
    }
    current_sum = 0;
    long long max_sum = -1e9 - 10;
    for(int i = n - 1; i >= 0; --i) {
      current_sum += a[i];
      max_sum = max(current_sum, max_sum);
      if(current_sum > 0)
        right_sum[i] = current_sum;
      else
        current_sum = 0;
    }
    if(k % 2 == 0) {
      cout << max_sum << endl;
      continue;
    }

    long long res = -1e9 - 5;
    for(int i = 0; i < n; i++) {
      long long left = i > 0 ? left_sum[i-1] : 0;
      long long right = i < n - 1 ? right_sum[i+1] : 0;
      res = max(res, left+right+a[i]+abs(b[i]));
    }
    cout << res << endl;
  }
  return 0;
}
