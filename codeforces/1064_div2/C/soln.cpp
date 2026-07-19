#include <bits/stdc++.h>

using namespace std;

struct node{
  int a;
  struct node *next, *prev;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<node*>> link;
    for(int i = 0; i < n; ++i)
      cin >> a[i];
    
    node *start = new node;
    (*start).a = a[0];
    node *pos = start;
    link[a[0]].push_back(start);
    for(int i = 1; i < n; ++i) {
      node *current = new node;
      (*current).a = a[i];
      (*current).prev = pos;
      (*pos).next = current;
      pos = current;
      link[a[i]].push_back(current);
    }
    (*start).prev = pos;
    (*pos).next = start;

    sort(a.begin(), a.end());
    long long res = 0;
    for(int i = 0 ; i < n - 1; ++i) {
      node* current = link[a[i]][link[a[i]].size()-1];
      if((*(current->prev)).a < (*(current->next)).a)
        res += (*(current->prev)).a;
      else
        res += (*(current->next)).a;
      current->prev->next = current -> next;
      current->next->prev = current -> prev;
      // cout << res << endl;
      link[a[i]].pop_back();
    }
    cout << res << endl;
  }
  return 0;
}
