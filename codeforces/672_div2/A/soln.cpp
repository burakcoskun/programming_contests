#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    bool check = false;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (i > 0 && a[i] >= a[i - 1])
        check = true;
    }
    if (check)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
