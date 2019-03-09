#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n, cnt;

int find_max(int left, int right) {
  while (left < right) {
    int mid = (left + right) / 2;
    ++cnt;
    printf("> %d\n", mid);
    fflush(stdout);
    int r;
    scanf("%d", &r);
    if (r)
      left = mid + 1;
    else
      right = mid;
  }
  return right;
}

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void read_input() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  scanf(" %d", &n);
  int max_elem = find_max(0, 1e9);

  vector<int> perm(n);
  for (int i = 0; i < n; ++i)
    perm[i] = i + 1;

  shuffle(perm.begin(), perm.end(), rng);

  for (int i = 0; i < n - 1 && i < cnt; ++i) {
    printf("? %d\n", perm[i]);
    scanf(" %d", &perm[i]);
  }
  perm[min(cnt, n - 1)] = max_elem;

  sort(perm.begin(), perm.end(), greater<int>());
  int all_gcd = perm[0] - perm[1];
  for (int i = 0; i < cnt && i < n - 1; ++i) {
    all_gcd = gcd(all_gcd, perm[i] - perm[i + 1]);
  }
  printf("! %d %d\n", max_elem - all_gcd * (n - 1), all_gcd);
}

int main() {
  read_input();
  return 0;
}
