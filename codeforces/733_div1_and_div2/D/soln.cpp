#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }

    vector<int> used(n), res(n), rev(n);
    vector<int> rem;
    for (int i = 0; i < n; ++i) {
      if (!used[a[i]]) {
        res[i] = a[i] + 1;
        rev[a[i]] = i;
        used[a[i]] = 1;
      }
    }
    for (int i = 0; i < n; ++i)
      if (!used[i])
        rem.push_back(i);
    sort(rem.begin(), rem.end(), greater<int>());
    int pos = 0;
    for (int i = 0; i < n; ++i)
      if (!res[i])
        res[i] = rem[pos++] + 1;

    //  for (int i = 0; i < n; ++i)
    //     cout << res[i] << " ";
    //    cout << "\n";

    for (int i = 0; i < n; ++i)
      if (i + 1 == res[i]) {
        res[i] = a[i] + 1;
        res[rev[a[i]]] = i + 1;
      }
    int ans = 0;
    for (int i = 0; i < n; ++i)
      if (res[i] == a[i] + 1)
        ++ans;

    cout << ans << "\n";
    for (int i = 0; i < n; ++i)
      cout << res[i] << " ";
    cout << "\n";
  }

  return 0;
}
