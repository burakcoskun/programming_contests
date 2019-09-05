#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n;
ll res;
ll top = ((ll)1 << 32) - 1;
vector<ll> muls;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "add") {
      ll mul = 1;
      for (int j = 0; j < muls.size(); ++j) {
        mul *= muls[j];
        if (mul > top) {
          printf("OVERFLOW!!!\n");
          return 0;
        }
      }
      res += mul;
    } else if (s == "for") {
      ll tmp;
      cin >> tmp;
      muls.push_back(tmp);
    } else {
      muls.pop_back();
    }
    if (res > top) {
      printf("OVERFLOW!!!\n");
      return 0;
    }
  }
  cout << res << endl;
  return 0;
}
