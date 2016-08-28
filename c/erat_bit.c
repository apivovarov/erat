#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void setBitToFalse(unsigned long * b, int pos) {
  unsigned long mask = ~(1L << pos);
  *b &= mask;
}

bool boolVal(unsigned long * b, int pos) {
  unsigned long mask = 1L << pos;
  return (*b & mask) != 0;
}

void getPos(long n, long * idx, int * pos) {
  *idx = n / 64;
  *pos = (int)(n % 64);
}

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

  // size of int array
  long erat_size = (max + 63) / 64 * 8;
  long max2 = erat_size * 8;
  // printf("erat_size: %ld\n", erat_size);
  // printf("max2: %ld\n", max2);
  unsigned long* erat = malloc(erat_size);

  memset(erat, 0xFF, erat_size);

  setBitToFalse(erat, 0);
  setBitToFalse(erat, 1);

  long lim = (long) sqrt(max2);

  long n, j;
  long idx = 0;
  int pos = 0;
  long* pIdx = &idx;
  int* pPos = &pos;

  for (n = 2; n < lim; n++) {
    getPos(n, pIdx, pPos);
    if (boolVal(erat + idx, pos)) {
      for (j = 2 * n; j < max2; j += n) {
        getPos(j, pIdx, pPos);
        setBitToFalse(erat + idx, pos);
      }
    }
  }

  unsigned long long t2 = timenow();
  unsigned long long tt = t2 - t1;

  printf("%llu ms\n", tt);

  // for(j = 0; j < 76; j++) {
  //   getPos(j, pIdx, pPos);
  //   bool r = boolVal(erat + idx, pos);
  //   if (r) {
  //     printf("%ld %s %ld %d\n", j, r ? "T" : "F", idx, pos);
  //   }
  // }

  return 0;
}
