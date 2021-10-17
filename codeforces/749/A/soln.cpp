#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int prime[20000];
int n;

bool isPrime(int k) {
  for (int i = 2; i * i <= k; ++i)
    if (k % i == 0)
      return false;
  return true;
}

void getPrimes() {
  int up = 20000;

  for (int i = 2; i < up; ++i)
    prime[i] = isPrime(i);
}

void result(vector<int> &exclude) {
  vector<int> res;
  for (int i = 0; i < n; ++i)
    if (!exclude[i])
      res.push_back(i + 1);
  cout << res.size() << "\n";
  for (int i = 0; i < res.size(); ++i)
    cout << res[i] << " ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  getPrimes();
  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }

    vector<int> res(n);
    bool found = false;
    if (prime[sum] == false) {
      result(res);
      found = true;
    }

    for (int i = 0; i < n && !found; ++i)
      if (prime[sum - a[i]] == false) {
        found = true;
        res[i] = 1;
        result(res);
        break;
      }
    for (int i = 0; i < n && !found; ++i)
      for (int j = i + 1; j < n && !found; ++j)
        if (prime[sum - a[i] - a[j]] == false) {
          found = true;
          res[i] = 1;
          res[j] = 1;
          result(res);
          break;
        }
    for (int i = 0; i < n && !found; ++i)
      for (int j = i + 1; j < n && !found; ++j)
        for (int k = j + 1; k < n && !found; ++k)
          if (!found && prime[sum - a[i] - a[j] - a[k]] == false) {
            found = true;
            res[i] = 1;
            res[j] = 1;
            res[k] = 1;
            result(res);
            break;
          }
  }
  return 0;
}
