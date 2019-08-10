#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int T;
vector<int> wa;
vector<int> ha;
int decFirst, decSec;
bool used = false;

int find(vector<int> &v, int mul, int w) {
  int maxS = 0, minS = 0;
  int lastMax = 0, firstMin = 0;
  int psum = 0;
  for (int i = 0; i < v.size(); ++i) {
    psum += v[i] * mul;
    if (maxS <= psum) {
      maxS = psum;
      lastMax = i;
    }
    if (minS > psum) {
      minS = psum;
      firstMin = i;
    }
  }

  if (firstMin > lastMax && !used) {
    if (w == 1)
      decFirst = 1;
    else
      decSec = 1;
  }
  return maxS - minS;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  for (int t = 0; t < T; ++t) {
    string s;
    cin >> s;

    decFirst = 0;
    decSec = 0;
    wa.clear();
    ha.clear();

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'D')
        wa.push_back(1);
      else if (s[i] == 'A')
        wa.push_back(-1);
      else if (s[i] == 'W')
        ha.push_back(1);
      else
        ha.push_back(-1);
    }
    long long wres = min(find(wa, 1, 1), find(wa, -1, 1)) + 1;
    long long hres = min(find(ha, 1, 0), find(ha, -1, 0)) + 1;
    if (decFirst && decSec) {
      if (wres < hres)
        --wres;
      else
        --hres;
    } else if (decFirst)
      --wres;
    else if (decSec)
      --hres;
    cout << wres * hres << endl;
  }
  return 0;
}
