#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int a, b;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> a >> b;
    if (__gcd(a, b) > 1)
      cout << "Infinite\n";
    else
      cout << "Finite\n";
  }
  return 0;
}
