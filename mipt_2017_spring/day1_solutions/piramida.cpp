#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct Query {
  int redak;
  int stupac;
  int duljina;
  int redni_broj;
};

vector<vector<int>> IzgradiPiramidu(int n, int v, int a, 
                                    int b, int c, int mod) {
  //  printf("%d %d %d %d\n", a, b, c, mod);

  vector<vector<int>> piramida(n);
  piramida[0].push_back(v);
  assert(n == piramida.size());
  for (int i = 1; i < n; ++i) {
    piramida[i].resize(i + 1);
    piramida[i][0] = ((long long)c * piramida[i-1][0])% mod;
    for (int j = 1; j < piramida[i].size(); ++j) {
      piramida[i][j] = ((long long)a * piramida[i][j-1] + 
                        (long long)b * piramida[i-1][j-1]) % mod;
    }
    assert(i + 1 == piramida[i].size());
  }
  return piramida;
}

void RijesiUpite(const vector<vector<int>>& piramida,
                 vector<Query> upiti,
                 vector<int>* rjesenja_upita) {
  sort(upiti.begin(), upiti.end(),
       [] (const Query& a, const Query& b) {
         return a.duljina < b.duljina;
       });
  
  const int n = piramida.size();
  const int broj_upita = upiti.size();
  rjesenja_upita->resize(broj_upita);

  vector<vector<int>> trokut = piramida;
  int d = 1;

  for (const auto& upit : upiti) {
    while (d * 2 < upit.duljina) {
      int nd = d * 2;
      auto ntrokut = trokut;
      for (int r = 0; r <= n-nd; ++r) {
        for (int s = 0; s <= r; ++s) {
          int& maksimum = ntrokut[r][s];
          maksimum = trokut[r][s];
          maksimum = std::max(maksimum, trokut[r+d/2][s]);
          maksimum = std::max(maksimum, trokut[r+d/2][s+d/2]);
          maksimum = std::max(maksimum, trokut[r+d][s]);
          maksimum = std::max(maksimum, trokut[r+d][s+d/2]);
          maksimum = std::max(maksimum, trokut[r+d][s+d]);
        }
      }

      trokut = ntrokut;
      d = nd;
    }
    assert(d <= upit.duljina);
    assert(2*d >= upit.duljina);

    const int r = upit.redak;
    const int s = upit.stupac;
    const int pd = upit.duljina;  // piramidna duljina
    int& maksimum = (*rjesenja_upita)[upit.redni_broj];
    maksimum = trokut[r][s];
    if (d / 2 + d <= pd) {
      maksimum = std::max(maksimum, trokut[r+d/2][s]);
      maksimum = std::max(maksimum, trokut[r+d/2][s+d/2]);
    }
    maksimum = std::max(maksimum, trokut[r+pd-d][s]);
    maksimum = std::max(maksimum, trokut[r+pd-d][s+(pd-d)/2]);
    maksimum = std::max(maksimum, trokut[r+pd-d][s+pd-d]);
  }
}

int main(void) {
  int n, v, a, b, c, mod;
  scanf("%d%d%d%d%d%d", &n, &v, &a, &b, &c, &mod);
  int q; scanf("%d", &q);
  vector<Query> upiti;
  for (int i = 0; i < q; ++i) {
    Query upit;
    upit.redni_broj = i;
    scanf("%d%d%d", &upit.redak, &upit.stupac, &upit.duljina);
    --upit.redak; --upit.stupac;
    upiti.emplace_back(upit);
  }

  auto piramida = IzgradiPiramidu(n, v, a, b, c, mod);
  // for (int i = 0; i < piramida.size(); ++i) {
  //   for (int j = 0; j < piramida[i].size(); ++j) {
  //     fprintf(stderr, "%d ", piramida[i][j]);
  //   }
  //   fprintf(stderr, "\n");
  // }
  vector<int> rjesenja_upita;
  RijesiUpite(piramida, std::move(upiti), &rjesenja_upita);
  for (int x : rjesenja_upita) {
    printf("%d\n", x);
  }
  return 0;
}
