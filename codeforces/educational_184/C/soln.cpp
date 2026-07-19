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
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
      cin >> a[i];
    
    vector<long long> px_sum(n), sx_sum(n);
    px_sum[0] = a[0];
    for(int i = 1 ; i < n; ++i)
      px_sum[i] = px_sum[i-1] + a[i];
    sx_sum[n-1] = a[n-1];
    for(int i = n -2; i>=0; --i)
      sx_sum[i] = sx_sum[i+1] + a[i];
    
    long long pre_sum = 0;
    long long right = 0;
    long long left = 0;
    long long res = 0;
    while(right < n) {
      pre_sum += (right+1)*2-a[right];
      
      res = max(res,pre_sum + px_sum[n-1]);
      // cout << left << " " << right << " "<< res << " left_sum:" << left_sum << " right_sum: " << right_sum << endl;
      if(pre_sum< 0) {
        left = right +1;
        pre_sum = 0;
      }
      ++right;
    }
    cout << res << endl;
  }
  return 0;
}
