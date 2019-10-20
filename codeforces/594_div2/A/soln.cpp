#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
ll n,m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for(int t = 0; t < T; ++t) {
    ll cnt1 = 0;
    ll cnt2 = 0;

    cin >> n;
    for(int i = 0; i < n; ++i) {
      int p;
      cin >> p;
      if(p %2)
        ++cnt1;
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
      int p;
      cin >> p;
      if(p %2)
        ++cnt2;
    }

    cout << cnt1*cnt2 + (n-cnt1)*(m-cnt2)<< endl;

  }
  return 0;
}
