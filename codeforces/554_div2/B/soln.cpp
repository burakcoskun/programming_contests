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

int x;
int b[50], ops[50], res, ocnt;

void convert(int k, int *ar) {
  int cnt = 0;
  while (k) {
    ar[++cnt] = k % 2;
    k /= 2;
  }
  ar[0] = cnt;
}

int check1(int *ar) {
  for (int i = 1; i <= ar[0]; ++i)
    if (!ar[i])
      return 0;
  return 1;
}

int num_zeros(int *ar) {
  for (int i = 1; i <= ar[0]; ++i)
    if (ar[i])
      return i - 1;
  return 0;
}

void read_input() {
  int cnt = 1;
  cin >> x;
  convert(x, b);
  while (!check1(b)) {
    if (cnt % 2) {
      int zeros = num_zeros(b);
      int pow = 1;
      for (int k = 0; k < zeros; ++k)
        pow *= 2;
      x ^= (pow - 1);
      ops[res++] = zeros;
    } else
      x = x + 1;
    ocnt++;

    ++cnt;
    convert(x, b);
  }

  cout << ocnt << endl;
  for (int i = 0; i < res; ++i)
    cout << ops[i] << " ";
  if (ocnt)
    cout << endl;
}

int main() {
  read_input();
  return 0;
}
