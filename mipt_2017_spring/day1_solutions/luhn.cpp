#include <cstdio>

int main(void) {
  char buff[20];
  scanf("%s", buff);

  int kartica[20];
  for (int i = 0; i < 16; ++i) {
    kartica[i] = buff[i] - '0';
  }

  for (int i = 0; i < 16; i += 2) {
    kartica[i] = kartica[i] * 2;
  }

  for (int i = 0; i < 16; ++i) {
    if (kartica[i] >= 10) {
      kartica[i] = kartica[i] / 10 + kartica[i] % 10;
    }
  }

  int suma = 0;
  for (int i = 0; i < 16; ++i) {
    suma += kartica[i];
  }

  if (suma % 10 == 0) {
    printf("DA\n");
  } else {
    printf("NE\n");
  }

  return 0;
}
