#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n;
int p[300005], pos[300005];
vector<pair<int, int>> res;

void swap(int a, int b) {
  res.pb(mp(a + 1, b + 1));
  int tmp = p[a];
  p[a] = p[b];
  p[b] = tmp;

  pos[p[a]] = a;
  pos[p[b]] = b;
}

void solve(int k) {
  if ((pos[k] - k) * 2 >= n) {
    swap(k, pos[k]);
  }

  else if ((n - 1 - pos[k]) * 2 >= n) {
    swap(n - 1, pos[k]);
    swap(k, n - 1);
  }

  else {
    int tmp = pos[k];
    swap(0, pos[k]);
    if (k * 2 >= n) {
      swap(0, k);
      swap(0, tmp);
      return;
    }

    swap(0, n - 1);
    swap(k, n - 1);
    swap(tmp, 0);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p + i);
    p[i]--;
    pos[p[i]] = i;
  }

  for (int i = 0; i < n; ++i) {
    if (p[i] != i) {
      solve(i);
    }
    /*
    for (int j = 0; j < n; ++j)
      cout << p[j] << " ";
    cout << endl;*/
  }

  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); ++i)
    printf("%d %d\n", res[i].fs, res[i].sc);
  return 0;
}
