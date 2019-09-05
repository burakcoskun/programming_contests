#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

ll n, k;

ll solve(ll a, ll b) {
  if (a < b)
    return a;
  if (a % b == 0)
    return solve(a / b, b) + 1;
  return solve(a - (a % b), b) + a % b;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    scanf("%lld%lld", &n, &k);
    printf("%lld\n", solve(n, k));
  }
  return 0;
}
