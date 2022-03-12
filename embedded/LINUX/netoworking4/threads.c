#include <stdio.h>
#include <pthread.h>

// This is the function the thread will run. It can be called anything.
//
// arg is the argument pointer passed to `thrd_create()`.
//
// The parent thread will get the return value back from `thrd_join()`'
// later.

void run(void *arg)
{
  int *a = arg; // We'll pass in an int* from thrd_create()

  printf("THREAD: Running thread with arg %d\n", *a);

  pthread_exit(12); // Value to be picked up by thrd_join() (chose 12 at random)
}

int main(void)
{
  pthread_t t; // t will hold the thread ID
  int arg = 3490;

  printf("Launching a thread\n");

  // Launch a thread to the run() function, passing a pointer to 3490
  // as an argument. Also stored the thread ID in t:

  pthread_create(&t,NULL, run, (void *)&arg);

  printf("Doing other things while the thread runs\n");

  printf("Waiting for thread to complete...\n");

  int *res; // Holds return value from the thread exit

  // Wait here for the thread to complete; store the return value
  // in res:

  pthread_join(t, &res);

  printf("Thread exited with return value %d\n", res);

}