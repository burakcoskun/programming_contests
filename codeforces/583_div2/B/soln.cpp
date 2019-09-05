#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int b, g, n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> b >> g >> n;

  int res = 0;
  for (int i = 0; i <= n; ++i) {
    int bl = i, red = n - i;
    if (bl <= b && red <= g)
      ++res;
  }

  cout << res << endl;
  return 0;
}
