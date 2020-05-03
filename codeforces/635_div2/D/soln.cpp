#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 1;
const ll inf = 2e9 + 1;
int nr, ng, nb;
vector<int> ar, ag, ab;

ll calc(ll x, ll y, ll z) {
  return abs(x - y) * abs(x - y) + abs(x - z) * abs(x - z) +
         abs(y - z) * abs(y - z);
}

void solve() {
  sort(ar.begin(), ar.end());
  sort(ag.begin(), ag.end());
  sort(ab.begin(), ab.end());

  ll res = inf * inf * 2;
  for (int i = 0; i < ar.size(); ++i) {
    auto lg = upper_bound(ag.begin(), ag.end(), ar[i]);
    auto rg = lower_bound(ag.begin(), ag.end(), ar[i]);
    auto lb = upper_bound(ab.begin(), ab.end(), ar[i]);
    auto rb = lower_bound(ab.begin(), ab.end(), ar[i]);
    if (lg != ag.begin())
      --lg;
    if (lb != ab.begin())
      --lb;

    if (lg != ag.end() && rb != ab.end())
      res = min(res, calc(ar[i], *lg, *rb));
    if (rg != ag.end() && lb != ab.end())
      res = min(res, calc(ar[i], *rg, *lb));
  }
  for (int i = 0; i < ag.size(); ++i) {
    auto lr = upper_bound(ar.begin(), ar.end(), ag[i]);
    auto rr = lower_bound(ar.begin(), ar.end(), ag[i]);
    auto lb = upper_bound(ab.begin(), ab.end(), ag[i]);
    auto rb = lower_bound(ab.begin(), ab.end(), ag[i]);
    if (lr != ar.begin())
      --lr;
    if (lb != ab.begin())
      --lb;

    if (lr != ar.end() && rb != ab.end())
      res = min(res, calc(ag[i], *lr, *rb));
    if (rr != ar.end() && lb != ab.end())
      res = min(res, calc(ag[i], *rr, *lb));
  }
  for (int i = 0; i < ab.size(); ++i) {
    auto lg = upper_bound(ag.begin(), ag.end(), ab[i]);
    auto rg = lower_bound(ag.begin(), ag.end(), ab[i]);
    auto lr = upper_bound(ar.begin(), ar.end(), ab[i]);
    auto rr = lower_bound(ar.begin(), ar.end(), ab[i]);
    if (lr != ar.begin())
      --lr;
    if (lg != ag.begin())
      --lg;

    if (lg != ag.end() && rr != ar.end())
      res = min(res, calc(ab[i], *lg, *rr));
    if (rg != ag.end() && lr != ar.end())
      res = min(res, calc(ab[i], *rg, *lr));
  }

  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> nr >> ng >> nb;

    int a;
    for (int i = 0; i < nr; ++i) {
      cin >> a;
      ar.push_back(a);
    }
    for (int i = 0; i < ng; ++i) {
      cin >> a;
      ag.push_back(a);
    }
    for (int i = 0; i < nb; ++i) {
      cin >> a;
      ab.push_back(a);
    }

    solve();
    ar.clear();
    ab.clear();
    ag.clear();
  }
  return 0;
}
