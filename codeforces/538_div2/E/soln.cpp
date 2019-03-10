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
vector<int> ar;

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
  mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
  scanf(" %d", &n);
  int max_elem = find_max(0, 1e9);
  int ar_size = min(n, 60 - cnt);
  vector<int> ar(ar_size);
  for (int i = 0; i < ar.size(); ++i) {
    ar[i] = i + 1;
  }
  shuffle(ar.begin(), ar.end(), rng32);

  for (int i = 0; i < ar_size; ++i) {
    printf("? %d\n", ar[i]);
    fflush(stdout);
    int tmp;
    scanf(" %d", &tmp);
    ar[i] = tmp;
  }

  sort(ar.begin(), ar.end());
  if (ar[ar_size - 1] != max_elem)
    ar.pb(max_elem);
  int all_gcd = 0;
  for (int i = 1; i < ar.size(); ++i)
    for (int j = 0; j < i; ++j) {
      all_gcd = gcd(ar[i] - ar[j], all_gcd);
    }

  printf("! %d %d\n", max_elem - all_gcd * (n - 1), all_gcd);
  fflush(stdout);
}

int main() {
  read_input();
  return 0;
}
