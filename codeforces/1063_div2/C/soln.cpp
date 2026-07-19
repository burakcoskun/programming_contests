#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<vector<int>> g(2,vector<int>(n));
    for(int i = 0; i < n; ++i)
      cin >> g[0][i];
    for(int i = 0; i < n; ++i)
      cin >> g[1][i];
    
    vector<vector<pair<int,int>>> pos(2*n+1);
    for(int i = 0; i < 2; ++i)
      for(int j = 0; j < n; ++j)
        pos[g[i][j]].push_back(make_pair(i,j));
    
    vector<set<int>> blocked(2,set<int>());
    blocked[0].insert(n+1);
    blocked[1].insert(-1);
    for(int i = 0; i < n; ++i) {
      blocked[0].insert(i);
      blocked[1].insert(i);
    }
    auto add = [&](int x) {
      for(int i = 0; i < pos[x].size(); ++i) {
        if(pos[x][i].first == 0)
          blocked[0].erase(pos[x][i].second);
        else
          blocked[1].erase(pos[x][i].second);
      }
    };
    auto del = [&](int x) {
      for(int i = 0; i < pos[x].size(); ++i) {
        if(pos[x][i].first == 0)
          blocked[0].insert(pos[x][i].second);
        else
          blocked[1].insert(pos[x][i].second);
      }
    };
    auto check = [&]() {
      int last1Up = *blocked[0].begin() - 1;
      int first1Down = *blocked[1].rbegin() + 1;
      if(blocked[0].find(0) != blocked[0].end() || blocked[1].find(n-1) != blocked[1].end())
        return false;
      return last1Up >= first1Down;
    };
    add(1);
    int r = 1;
    long long res = 0;
    for(int l = 1; l <= 2*n; ++l) {
      if(r<l)
         r = l;
      while(r < 2*n && !check()) {
        ++r;
        add(r);
      }
      if(check()) {
        // cout << l << " " << r << endl;
        res += 2*n-(r-1);
      }
      del(l);
    }
    cout << res << endl;
  }
  return 0;
}
