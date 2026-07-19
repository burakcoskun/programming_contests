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
    sort(a.begin(), a.end());
    int ans = true;
    for(int i = 1; i + 1< n; i += 2)
      if(a[i] != a[i+1])
        ans = false;
    if(ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
