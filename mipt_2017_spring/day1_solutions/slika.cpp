#include <cstdio>

const int kMod = 10007;
const int kIntensityLimit = 256;

int main(void) {
  int r, s; scanf("%d%d", &r, &s);
  static int slika[1000][1010];
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < s; ++j) {
      scanf("%d", &slika[i][j]);
    }
  }

  static int num_ways_to_reach_sum[3 * kIntensityLimit];
  for (int i = 0; i < kIntensityLimit; ++i) {
    for (int j = 0; j < kIntensityLimit; ++j) {
      for (int k = 0; k < kIntensityLimit; ++k) {
        int& num_ways = num_ways_to_reach_sum[i + j + k];
        num_ways += 1;
        if (num_ways >= kMod) {
          num_ways -= kMod;
        }
      }
    }
  }

  long long num_color_images = 1;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < s; ++j) {
      int num_ways_to_reach_average = 0;
      for (int mod = 0; mod < 3; ++mod) {
        int suma = slika[i][j] * 3 + mod;
        if (suma < 3 * kIntensityLimit) {
          num_ways_to_reach_average += num_ways_to_reach_sum[suma];
          if (num_ways_to_reach_average >= kMod) {
            num_ways_to_reach_average -= kMod;
          }
        }
      }
      num_color_images *= num_ways_to_reach_average;
      num_color_images %= kMod;
    }
  }

  printf("%lld\n", num_color_images);

  return 0;
}
