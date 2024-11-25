#include <stdio.h>
#include <time.h>

#define R 14000000
#define C 1000
float m[R][C];

int main()
{
  float a = 0.0;

  clock_t s, f;

  printf("%zu, %lf\n", sizeof(m), sizeof(m)/1048576.);

  s = clock();

  // for(int n = 0; n < 100; ++n)
      for(int j = 0; j < C; ++j)
      {
      printf("C = %d\n", j);
    for(int i = 0; i < R; ++i)
      {
        m[i][j] = i + j; // [i][j] takes ... ms, [j][i] takes ... ms
      }
      }

  f = clock();

  printf("%f: %f ms\n", a, ((double)(f - s)) * 1000.0 / CLOCKS_PER_SEC);

  printf("%f\n", m[0][0] + m[R-1][C-1]);

  return 0;
}
