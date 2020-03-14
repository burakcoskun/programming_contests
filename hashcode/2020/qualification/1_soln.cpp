#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int B, L;
int D;
vector<int> books;
vector<int> freqs;

struct library {
  int lib_id;
  long long n;
  long long t;
  long long m;
  vector<int> ids;
  long long sum;
  int cnt;
};
struct result {
  int lib_id;
  vector<int> books;
};

vector<library> libs;

bool compareBooks(const int &id_1, const int &id_2) {
  return (double)books[id_1] / freqs[id_1] > (double)books[id_2] / freqs[id_2];
}

vector<result> single(vector<library> &libs) {
  vector<result> res;
  vector<int> taken(B);

  int current_time = 0;
  for (int i = 0; i < libs.size(); ++i) {
    current_time += libs[i].t;

    result current_lib;
    current_lib.lib_id = libs[i].lib_id;

    long long num_of_books = (long long)(D - current_time) * libs[i].m;
    num_of_books = min(num_of_books, (long long)libs[i].n);

    for (int j = 0; j < num_of_books && j < libs[i].n; ++j) {
      if (taken[libs[i].ids[j]]) {
        num_of_books++;
        continue;
      }
      taken[libs[i].ids[j]] = 1;
      current_lib.books.push_back(libs[i].ids[j]);
    }

    res.push_back(current_lib);
  }
  return res;
}

long long calc_score(vector<result> &res) {
  vector<int> taken(B);
  long long cnt = 0;
  for (int i = 0; i < res.size(); ++i) {
    for (int j = 0; j < res[i].books.size(); ++j) {

      if (!taken[res[i].books[j]])
        cnt += books[res[i].books[j]];
      taken[res[i].books[j]] = 1;
    }
  }
  return cnt;
}

void print_res(vector<result> res) {
  vector<result> final_res;
  for (int i = 0; i < res.size(); ++i)
    if (res[i].books.size() > 0)
      final_res.push_back(res[i]);

  res = final_res;
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i].lib_id << " " << res[i].books.size() << endl;

    for (int j = 0; j < res[i].books.size(); ++j)
      cout << res[i].books[j] << " ";
    cout << endl;
  }
}

void read_input() {
  cin >> B >> L >> D;
  books.resize(B);
  libs.resize(L);
  freqs.resize(B);
  for (int i = 0; i < B; ++i)
    cin >> books[i];

  for (int i = 0; i < L; ++i) {
    cin >> libs[i].n;
    cin >> libs[i].t;
    cin >> libs[i].m;
    libs[i].ids.resize(libs[i].n);
    libs[i].lib_id = i;
    libs[i].sum = 0;
    for (int j = 0; j < libs[i].n; ++j) {
      cin >> libs[i].ids[j];
      libs[i].sum += books[libs[i].ids[j]];
      freqs[libs[i].ids[j]]++;
    }
    /*
    for (int j = 0; j < libs[i].n; ++j)
      cout << libs[i].ids[j] << " ";
    cout << endl;
    */
  }
  for (int i = 0; i < L; ++i) {
    sort(libs[i].ids.begin(), libs[i].ids.end(), compareBooks);
  }
}

bool compareLibs(const library &lib1, const library &lib2) {
  return lib1.t < lib2.t;
}
bool compareLibs2(const library &lib1, const library &lib2) {
  double ran = float(rand() / RAND_MAX);
  double ll1 = (lib1.n * lib1.m / (lib1.t / ran));
  double ll2 = (lib2.n * lib2.m / (lib2.t / ran));
  return ll1 > ll2;
}
bool compareLibs3(const library &lib1, const library &lib2) {
  double ran = float(rand() / RAND_MAX);
  double ll1 = min(lib1.m * D, lib1.n) - lib1.t / ran;
  double ll2 = min(lib2.m * D, lib2.n) - lib2.t / ran;
  return ll1 > ll2;
}
bool compareLibs4(const library &lib1, const library &lib2) {
  return lib1.sum > lib2.sum;
}
bool compareLibs5(const library &lib1, const library &lib2) {
  double ll1 = (lib1.n / lib1.t);
  double ll2 = (lib2.n / lib2.t);
  return ll1 > ll2;
}
bool compareLibs6(const library &lib1, const library &lib2) {
  return lib1.n > lib2.n;
}
bool compareLibs7(const library &lib1, const library &lib2) {
  return lib1.cnt > lib2.cnt;
}

void do_more(vector<library> &best_libs) {
  vector<result> res = single(best_libs);
  long long max_score = calc_score(res);
  vector<result> final_res = res;

  for (int i = 0; i < 100000; ++i) {
    int a = rand() % L;
    int b = rand() % L;
    vector<library> new_libs = best_libs;

    library temp = new_libs[a];
    new_libs[a] = new_libs[b];
    new_libs[b] = temp;

    res = single(libs);

    long long score = calc_score(res);
    if (score > max_score) {
      max_score = score;
      final_res = res;
      best_libs = libs;
    }
  }

  cerr << max_score << endl;
  print_res(final_res);
}

void solve_d() {
  vector<library> d_libs = libs;
  for (int i = 0; i < d_libs.size(); ++i)
    d_libs[i].cnt = d_libs[i].n;
  vector<int> taken(B);
  sort(d_libs.begin(), d_libs.end(), compareLibs7);
  for (int i = 1; i < L; ++i) {
    for (int j = 0; j < d_libs[i - 1].ids.size(); ++j)
      taken[d_libs[i - 1].ids[j]] = 1;
    for (int j = i; j < L; ++j) {
      d_libs[j].cnt = d_libs[j].n;
      for (int k = 0; k < d_libs[j].ids.size(); ++k)
        if (taken[d_libs[j].ids[k]])
          d_libs[j].cnt--;
    }
    sort(d_libs.begin(), d_libs.end(), compareLibs7);
  }

  do_more(d_libs);
  vector<result> res = single(d_libs);
  cerr << "dscore: " << calc_score(res) << endl;
}
void call_single() {
  long long max_score = 0;
  vector<result> final_res;
  vector<library> best_libs;
  for (int i = 0; i < 100000; ++i) {
    random_shuffle(libs.begin(), libs.end());
    if (i == 100)
      sort(libs.begin(), libs.end(), compareLibs);
    if (i == 101)
      sort(libs.begin(), libs.end(), compareLibs2);
    if (i == 102)
      sort(libs.begin(), libs.end(), compareLibs3);
    if (i == 103)
      sort(libs.begin(), libs.end(), compareLibs4);
    if (i == 104)
      sort(libs.begin(), libs.end(), compareLibs5);
    if (i == 105)
      sort(libs.begin(), libs.end(), compareLibs6);
    if (i % 1000 == 0)
      cerr << i << " " << endl;
    vector<result> res = single(libs);

    long long score = calc_score(res);
    if (score > max_score) {
      final_res = res;
      max_score = score;
      best_libs = libs;
    }
  }

  do_more(best_libs);
}

int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  read_input();

  // solve_d();
  call_single();

  return 0;
}
