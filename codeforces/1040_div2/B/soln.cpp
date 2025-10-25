#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    vector<int> cnt(3);
    for(int i =0; i < n; ++i) {
      cin >> a[i];
      ++cnt[a[i]];
    }
    int sum = cnt[1] + 2*cnt[2];
    if(sum > s) {
      for(int i = 0; i <n ; ++i)
        cout << a[i] << " ";
      cout << endl;
      continue;
    }
    if(s == sum + 1) {
      for(int i = 0; i < cnt[0]; ++i)
        cout << "0 ";
      for(int i = 0; i < cnt[2]; ++i)
        cout << "2 ";
      for(int i = 0; i < cnt[1]; ++i)
        cout << "1 ";
      cout << endl;
    }
    else
      cout << -1 << endl;
  }
  return 0;
}
