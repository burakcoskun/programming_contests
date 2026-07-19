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
    vector<int> b(n);
    long long sum = 0;
    long long cnt_0 = 0;
    for(int i = 0; i < n; ++i) {
      cin >> b[i];
      sum += b[i];
      if(!b[i])
        ++cnt_0;
    }

    if(sum >= 2*n)
      cout << n - cnt_0 << endl;
    else
      cout << min(sum - n + 1, n - cnt_0) << endl;
  }
  return 0;
}
