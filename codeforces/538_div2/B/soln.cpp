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
long long res;
vector<int> a, b;
map<int, int> biggest;

void read_input() {
  scanf(" %d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    int tmp;
    scanf(" %d", &tmp);
    a.pb(tmp);
    b.pb(tmp);
  }

  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; i < m * k; ++i) {
    res += a[i];
    biggest[a[i]]++;
  }
  cout << res << "\n";
  int cnt = 0, cnt2 = 0;
  for (int i = 0; i < n; ++i) {
    if (biggest[b[i]] > 0) {
      biggest[b[i]]--;
      ++cnt;
    }
    if (cnt == m) {
      printf("%d ", i + 1);
      cnt = 0;
      ++cnt2;
    }
    if (cnt2 == k - 1)
      break;
  }
  printf("\n");
}

int main() {
  read_input();
  return 0;
}
