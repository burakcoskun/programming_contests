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

int p1[2], p2[2] string s;

int wind[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int a[100005][2];

int dist(int a, int dim) { return abs(p2[dim] - a); }

long long solve(int dim) {
  long long pos = p1[dim];

  for (int i = 0; i < s.size(); ++i) {

    if (dist(pos, dim) == 0)
      return i;

    if (s[i] == 'U')
      w = 0;
    else if (s[i] == 'D')
      w = 1;
    else if (s[i] == 'L')
      w = 2;
    else
      w = 3;

    long long int minpos = pos;
    for (int j = 0; j < 4; ++j) {
      long long int npos = pos + wind[w][dim] + wind[j][dim];
      if (dist(npos, dim) < dist(minpos, dim)) {
        minpos = npos;
      }
    }

    pos = minpos;
  }

  if (dist(pos, dim) >= dist(p1[dim], dim))
    return -1;
}

void read_input() {
  scanf(" %d %d %d %d", &p1[0], &p1[1], &p2[0], &p2[1]);
  cin >> s;
  long long res1 = solve(0);
  long long res2 = solve(1);
}

int main() {
  read_input();
  return 0;
}
