#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> a;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  a.resize(n + 1);
  for (int i = 2; i <= n; ++i)
    a[i] = 1;

  for (int i = 2; i <= n; ++i)
    for (int j = i + i; j <= n; j += i)
      a[j] = max(a[j], i);

  sort(a.begin() + 2, a.end());
  for (int i = 2; i <= n; ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
