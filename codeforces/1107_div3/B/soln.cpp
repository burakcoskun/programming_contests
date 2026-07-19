#include <bits/stdc++.h>

using namespace std;

bool is_good(long long k) {
  vector<int> digits(10);
  while(k) {
    digits[k%10]++;
    k/=10;
  }
  int cnt = 0;
  for(int i = 0; i < 10; ++i)
    if(digits[i])
      ++cnt;
  if(cnt <= 2)
    return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  vector<vector<long long>> all_good;
  vector<long long> good_1;
  for(int i = 1; i < 10; ++i)
    good_1.push_back(i);
  all_good.push_back(good_1);
  int d = 0;
  while(d < all_good.size()) {
    vector<long long> good_c;
    for(int i = 0; i < all_good[d].size(); ++i) {
      for(int j = 0; j < 10; ++j) {
        long long current = all_good[d][i] * 10 + j;
        if(current <= 1e9 && is_good(current)) {
          good_c.push_back(current);
          cout << current << endl;
        }
      }
    }
    if(good_c.size() > 0)
      all_good.push_back(good_c);
    ++d;
  }
  set<long long> goods;
  for(int i = 0; i < all_good.size(); ++i)
    for(int j = 0; j < all_good[i].size(); ++j)
      goods.insert(all_good[i][j]);

  while(t--) {
    int x;
    cin >> x;
    long long res = 0;
    for(auto y: goods)
      if(y >1 && y <= x && is_good(y*x)) {
        res = y;
        break;
      }
    cout << res << endl;
  }
  return 0;
}
