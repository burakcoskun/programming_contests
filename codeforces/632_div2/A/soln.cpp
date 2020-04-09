#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  for (int t = 0; t < T; ++t) {
    cin >> n >> m;

    cout << 'W';
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        if (i != 0 || j != 0)
          cout << 'B';
      cout << '\n';
    }
  }
  return 0;
}
