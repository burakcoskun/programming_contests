#include <cstdint>
#include <cstdio>
#include <set>
#include <string>

const int MAXC = 2000010;

inline bool isWordChar(char c) {
  return (c >= '0' && c <= '9')
    || (c >= 'A' && c <= 'Z')
    || (c >= 'a' && c <= 'z');
}

inline bool isWordEndChar(char c) {
  return c == ' '
    || c == '.'
    || c == '-'
    || c == ','
    || c == ';'
    || c == '?'
    || c == '!'
    || c == '\n';
}

int n, m;
std::set<std::string> nicknames;
std::set<std::string> messages;
char buff[MAXC];
char message[MAXC];

int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf(" %s", buff);
    nicknames.insert(buff);
  }

  fgets(buff, sizeof(buff), stdin);
  for (int i = 0; i < m; ++i) {
    fgets(buff, sizeof(buff), stdin);

    int k = 0, word_start = 0;
    bool in_word = false;

    for (int j = 0; buff[j] != 0; ++j) {
      if (isWordChar(buff[j])) {
        if (!in_word) {
          in_word = true;
          word_start = j;
        }
      } else {
        if (in_word) {
          if (nicknames.count(std::string(buff + word_start, buff + j)) == 0) {
            for (int l = word_start; l < j; ++l) {
              message[k++] = buff[l];
            }
          }
        }
        in_word = false;
        if (k == 0 && buff[j] == ' ') {
          continue;
        }
        if (k != 0 && buff[j] == ' ' && message[k-1] == ' ') {
          continue;
        }
        message[k++] = buff[j];
      }
    }
    if (k > 0) --k;
    while (k > 0 && message[k-1] == ' ') --k;
    message[k] = 0;

    if (messages.count(message)) {
      printf("BRISI\n");
    } else {
      printf("OSTAVI\n");
    }
    messages.insert(message);
  }

  return 0;
}
