#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n;
int u[100005], cnt[100005];

pair<int, int> pq[100005];
int pos[100005], diff;

void swapelem(int a, int b) {

  pos[pq[a].fs] = b;
  pos[pq[b].fs] = a;

  pair<int, int> temp = pq[a];
  pq[a] = pq[b];
  pq[b] = temp;
}

void update(int u) {
  pq[pos[u]].sc++;

  int i = pos[u];
  while (i * 2 <= diff) {
    if (pq[i].sc > pq[i * 2].sc) {
      swapelem(i, i * 2);
      i = i * 2;
    } else if (i * 2 + 1 <= diff && pq[i].sc > pq[i * 2 + 1].sc) {
      swapelem(i, i * 2 + 1);
      i = i * 2 + 1;
    } else
      break;
  }
}

void addpq(int u) {
  int i = diff;
  while (i >= 2) {
    if (pq[i].sc < pq[i / 2].sc) {
      swapelem(i, i / 2);
      i = i / 2;
    } else
      break;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &u[i]);

  if (n <= 3) {
    cout << n << endl;
    return 0;
  }

  int res = 0;
  int maxu = 0;
  int cnt_max = 0;
  for (int i = 0; i < n; ++i) {
    ++cnt[u[i]];
    if (cnt[u[i]] > maxu) {
      maxu = cnt[u[i]];
      cnt_max = 1;
    } else if (cnt[u[i]] == maxu)
      ++cnt_max;

    if (!pos[u[i]]) {
      ++diff;
      pos[u[i]] = diff;
      pq[diff] = mp(u[i], 1);
      addpq(diff);
    } else {
      update(u[i]);
    }

    // cout << maxu << " " << cnt_max << " " << pq[1].sc << endl;

    if (diff == 1 || (maxu == pq[1].sc + 1 && cnt_max == 1))
      res = i + 1;
    else if (diff == 2 && pq[1].sc == 1)
      res = i + 1;
    else if (diff > 2 && pq[1].sc == 1 && maxu == pq[2].sc && maxu == pq[3].sc)
      res = i + 1;
  }
  cout << res << endl;
  return 0;
}
