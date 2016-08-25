#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

unsigned long long timenow(void) {
  struct timeval tv;
  gettimeofday(&tv, NULL);

  unsigned long long millisecondsSinceEpoch =
      (unsigned long long)(tv.tv_sec) * 1000 +
      (unsigned long long)(tv.tv_usec) / 1000;

  return millisecondsSinceEpoch;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Size of array is not provided\n");
    exit(-1);
  }
  char* arg1 = argv[1];

  char *end = "";
  long max = 0;
  long tmp = strtol(arg1, &end, 10);
  if (end[0] == '\0') max = tmp;
  else printf("Parse err\n");

  printf("Max: %ld\n", max);
  if (max == 0 ) {
    printf("Size of array is 0");
    exit(-1);
  }

  unsigned long long t1 = timenow();

  long erat_size = sizeof(bool) * max;
  bool* erat = malloc(erat_size);

  memset(erat, 1, erat_size);

  erat[0] = false;
  erat[1] = false;

  long lim = (long) sqrt(max);

  long n, j;
  for (n = 2; n < lim; n++) {
    if (erat[n]) {
      for (j = 2 * n; j < max; j += n)
        erat[j] = false;
    }
  }

  unsigned long long t2 = timenow();
  unsigned long long tt = t2 - t1;

  printf("%llu ms\n", tt);

  // for(j = 0; j < 24; j++) {
  //   printf("%s, ", erat[j] ? "true" : "false");
  // }
  // printf("\n");

  return 0;
}
