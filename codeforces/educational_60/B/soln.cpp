#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n, m, k;
vector<int> a;
long long res;

void read_input() {
  scanf(" %d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    int ai;
    scanf(" %d", &ai);
    a.pb(ai);
  }
  sort(a.begin(), a.end(), greater<int>());
  res = ((long long)a[0] * k + a[1]) * (m / (k + 1));
  res += ((long long)m % (k + 1)) * a[0];
  cout << res << endl;
}

int main() {
  read_input();
  return 0;
}
