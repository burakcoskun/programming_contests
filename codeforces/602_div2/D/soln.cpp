#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> res(400005), b(400005);

struct aaaa {
  int num, pos;
} a[400005];
bool comp2(aaaa lhs, aaaa rhs) {
  if (lhs.num != rhs.num)
    return lhs.num > rhs.num;
  return lhs.pos < rhs.pos;
}

struct query {
  int k, pos, p;
} q[400005];

struct aaa {
  int num, lcnt;
} bst[400005];

bool comp(query lhs, query rhs) {
  return lhs.k < rhs.k;
}

void add(int node, int num) {
  // cout << node << " " << num << endl;
  if (bst[node].num == 0) {
    bst[node].num = num;
    bst[node].lcnt = 1;
    return;
  }
  if (bst[node].num > num) {
    bst[node].lcnt++;
    add(node * 2, num);
  } else
    add(node * 2 + 1, num);
}

int get(int node, int t) {
  if (t == bst[node].lcnt)
    return bst[node].num;
  else if (t < bst[node].lcnt)
    return get(node * 2, t);
  else
    return get(node * 2 + 1, t - bst[node].lcnt);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].num;
    a[i].pos = i;
    b[i] = a[i].num;
  }
  sort(a, a + n, comp2);

  cin >> m;
  for (int t = 0; t < m; ++t) {
    cin >> q[t].k >> q[t].pos;
    q[t].p = t;
  }

  sort(q, q + m, comp);
  int last = 0;
  for (int j = 0; j < m; ++j) {
    while (last < q[j].k) {
      add(1, a[last].pos);
      ++last;
    }
    // cout << 4 << endl;
    // cout << "get" << get(1, 1) << " " << q[j].p << " " << b[1] << endl;
    res[q[j].p] = get(1, q[j].pos);
    // cout << "res0" << res[0] << endl;
    // cout << get(1, q[j].pos);

    // cout << 5 << endl;
  }

  for (int i = 0; i < m; ++i)
    cout << b[res[i]] << endl;
  return 0;
}
