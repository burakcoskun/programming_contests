#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n;
    int temp = n;
    int d = 0;
    while (temp) {
      temp /= 10;
      ++d;
    }

    int res = 0;
    vector<long long> num;
    for (int k = 1; k <= 9; ++k) {
      num.push_back(k);
      for (int i = 0; i < d - 1; ++i) {
        num[k - 1] = num[k - 1] * 10 + k;
      }
      if (num[k - 1] <= n)
        res += 1;
    }

    cout << (d - 1) * 9 + res << endl;
  }
  return 0;
}
