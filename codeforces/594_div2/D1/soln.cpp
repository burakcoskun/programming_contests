#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,s;
int res, lres, rres;



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;

  for(int l = 0; l < n; ++l)
    for(int r = 0; r < n; ++r) {
      string s1 = s;
      s1[l] = s[r];
      s1[r] = s[l];
      int cur = check(s1);
      if(cur > res) {
        res = cur;
        lres = l;
        rres = r;
      }
    }

  cout << res << endl;
  cout << lres << " " << rres << endl;
  return 0;
}
