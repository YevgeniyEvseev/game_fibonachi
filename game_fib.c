#include <stdio.h>
#include <stdlib.h>

#define NMAX 80
#define COUNT_ARR 8

unsigned long long fib(unsigned n){
  unsigned long long first = 0ull, second = 1ull, tmp;
  int idx=2;
  if (n == 0) return 0;
  if (n == 1) return 1;
  for (; idx < n; idx++) {
    tmp = second;
    second+=first;
    first = tmp;
  }
  return second;
}

void array_fib_from_num(unsigned long long *res, unsigned long long* fib, unsigned n){
  unsigned long long sum = 0;
  int i = 0, j=0;
  for (i; fib[i] <= n;i++) {
    if (i >= NMAX) abort();
  }
  i -= 1;
  res[j++] = fib[i--];
  sum = res[0];
  for (i; i > 0; --i) {
    unsigned long long tmp=sum+fib[i];
    if(tmp<=n) {
      if (j >= COUNT_ARR) abort();
      res[j++] = fib[i];
      sum = tmp;
    }
  }
}

unsigned min_array(unsigned long long *array,int begin_i, int end_i){
  unsigned res;
  int centr = (end_i + begin_i) / 2;
  if (begin_i == centr) return array[begin_i];
  if (array[centr] > 0)
    min_array(array, centr, end_i);
  else
    min_array(array, begin_i, centr);
}

void printf_arr(unsigned long long *res){
    for (int i = 0; i < COUNT_ARR && res[i] > 0; i++){ 
    printf("%lld ", res[i]); 
  }
}

unsigned get_num_fib(unsigned long long *fib_n, unsigned n){
 unsigned long long res[COUNT_ARR] = {0};
 array_fib_from_num(res, fib_n, n);
 printf_arr(res);
 return min_array(res, 0, COUNT_ARR);
}

unsigned init_game() {
  unsigned n;
  int res;
  printf("Enter number from 3 to 1000");
  res = scanf("%u", &n);
  if(res!=1){
    printf("Wrong input");
    abort();
  }
  return n;
}

void set_array_fib(unsigned long long *fib_n, unsigned n){
  for (int i = 0; fib_n[i] < n; i++) {
    if (i > NMAX) abort();
    fib_n[i] = fib(i);
  }
}

int main() { 
  unsigned long long fib_n[NMAX] = {0};
 
  unsigned n=init_game();
  set_array_fib(fib_n, n);

  unsigned m = get_num_fib(fib_n, n);
  printf("\n%u", m);

  
  return 0;
}