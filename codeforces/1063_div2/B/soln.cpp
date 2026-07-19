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
    vector<int> p(n);
    string x;
    for(int i = 0; i < n; ++i)
      cin >> p[i];
    cin >> x;

    int minPos, maxPos;
    for(int i = 0; i < n; ++i) {
      if(p[i] == 1)
        minPos = i;
      if(p[i] == n)
        maxPos = i;
    }
    int lPos = min(minPos, maxPos), rPos = max(minPos, maxPos);
    vector<int> s(n,0);
    int pMin = min(p[0], p[lPos]);
    int pMax = max(p[0], p[lPos]);
    for(int i = 1; i < lPos; ++i) {
      if(p[i] > pMin && p[i] < pMax)
        s[i] = 1;
    }
    pMin = min(p[0], p[rPos]);
    pMax = max(p[0], p[rPos]);
    for(int i = 1; i < rPos; ++i) {
      if(p[i] > pMin && p[i] < pMax)
        s[i] = 1;
    }
    pMin = min(p[lPos], p[rPos]);
    pMax = max(p[lPos], p[rPos]);
    for(int i = lPos + 1; i < rPos; ++i)
      if(p[i] > pMin && p[i] < pMax)
        s[i] = 1;
    
    pMin = min(p[rPos], p[n-1]);
    pMax = max(p[rPos], p[n-1]);
    for(int i = rPos +1; i < n; ++i)
      if(p[i] > pMin && p[i] < pMax)
        s[i] = 1;
    pMin = min(p[lPos], p[n-1]);
    pMax = max(p[lPos], p[n-1]);
    for(int i = lPos +1; i < n; ++i)
      if(p[i] > pMin && p[i] < pMax)
        s[i] = 1;
    
    bool ans = true;
    for(int i = 0; i < n; ++i)
      if(x[i] == '1' && s[i] == 0)
        ans = false;
    if(ans == true) {
      ++lPos;
      ++rPos;
      cout << 5 << endl;
      cout << 1 << " " << lPos << endl;
      cout << 1 << " " << rPos << endl;
      cout << lPos << " " << rPos << endl;
      cout << rPos <<  " " << n << endl;
      cout << lPos <<  " " << n << endl;

    }
    else
      cout << -1 << endl;
  }
  return 0;
}
