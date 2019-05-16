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

int a[] = {4, 8, 15, 16, 23, 42};
set<int> kalan(a, a + 6), two, three;
int c[6][6];
int res[10];

int main() {
  int ans;
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      c[i][j] = a[i] * a[j];
    }
  }

  cout << "? 1 2" << endl;
  fflush(stdout);
  cin >> ans;
  for (int i = 0; i < 6; ++i)
    for (int j = i + 1; j < 6; ++j)
      if (c[i][j] == ans) {
        two.insert(a[i]);
        two.insert(a[j]);
        kalan.erase(a[i]);
        kalan.erase(a[j]);
      }
  cout << "? 6 6" << endl;
  fflush(stdout);
  cin >> ans;
  for (int i = 0; i < 6; ++i)
    if (a[i] * a[i] == ans) {
      kalan.erase(a[i]);
      res[6] = a[i];
      break;
    }

  cout << "? 2 3" << endl;
  fflush(stdout);
  cin >> ans;

  for (int i = 0; i < 6; ++i)
    for (int j = i + 1; j < 6; ++j)
      if (c[i][j] == ans) {
        if (two.find(a[i]) != two.end()) {
          res[2] = a[i];
          // cout << a[i] << " " << a[j] << endl;
          res[3] = a[j];
          kalan.erase(a[j]);
          two.erase(a[i]);
          res[1] = *two.begin();
        } else {
          res[3] = a[i];
          res[2] = a[j];
          kalan.erase(a[i]);
          two.erase(a[j]);
          res[1] = *two.begin();
        }
      }

  cout << "? 4 4" << endl;
  fflush(stdout);
  cin >> ans;
  for (int i = 0; i < 6; ++i)
    if (a[i] * a[i] == ans) {
      kalan.erase(a[i]);
      res[4] = a[i];
      res[5] = *kalan.begin();
      break;
    }

  cout << "! ";
  for (int i = 1; i <= 6; ++i)
    cout << res[i] << " ";
  cout << endl;
  fflush(stdout);
  return 0;
}
