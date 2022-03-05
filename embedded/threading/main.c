#include <stdio.h>
#include <stdlib.h>

#if _WIN32
#include <windows.h>
#else
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#endif

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
  sleep(1);
  printf("Printing from Thread \n");
  return 0;
}

int main()
{
#if _WIN32
  DWORD dwThreadId, dwThrdParam = 1;
  HANDLE hThread;
  hThread = CreateThread(
      NULL,         // default security attributes
      0,            // use default stack size
      myThreadFun,  // thread function
      &dwThrdParam, // argument to thread function
      0,            // use default creation flags
      &dwThreadId); // returns the thread identifier
  printf("The thread ID: %d.\n", dwThreadId);
  // Check the return value for success. If something wrong...

  if (hThread == NULL)
  {
      printf("CreateThread() failed, error: %d.\n", GetLastError());
  }
  else
  {
      printf("It seems the CreateThread() is OK lol!\n");

  }
  if (CloseHandle(hThread) != 0) {
      printf("Handle to thread closed successfully.\n");
  }
#endif
  return 0;
}
