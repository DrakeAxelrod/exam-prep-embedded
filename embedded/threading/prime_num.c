
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <string.h>

// compile command
// gcc prime_num.c - o prime_num - lpthread

int IsPrime(int n)
{
  // change flag to 1 for non-prime number
  if (n == 0 || n == 1)
    return 1;

  for (int i = 2; i <= n / 2; ++i)
  {
    // if n is divisible by i, then n is not prime
    // change flag to 1 for non-prime number
    if (n % i == 0)
    {
      return 1;
    }
  }
  return 0;
}

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *args)
{
  char *value = (char *)args;
  printf(args);
  int v = atoi(value);
  // sleep(1);
  if (IsPrime(v) == 0)
  {
    printf("%d is prime\n", v);
  }
  else
  {
    printf("%d is not prime\n", v);
  }

  // printf("value: %d\n", v);
  return NULL;
}

int main(int argc, char const *argv[])
{
  // pthread_t thread_id;
  pthread_t threads[argc-1];
  int result_code;

  for (int i = 1; i < argc-1; i++) {
    pthread_create(&threads[i], NULL, myThreadFun, &argv[i]);
    // printf("%s", argv[i]);
  }
  for (int i = 1; i < argc - 1; i++)
  {
    int v = atoi(argv[i]);
    result_code = pthread_join(&threads[i - 1], NULL);
    // printf("%s", argv[i]);
  }
  sleep(1);
  // pthread_join(thread_id, NULL);

  return 0;
}
