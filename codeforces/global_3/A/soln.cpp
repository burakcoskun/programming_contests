#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

ll a, b, c, res;

int main() {
  cin >> a >> b >> c;
  res = 2 * c + min(a, b) * 2;
  if (a != b)
    ++res;
  cout << res << endl;
  return 0;
}
