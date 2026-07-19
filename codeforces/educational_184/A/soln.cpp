#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, a;
    cin >> n >> a;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());
    int left = 0, right = 0;
    for(int i = 0; i < n; ++i) {
      if(v[i] < a)
        ++left;
      else if(v[i] > a)
        ++right;
    }
    if(left > right)
      cout << a - 1 << endl;
    else
      cout << a + 1 << endl;
  }
  return 0;
}
