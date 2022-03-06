#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *worker(void *);
int isPrime(int);

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int completed = 0;
int n_args;

int main(int argc, char const *argv[])
{
  n_args = argc - 1;
  char *tasks[n_args];
  pthread_t threads[n_args];
  int th_code;

  for (int i = 1; i < argc; i++)
  {
    th_code = pthread_create(&threads[i], NULL, worker, (void *)argv[i]);
    if (th_code)
    {
      printf("Error: unable to create thread, %d\n", th_code);
      exit(1);
    }
  }

  for (int i = 1; i < argc; i++)
  {
    void *return_val;
    th_code = pthread_join(threads[i], &return_val);
    if (th_code)
    {
      printf("Error: unable to create thread, %d\n", th_code);
      exit(1);
    }
    char *str = malloc(1024);
    sprintf(str, "%d - %s\n", atoi(argv[i]), (char *)return_val);
    tasks[i] = str;
  }

  for (int i = 0; i <= n_args; i++) {
    printf("%s", tasks[i]);
  }

    pthread_exit(NULL);
}

void *worker(void *argument)
{
  pthread_mutex_lock(&lock);
  char *return_val = malloc(sizeof(argument));
  char *arg;
  arg = (char *)argument; // cast void pointer to char * so we can access arg
  int v = atoi(arg); // change string to int
  if (isPrime(v) == 0) // if the result of isPrime is 0 its prime
  {
    strcpy(return_val, "Prime");
    // printf("%d: prime\n", v); // print its prime
  }
  else // if the result of isPrime is 1 its not prime
  {
    strcpy(return_val, "Not Prime");
    // printf("%d: not prime\n", v); // print its not prime
  }
  //strcpy(return_val, "This is a test");
  // pthread_exit(NULL); // close thread
  completed++;
  printf("%d out of %d numbers checked\n", completed, n_args);
  pthread_mutex_unlock(&lock);
  pthread_exit(return_val); // close thread
}

int isPrime(int n)
{
  // return 1 for non-prime number
  if (n == 0)
  {
    return 1;
  }

  for (int i = 2; i <= n / 2; ++i)
  {
    // if n is divisible by i, then n is not prime
    if (n % i == 0)
    {
      return 1;
    }
  }
  return 0;
}
