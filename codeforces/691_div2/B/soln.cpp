#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int res;
  if (n % 2 == 0) {
    res = (n / 2 + 1) * (n / 2 + 1);
  } else {
    int l = n / 2 + 1;
    int r = n / 2;
    res = (l + 1) * (r + 1) * 2;
  }
  cout << res << endl;
  return 0;
}
