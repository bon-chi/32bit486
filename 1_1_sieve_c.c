#include <stdio.h>
#include <stdlib.h>

#define NUM 10000

int main(int argc, char *argv[])
{
  unsigned char *tbl;
  unsigned int m, i, snum;
  void sieve(unsigned char *tbl, unsigned int num);
  int isprime(unsigned char *tbl, unsigned int num);

  if (argc > 1)
    m = atol(argv[1]);
  else 
    m = NUM;
        
  tbl = (unsigned char *) malloc(sizeof(char) * (m + 1));
  if (tbl == NULL) {
    fprintf(stderr, "Can't alloc memory\n");
    exit(1);
  }

  sieve(tbl, m);

  snum = 0;
  for (i = 2; i <= m; i++) {
    if (isprime(tbl, i)) {
      snum++;
      printf("%u ", i);
    }
  }
  putchar('\n');
  printf("%u prime numbers in 2..%u\n", snum, m);

  return 0;
}

void sieve(unsigned char *tbl, unsigned int num)
{
  unsigned long i, j;
  for (i = 0; i <= num; i++)
    tbl[i] = 1;

  for (i = 2; i <= num / 2 ; i++) {
    if (tbl[i] == 1) {
      for (j = i + i; j <= num; j += i)
        tbl[j] = 0;
    }
  }
}

int isprime(unsigned char *tbl, unsigned int num)
{
  return tbl[num];
}
