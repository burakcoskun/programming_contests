#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int T;
string x, y;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> x >> y;

    int res = -1;
    int yf, xf;
    for (yf = y.size(); yf >= 0; --yf) {
      if (y[yf] == '1')
        break;
    }
    xf = x.size() - 1 - (y.size() - 1 - yf);
    for (; xf >= 0; --xf)
      if (x[xf] == '1')
        break;
    int ylen = y.size() - 1 - yf;
    int xlen = x.size() - 1 - xf;
    cout << xlen - ylen << "\n";
  }
  return 0;
}
