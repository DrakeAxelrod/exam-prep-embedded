#include <pthread.h> // thread lib
#include <stdlib.h> // standard lib for malloc
#include <stdio.h> // for printf and sprintf
#include <string.h> // for strcmp

// function declarations
void *worker(void *);
int isPrime(int);

// mutex init (to lock and unlock threads)
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int completed = 0; // number of completed tasks
int n_args;        // number of provided args

// main function
int main(int argc, char const *argv[])
{
  n_args = argc - 1;         // args -1 accounting for argv[0] being the file name
  char *tasks[n_args];       // init results of tasks
  pthread_t threads[n_args]; // array of threads corresponding to argc-1
  int th_code;               // thread return code

  // loop through and create the threads
  for (int i = 1; i < argc; i++)
  {
    // create thread
    th_code = pthread_create(&threads[i], NULL, worker, (void *)argv[i]);
    if (th_code < 0) // check if error
    {
      // print err and code if unable to make thread
      printf("Error: unable to create thread, %d\n", th_code);
      // exit with error code 1
      exit(1);
    }
  }
  // loop through and join the threads
  for (int i = 1; i < argc; i++)
  {
    void *return_val; // return value holder
    // join thread
    th_code = pthread_join(threads[i], &return_val);
    if (th_code < 0) // check if error
    {
      // print err and code if unable to join thread
      printf("Error: unable to create thread, %d\n", th_code);
      // exit with error code 1
      exit(1);
    }
    char *str = malloc(100);
    sprintf(str, "%d - %s\n", atoi(argv[i]), (char *)return_val);
    tasks[i] = str;
  }
  int i; // declare i
  // loop through and print the results
  for (i = 0; i <= n_args; i++)
  {
    printf("%s", tasks[i]); // print result
  }
  pthread_exit(NULL); // exit main thread
}

// threads job function
void *worker(void *argument)
{
  pthread_mutex_lock(&lock);                   // lock the thread

  char *return_val = malloc(sizeof(argument)); // allocate space for return_value
  char *arg;                                   // char pointer for argument (still void pointer)
  arg = (char *)argument;                      // cast void pointer to char * so we can access arg
  int v = atoi(arg);                           // change string to int
  if (isPrime(v) == 0)                         // if the result of isPrime is 0 its prime
  {
    strcpy(return_val, "Prime"); // put Prime in return_val
  }
  else // if the result of isPrime is 1 its not prime
  {
    strcpy(return_val, "Not Prime"); // put Not Prime in return_val
  }
  completed++; // incremented completed tasks
  printf("%d out of %d numbers checked\n", completed, n_args);
  pthread_mutex_unlock(&lock); // unlock the thread
  pthread_exit(return_val);    // close thread
}

// check whether a num is prime or not
int isPrime(int n)
{
  // return 1 for non-prime number
  if (n == 0)
  {
    return 1; // if the arg was 0 it is not prime
  }
  // for 2 to n/2 check if n modulo i == 0 (basically checking if divisible)
  for (int i = 2; i <= n / 2; ++i)
  {
    // if n is divisible by i, then n is not prime
    if (n % i == 0)
    {
      // return 1 for not prime (was divisible)
      return 1;
    }
  }
  return 0; // passed all criteria it is prime
}
