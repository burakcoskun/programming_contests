#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int T;
int n;

void print_res(int i) {
  for (int j = 0; j < i; ++j) {
    cout << "1";
  }
  cout << "33";
  for (int j = 0; j < n / i; ++j) {
    cout << "7";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n;
    if (n == 1) {
      cout << "1337\n";
      continue;
    }

    int x = 2;
    while (x * (x - 1) / 2 < n)
      ++x;
    if (x * (x - 1) / 2 != n)
      --x;
    cout << "133";
    int rem = n - x * (x - 1) / 2;
    for (int i = 0; i < rem; ++i)
      cout << "7";
    for (int i = 2; i < x; ++i)
      cout << "3";
    cout << "7" << endl;
  }
  return 0;
}
