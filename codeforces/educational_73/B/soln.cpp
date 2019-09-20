#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int res[105][105];
int xy[8][2] = {{2, 1},
                {2, -1},
                {-2, 1},
                {-2, -1},
                {1, 2},
                {
                    1,
                    -2,
                },
                {-1, 2},
                {-1, -2}};

void put(int a, int b, int v) {
  res[a][b] = v;
  for (int i = 0; i < 8; ++i) {
    int x = xy[i][0] + a;
    int y = xy[i][1] + b;
    // cout << a << " " << b << " " << x << " " << y << " " << endl;
    if (x < 0 || y < 0 || x >= n || y >= n)
      continue;
    if (!res[x][y])
      put(x, y, -1 * v);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (res[i][j] == 0)
        put(i, j, -1);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (res[i][j] == -1)
        cout << "W";
      else
        cout << "B";
    }
    cout << endl;
  }
  return 0;
}
