#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{if (argc < 2){
    printf("provide argument\n");
    exit(0);
  }
  char *arg = argv[1];
  
  if (strcmp("types", arg) == 0)
  {
    printf("\
    \n\
    // Data Type                  Memory (bytes)          Range                                Format Specifier\n\
    // ========================================================================================================================= //\n\
    // short int                  2                       -32,768 to 32,767                    ‰hd\n\
    // unsigned short int         2                       0 to 65,535                          ‰hu\n\
    // unsigned int               4                       0 to 4,294,967,295                   ‰u\n\
    // int                        4                      -2,147,483,648 to 2,147,483,647       ‰d\n\
    // long int                   4                      -2,147,483,648 to 2,147,483,647       ‰ld\n\
    // unsigned long int          4                       0 to 4,294,967,295                   ‰lu\n\
    // long long int              8                       -(2^63) to (2^63)-1                  ‰lld\n\
    // unsigned long long int     8                       0 to 18,446,744,073,709,551,615      ‰llu\n\
    // signed char                1                       -128 to 127                          ‰c\n\
    // unsigned char              1                       0 to 255                             ‰c\n\
    // float                      4                                                            ‰f\n\
    // double                     8                                                            ‰lf\n\
    // long double                16                                                           ‰Lf\n\
    \n");
  }
  else if (strcmp("parrallism", arg) == 0)
  {
    printf("\
    \n\
    // Parallelism is related to an application where tasks are divided into smaller sub-tasks that are processed \n\
    // seemingly simultaneously or parallel. It is used to increase the throughput and computational speed of \n\
    // the system by using multiple processors. It enables single sequential CPUs to do lot of things “seemingly” simultaneously. \n\
    // Parallelism leads to overlapping of central processing units and input-output tasks in one process with the central \n\
    // processing unit and input-output tasks of another process. Whereas in concurrency the speed is increased by overlapping \n\
    // the input-output activities of one process with CPU process of another process.\n\
    \n");
  }
  else if (strcmp("concurrency", arg) == 0)
  {
    printf("\
    \n\
    // single core cpus can run multiple threads through the use of interrupts\n\
    // this allows for context switching between applications\n\
    //\n\
    // In a multithreaded process on a single processor, the processor can switch execution resources between threads,\n\
    // resulting in concurrent execution. Concurrency indicates that more than one thread is making progress,\n\
    // but the threads are not actually running simultaneously.\n\
    \n\
    // Concurrency relates to an application that is processing more than one task at the same time. \n\
    // Concurrency is an approach that is used for decreasing the response time of the system by using the single processing unit. \n\
    // Concurrency is creates the illusion of parallelism, however actually the chunks of a task aren’t parallelly processed, \n\
    // but inside the application, there are more than one task is being processed at a time. \n\
    // It doesn’t fully end one task before it begins ensuing. \n\
    // Concurrency is achieved through the interleaving operation of processes on the central processing unit(CPU) or \n\
    // in other words by the context switching. that’s rationale it’s like parallel processing. \n\
    // It increases the amount of work finished at a time. \n\
    \n");
  }
  else if (strcmp("amdahl", arg) == 0)
  {
    printf("\n\
    // After reducing the sequential part of her code to 20‰ and using 4 cores instead of 1 for the\n\
    // rest of the code, Maria’s program ran 3 times faster compared to the original code.\n\
    // check with Amdhal’s law... E.g. 1/(0.2+0.8/4)=2.5<3 ->so first sentence if false\n\
    //\n\
    // Identifies performance gains from adding additional cores to an application\n\
    // The application has both serial and parallel components\n\
    // S - is serial portion, N - is processing cores\n\
    //\n\
    // equation:\n\
    // speedup <= 1(S + (1-S / N))\n\
    // this means that if app is 75‰ parallel and 25‰ serial, moving from 1 to 2 cores results in speedup of 1.6 times\n\
    // 1(0.25 + (1-0.25 / 0.75)) -> 1(0.25 + (1/0.75)) -> 1(0.25 + 1.33) -> 1(1.58) -> 1.58 = rounded to 1.6\n\
    // As N approaches infinity, speedup approaches - 1 / S\n\
    // ========================================================================================================================= //\n\
    // Amdahl's Law # 2\n\
    // ========================================================================================================================= //\n\
    // Amdahl’s Law was named after Gene Amdahl, who presented it in 1967.\n\
    // In general terms, Amdahl’s Law states that in parallelization,\n\
    // if P is the proportion of a system or program that can be made parallel,\n\
    // and 1-P is the proportion that remains serial, then the maximum speedup S(N)\n\
    // that can be achieved using N processors is:\n\n\
    //                 S(N)=1/((1-P)+(P/N))\n\n\
    // As N grows the speedup tends to 1/(1-P).\n\
    //\n\
    // Speedup is limited by the total time needed for the sequential (serial) part of the program.\n\
    // For 10 hours of computing, if we can parallelize 9 hours of computing and 1 hour cannot be parallelized,\n\
    // then our maximum speedup is limited to 10 times as fast. If computers get faster the speedup itself stays the same.\n\
    \n");
  }
  else if (strcmp("threads", arg) == 0)
  {
    printf("\
    \n\
    // Semaphore\n\
    // In computer science, a semaphore is a variable or abstract data type\n\
    // used to control access to a common resource by multiple threads\n\
    // and avoid critical section problems in a concurrent system such as a multitasking operating system.\n\
    // Semaphores are a type of synchronization primitives.\n\
    // A trivial semaphore is a plain variable that is changed (for example, incremented or decremented, or toggled)\n\
    // depending on programmer-defined conditions.\n\
    \n\
    //  Function\n\
    // #include <pthread.h> // thread lib\n\
    // #include <stdlib.h> // standard lib for malloc\n\
    // #include <stdio.h> // for printf and sprintf\n\
    // #include <string.h> // for strcmp\n\
    \n\
    // #include 'common.h' // common header file\n\
    \n\
    // // function declarations\n\
    // void *worker(void *);\n\
    \n\
    // // mutex init (to lock and unlock threads)\n\
    // pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;\n\
    // int completed = 0; // number of completed tasks\n\
    // int n_args;        // number of provided args\n\
    \n\
    // // main function\n\
    // int thread_prime(int argc, char *argv[])\n\
    // {\n\
    //   n_args = argc - 1;         // args -1 accounting for argv[0] being the file name\n\
    //   char *tasks[n_args];       // init results of tasks\n\
    //   pthread_t threads[n_args]; // array of threads corresponding to argc-1\n\
    //   int th_code;               // thread return code\n\
    \n\
    //   // loop through and create the threads\n\
    //   for (int i = 1; i < argc; i++)\n\
    //   {\n\
    //     // create thread\n\
    //     th_code = pthread_create(&threads[i], NULL, worker, (void *)argv[i]);\n\
    //     if (th_code < 0) // check if error\n\
    //     {\n\
    //       // print err and code if unable to make thread\n\
    //       printf('Error: unable to create thread, ‰d\n', th_code);\n\
    //       // exit with error code 1\n\
    //       exit(1);\n\
    //     }\n\
    //   }\n\
    //   // loop through and join the threads\n\
    //   for (int i = 1; i < argc; i++)\n\
    //   {\n\
    \n\
    //     void *return_val; // return value holder\n\
    //     // join thread\n\
    //     th_code = pthread_join(threads[i], &return_val);\n\
    //     if (th_code < 0) // check if error\n\
    //     {\n\
    //       // print err and code if unable to join thread\n\
    //       printf('Error: unable to create thread, ‰d\n', th_code);\n\
    //       // exit with error code 1\n\
    //       exit(1);\n\
    //     }\n\
    \n\
    //     char *str = malloc(100);\n\
    //     sprintf(str, '‰d - ‰s\n', atoi(argv[i]), (char *)return_val);\n\
    //     tasks[i] = str;\n\
    //   }\n\
    //   int i; // declare i\n\
    //   // loop through and print the results\n\
    //   for (i = 0; i <= n_args; i++)\n\
    //   {\n\
    //     printf('‰s', tasks[i]); // print result\n\
    //   }\n\
    //   pthread_exit(NULL); // exit main thread\n\
    // }\n\
    \n\
    // // threads job function\n\
    // void *worker(void *argument)\n\
    // {\n\
    //   pthread_mutex_lock(&lock);                   // lock the thread\n\
    \n\
    //   char *return_val = malloc(sizeof(argument)); // allocate space for return_value\n\
    //   char *arg;                                   // char pointer for argument (still void pointer)\n\
    //   arg = (char *)argument;                      // cast void pointer to char * so we can access arg\n\
    //   int v = atoi(arg);                           // change string to int\n\
    //   if (isPrime(v) == 0)                         // if the result of isPrime is 0 its prime\n\
    //   {\n\
    //     strcpy(return_val, 'Prime'); // put Prime in return_val\n\
    //   }\n\
    //   else // if the result of isPrime is 1 its not prime\n\
    //   {\n\
    //     strcpy(return_val, 'Not Prime'); // put Not Prime in return_val\n\
    //   }\n\
    //   completed++; // incremented completed tasks\n\
    //   printf('‰d out of ‰d numbers checked\n', completed, n_args);\n\
    //   pthread_mutex_unlock(&lock); // unlock the thread\n\
    //   pthread_exit(return_val);    // close thread\n\
    // }\n\
    \n\
    // /*\n\
    // Question 3: Multithreaded elevator – 8 points\n\
    // Create a multithreaded elevator program. The main thread should be responsible for the interaction\n\
    // between the user and the elevator. The child thread should control the elevator’s movement.\n\
    // The elevator should move between 0 and MAX floors (MAX is defined by you, should be between 10\n\
    // and 20). The travel time between each floor is 1 second. When the elevator reaches the desired\n\
    // floor, a message is printed on the console. When the elevator moves between the floors, a message\n\
    // with the elevator’s position should be printed to the console when passing a floor and once in￾between every floor.\n\
    // The user can choose the floor where he/she wants to travel only when the elevator is waiting at one\n\
    // of the floors. When the user chooses a new floor while the elevator is in motion (moving to the\n\
    // destination floor), an error message should be printed.\n\
    // The user can always choose to print the status of the elevator. The output of the status should be:\n\
    // waiting_for_user or moving. */\n\
    // #include <stdio.h>\n\
    // #include <pthread.h>\n\
    // #include <unistd.h>\n\
    // #include <stdlib.h> //header imported to use the random function and malloc\n\
    // #include <time.h>   //header imported to use the random function\n\
    \n\
    // #define MAX 20\n\
    \n\
    // void *elevator(void *param);\n\
    // void *movement(void *);\n\
    // int acquireFloor(int min, int m);\n\
    // void clear_stdin();\n\
    \n\
    // pthread_mutex_t movingSem = PTHREAD_MUTEX_INITIALIZER;\n\
    // int currentFloor = 0;\n\
    // int destination = 0;\n\
    // int moving = 0;\n\
    \n\
    // int main()\n\
    // {\n\
    //   pthread_t thread;\n\
    //   if (pthread_create(&thread, NULL, movement, NULL))\n\
    //   {\n\
    //     printf('error creating thread\n');\n\
    //     return -1;\n\
    //   }\n\
    \n\
    //   printf('-1 : print status \n 0-‰d: to select a floor\n\n', MAX);\n\
    \n\
    //   while (1)\n\
    //   {\n\
    //     int input = acquireFloor(-1, MAX); // prints user prompt for input to console\n\
    \n\
    //     pthread_mutex_lock(&movingSem);\n\
    //     if (input == -1)\n\
    //     {\n\
    //       if (moving)\n\
    //       {\n\
    //         printf('status: Moving');\n\
    //       }\n\
    //       else\n\
    //         printf('status: waiting for user input');\n\
    //     }\n\
    //     else\n\
    //     {\n\
    //       if (moving == 1)\n\
    //       {\n\
    //         printf('the elevator is already moving');\n\
    //       }\n\
    //       else\n\
    //       {\n\
    //         moving = 1;\n\
    //         destination = input;\n\
    //       }\n\
    //     }\n\
    //     pthread_mutex_unlock(&movingSem);\n\
    //   }\n\
    //   pthread_join(thread, NULL);\n\
    // }\n\
    \n\
    // void *movement(void *param)\n\
    // {\n\
    //   while (1)\n\
    //   {\n\
    //     pthread_mutex_lock(&movingSem);\n\
    //     if (moving)\n\
    //     {\n\
    //       printf('\nCurrent floor:‰d', currentFloor);\n\
    //       if (destination > currentFloor)\n\
    //       {\n\
    //         currentFloor++;\n\
    //       }\n\
    //       else if (destination < currentFloor)\n\
    //       {\n\
    //         currentFloor--;\n\
    //       }\n\
    //       else\n\
    //       {\n\
    //         printf('Arrived\n');\n\
    //         moving = 0;\n\
    //       }\n\
    //     }\n\
    //     pthread_mutex_unlock(&movingSem);\n\
    //     sleep(1);\n\
    //   }\n\
    \n\
    //   pthread_exit(NULL);\n\
    // }\n\
    \n\
    // // the following function is from my group (2), IT WAS ALSO ORIGINALLY WRITTEN BY ME IN ONE OF THE LABS (one of the first labs, i don't remember which).\n\
    // // what it does it's just safely acquire a value between min and max, if this is considered plagmarism, a scanf does the same as this function it's does not check the values though\n\
    // int acquireFloor(int min, int m)\n\
    // {\n\
    \n\
    //   int inputVal; // acquired val\n\
    \n\
    //   char endLine;       // to check if the value insered is actually an integer\n\
    //   int wrongInput = 0; // a 'boolean' value to keep track of the (wrong) user input\n\
    \n\
    //   do\n\
    //   {\n\
    //     // the input is not yet wrong\n\
    //     wrongInput = 0;\n\
    //     // asking the user to insert a value\n\
    \n\
    //     // acquiring the user answer inputVal, and also acquiring a new line character to make sure an integer is insered\n\
    //     if (scanf('‰d‰c', &inputVal, &endLine) != 2 || endLine != '\n')\n\
    //     {\n\
    //       // clean the input buffer after reading the input\n\
    //       clear_stdin();\n\
    //       // printing an error message to the user\n\
    //       perror('\n**ERROR: unexpected value in input**\n');\n\
    //       // the value insered is not correct, so wrongInput=1;\n\
    //       wrongInput = 1;\n\
    //     }\n\
    \n\
    //     // the user is asked to insert a coordinate value untill it's a value between min and max (and it's a number, the last condition in the do-while guard checks this)\n\
    //   } while ((inputVal > m || inputVal < min) || wrongInput == 1);\n\
    \n\
    //   // returning the value read\n\
    //   return inputVal;\n\
    // }\n\
    // // to clear the stdin buffer since fflush on unix doesn't work\n\
    // void clear_stdin()\n\
    // {\n\
    //   //'moving' forward the pointer related with the stdin buffer, until \n\n\
    //   while (getchar() != '\n')\n\
    //   {\n\
    //     ;\n\
    //   }\n\
    // }\n\
    \n");
  }
  else if (strcmp("libs", arg) == 0)
  {
    printf("\
    \n\
    // stdio.h -> input/output\n\
    // unistd.h -> POSIX operating system API (sleep)\n\
    // assert.h -> void assert(int expression) This is actually a macro and not a function, which can be used to add diagnostics in your C program.\n\
    \n\
    // stdlib.h:\n\
    // ---------\n\
    // int atoi(const char *str)                -> Converts the string pointed to, by the argument str to an integer (type int).\n\
    // void *calloc(size_t nitems, size_t size) -> Allocates the requested memory and returns a pointer to it.\n\
    // void *malloc(size_t size)                -> Allocates the requested memory and returns a pointer to it.\n\
    // void *realloc(void *ptr, size_t size)    -> Attempts to resize the memory block pointed to by ptr that was previously allocated with a call to malloc or calloc.\n\
    // void free(void *ptr)                     -> Deallocates the memory previously allocated by a call to calloc, malloc, or realloc.\n\
    // void exit(int status)                    -> Causes the program to terminate normally.\n\
    // void srand(unsigned int seed)            -> This function seeds the random number generator used by the function rand.\n\
    // int rand(void)                           -> Returns a pseudo-random number in the range of 0 to RAND_MAX.\n\
    \n\
    // void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) -> Performs a binary search.\n\
    // void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))  -> Sorts an array.\n\
    // int abs(int x)                           -> Returns the absolute value of x.\n\
    \n\
    // math.h:\n\
    // ---------\n\
    // double exp(double x)                     -> Returns the value of e raised to the xth power.\n\
    // double log(double x)                     ->  Returns the natural logarithm (base-e logarithm) of x.\n\
    // double log10(double x)                   ->  Returns the common logarithm (base-10 logarithm) of x.\n\
    // double pow(double x, double y)           ->  Returns x raised to the power of y\n\
    // double sqrt(double x)                    ->  Returns the square root of x.\n\
    // double fabs(double x)                    ->  Returns the absolute value of x\n\
    // double fmod(double x, double y)          ->  Returns the remainder of x divided by y.\n\
    \n\
    // string.h:\n\
    // ---------\n\
    // int memcmp(const void *str1, const void *str2, size_t n)     ->  Compares the first n bytes of str1 and str2.\n\
    // void *memcpy(void *dest, const void *src, size_t n)          ->  Copies n characters from src to dest.\n\
    // size_t strlen(const char *str)                               ->  Computes the length of the string str up to but not including the terminating null character.\n\
    // int strcmp(const char *str1, const char *str2)               ->  Compares the string pointed to, by str1 to the string pointed to by str2.\n\
    // int strncmp(const char *str1, const char *str2, size_t n)    ->  Compares at most the first n bytes of str1 and str2.\n\
    // char *strcpy(char *dest, const char *src)                    ->  Copies the string pointed to, by src to dest.\n\
    // char *strtok(char *str, const char *delim)                   ->  Breaks string str into a series of tokens separated by delim.\n\
    \n\
    // ctype.h:\n\
    // ---------\n\
    // int isalnum()                        -> This function checks whether the passed character is alphanumeric.\n\
    // int isalpha(int c)                   -> This function checks whether the passed character is alphabetic.\n\
    // int isdigit(int c)                   -> This function checks whether the passed character is decimal digit.\n\
    // int islower(int c)                   -> This function checks whether the passed character is lowercase letter.\n\
    // int isspace(int c)                   -> This function checks whether the passed character is white-space.\n\
    // int isupper(int c)                   -> This function checks whether the passed character is an uppercase letter.\n\
    // int isxdigit(int c)                  -> This function checks whether the passed character is a hexadecimal digit.\n\
    // int tolower(int c)                   -> This function converts uppercase letters to lowercase.\n\
    // int toupper(int c)                   -> This function converts lowercase letters to uppercase.\n\
    \n\
    // errno.h:\n\
    // ---------\n\
    // extern int errno   -> This is the macro set by system calls and some library functions in the event of an error to indicate what went wrong.\n\
    \n\
    // pthread.h: (cc -lpthread file.c)\n\
    // ---------\n\
    // pthread_t pthread_self(void) used to get the thread id of the current thread.\n\
    // int pthread_detach(pthread_t thread) used to detach a thread. A detached thread does not require a thread to join on terminating. The resources of the thread are automatically released after terminating if the thread is detached.\n\
    // pthread_cond_t PTHREAD_COND_INITIALIZER\n\
    // pthread_mutex_t PTHREAD_MUTEX_INITIALIZER\n\
    // pthread_rwlock_t PTHREAD_RWLOCK_INITIALIZER\n\
    \n\
    // int pthread_create(pthread_t *restrict, const pthread_attr_t *restrict, void *(*)(void*), void *restrict);\n\
    // ARGS:\n\
    // thread: pointer to an unsigned integer value that returns the thread id of the thread created.\n\
    // attr: pointer to a structure that is used to define thread attributes like detached state, scheduling policy, stack address, etc. Set to NULL for default thread attributes.\n\
    // start_routine: pointer to a subroutine that is executed by the thread. The return type and parameter type of the subroutine must be of type void *. The function has a single attribute but if multiple values need to be passed to the function, a struct must be used.\n\
    // arg: pointer to void that contains the arguments to the function defined in the earlier argument\n\
    \n\
    // int pthread_join(pthread_t, void **);\n\
    // pthread_mutex_lock(pthread_mutex_t *);\n\
    // pthread_mutex_unlock(pthread_mutex_t *);\n\
    // pthread_exit(void *);\n\
    // ARGS:\n\
    // This method accepts a mandatory parameter retval\n\
    // which is the pointer to an integer that stores the return status of the thread terminated.\n\
    // The scope of this variable must be global so that any thread waiting to join this thread may read the return status.\n\
    \n");
  }
  else if (strcmp("input", arg) == 0)
  {
    printf("\
    \n\
    // char str1[5];\n\
    // if(fgets (str1, 5, stdin) != NULL) {\n\
    //   /* writing content to stdout */\n\
    //   printf('‰s', str1);\n\
    // }\n\
    // fgets is safe (but does not convert)\n\
    // sscanf lets your converit the line you got with fgets\n\
    \n\
    // #include <stdio.h>\n\
    \n\
    // void getInputToInt()\n\
    // {\n\
    //   char line[256];\n\
    //   int i;\n\
    //   if (fgets(line, sizeof(line), stdin)) {\n\
    //     if (1 == sscanf(line, '‰d', &i)) {\n\
    //       /* i can be safely used */\n\
    //       printf('‰d', i);\n\
    //     }\n\
    //   }\n\
    // }\n\
    \n\
    // // still better to use fgets\n\
    // #define LINE 80\n\
    // int read_input()\n\
    // {\n\
    //   char buffer[LINE+1];\n\
    //   int i;\n\
    //   int ch;\n\
    \n\
    //   printf( 'Please enter string\n' );\n\
    \n\
    //   /* Keep reading until either:\n\
    //     1. the length of LINE is exceeded  or\n\
    //     2. the input character is EOF  or\n\
    //     3. the input character is a new-line character\n\
    //   */\n\
    \n\
    //   for ( i = 0; ( i  < LINE ) && (( ch = getchar()) != EOF) && ( ch !='\\n' ); ++i )\n\
    //   {\n\
    //     buffer[i] = ch;\n\
    //   }\n\
    \n\
    //   buffer[i] = '\\0';  /* a string should always end with '\\0' ! */\n\
    //   printf( 'The string is ‰s\\n', buffer );\n\
    //   return 0;\n\
    // }\n\
    \n\
    // int main( )\n\
    // {\n\
    //   char c;\n\
    //   int i,l;\n\
    \n\
    //   fprintf(stdout, 'Enter the string length: ');\n\
    //   fscanf(stdin,'‰d', &l);\n\
    //   fprintf(stdout, 'Enter a value :');\n\
    \n\
    //   for (i=0; i<=l; i++)\n\
    //   {\n\
    //     c=getc(stdin);\n\
    //     putc(c,stdout);\n\
    //   }\n\
    //   fprintf(stdout, '\\n');\n\
    //   return 0;\n\
    // }\n\
    \n");
  }
  else if (strcmp("math", arg) == 0)
  {
    printf("\
    \n\
    // check whether a num is prime or not\n\
    // int isPrime(int n)\n\
    // {\n\
    //   // return 1 for non-prime number\n\
    //   if (n == 0)\n\
    //     {\n\
    //       return 1;			// if the arg was 0 it is not prime\n\
    //     }\n\
    //   // for 2 to n/2 check if n modulo i == 0 (basically checking if divisible)\n\
    //   for (int i = 2; i <= n / 2; ++i)\n\
    //     {\n\
    //       // if n is divisible by i, then n is not prime\n\
    //       if (n ﹪ i == 0)\n\
    // 	{\n\
    // 	  // return 1 for not prime (was divisible)\n\
    // 	  return 1;\n\
    // 	}\n\
    //     }\n\
    //   return 0;			// passed all criteria it is prime\n\
    // }\n\
    \n\
    // // recursive fibonacci\n\
    // int fib(int n)\n\
    // {\n\
    //   if (n <= 1) // base case\n\
    //   {\n\
    //     return n; // return 0 or 1 since those are what n<=1 will catch\n\
    //   }\n\
    //   return fib(n-2) + fib(n-1); // recursively take the last two numbers in the sequence and sum\n\
    // }\n\
    // // // memoization fib\n\
    // // //                           fib(5)\n\
    // // //                     /                \\\n\
    // // //               fib(4)                fib(3)\n\
    // // //             /        \\              /       \\ \n\
    // // //         fib(3)      fib(2)         fib(2)   fib(1)\n\
    // // //         /    \\       /    \\        /      \\\n\
    // // //   fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)\n\
    // // //   /     \\n\
    // // // fib(1) fib(0)\n\
    // int memo_fib(int n)\n\
    // {\n\
    //   /* Declare an array to store Fibonacci numbers. */\n\
    //   int f[n+2];   // 1 extra to handle case, n = 0\n\
    //   int i;\n\
    //   /* 0th and 1st number of the series are 0 and 1*/\n\
    //   f[0] = 0;\n\
    //   f[1] = 1;\n\
    //   for (i = 2; i <= n; i++)\n\
    //   {\n\
    //     /* Add the previous 2 numbers in the series\n\
    //       and store it */\n\
    //     f[i] = f[i-1] + f[i-2];\n\
    //   }\n\
    //   return f[n];\n\
    // }\n\
    \n\
    // // power of a number\n\
    // int pow_of_num(int base, int expn)\n\
    // {\n\
    // if (expn != 0) // if we arnt 0 yet keep going\n\
    //   return (base * pow_of_num(base, expn-1)); // recursively call pow_of_num with expn being 1 less\n\
    // else\n\
    //   return 1; // once expn hits 0 return 1 (last call)\n\
    // }\n\
    \n\
    // int factorial(int n)\n\
    // {\n\
    //   int i;\n\
    //   int base = 1;\n\
    //   if (n < 0)\n\
    //   {\n\
    //     base = 0;\n\
    //   }\n\
    //   else\n\
    //   {\n\
    //     for (i = 1; i <= n; ++i)\n\
    //     {\n\
    //       base *= i;\n\
    //     }\n\
    //     // printf('Factorial of ‰d = ‰l', n, base);\n\
    //   }\n\
    //   return base;\n\
    // }\n\
    \n\
    // // factorial\n\
    // int recursive_fact(int n)\n\
    // {\n\
    // 	if(n==0)\n\
    // 	{\n\
    // 		return 1;\n\
    // 	}\n\
    // 	else\n\
    // 	{\n\
    // 		return n * recursive_fact(n-1);\n\
    // 	}\n\
    // }\n\
    \n\
    // // FRACTIONS\n\
    // void add()\n\
    // {\n\
    // 	num = ((x1 * y2) + (y1 * x2));\n\
    // 	denom = (y1 * y2);\n\
    // }\n\
    \n\
    // void subtract()\n\
    // {\n\
    // 	num = ((x1 * y2) - (y1 * x2));\n\
    // 	denom = (y1 * y2);\n\
    // }\n\
    \n\
    // void multiply()\n\
    // {\n\
    // 	num = (x1 * x2);\n\
    // 	denom = (y1 * y2);\n\
    // }\n\
    \n\
    // void divide()\n\
    // {\n\
    // 	num = (x1 * y2);\n\
    // 	denom = (y1 * x2);\n\
    // }\n\
    \n\
    // Fraction add_fractions(Fraction a, Fraction b)\n\
    // {\n\
    //     Fraction x;\n\
    //     a.n *= b.d;\n\
    //     b.n *= a.d;\n\
    \n\
    //     x.n = a.n + b.n;\n\
    //     x.d = a.d * b.d;\n\
    \n\
    //     return x;\n\
    // }\n\
    \n");
  }
  else if (strcmp("bit", arg) == 0)
  {
    printf("\
    \n\
    // Constant true is 1 and constant false is 0.\n\
    \n\
    // int a = 60;	      /* 60 = 0011 1100 represents 60 in binary*/\n\
    // int b = 13;	      /* 13 = 0000 1101 */\n\
    // int c = 0;\n\
    \n\
    // c = a & b;        /* 12 = 0000 1100 */\n\
    // c = a | b;        /* 61 = 0011 1101 */\n\
    // c = a ^ b;        /* 49 = 0011 0001 */\n\
    // c = ~a;           /*-61 = 1100 0011  :Invert all bits */\n\
    \n\
    // // shift operators : zeros are shifted in to replace the discarded bits\n\
    // c = a << 2;       /* 240 = 1111 0000 : Shift left 2 bits*/\n\
    // c = a >> 2;       /* 15 = 1111 */\n\
    // c = a >>> 2;      /* 15 = 0000 1111 : Zero fill right shift*/\n\
    \n\
    \n\
    // | b1 | b2 | & | | | ^ |\n\
    // -----------------------\n\
    // | 1  | 0  | 1 | 1 | 0 |\n\
    // | 1  | 0  | 0 | 1 | 1 |\n\
    // | 0  | 1  | 0 | 1 | 1 |\n\
    // | 0  | 0  | 0 | 0 | 0 |\n\
    \n\
    // | b | ~ |\n\
    // ---------\n\
    // | 1 | 0 |\n\
    // | 0 | 1 |\n\
    \n\
    // void outputBinary(uint32_t x)\n\
    // {\n\
    //   char binary[35];\n\
    //   for (int i = 0; i < 35; i++)\n\
    //   {\n\
    //     if (i == 8 || i == 17 || i == 26)\n\
    //     { // loop over each number in the array of bits\n\
    //       binary[i] = '.';\n\
    //     }\n\
    //     else\n\
    //     {\n\
    //       // we shift the decimal down based on the ith digit \n\
    //       // of the binary representation and check whether that digit should be a 1 or a 0\n\
    //       binary[i] = (char)(x >> i) & 1;\n\
    //     }\n\
    //   }\n\
    //   for (int i = 35 - 1; i >= 0; i--) // for each number in the array in reverse order\n\
    //   {\n\
    //     if (i == 8 || i == 17 || i == 26)\n\
    //     {\n\
    //       printf(' ‰c ', binary[i]);\n\
    //     }\n\
    //     else\n\
    //       printf('i: ﹪ d, ﹪ d ', i, binary[i]); // print every element\n\
    //   }\n\
    //   printf('\n '); // next line\n\
    // }\n\
    \n\
    // #include <stdio.h>\n\
    // #include <stdlib.h>\n\
    \n\
    // char *bin(unsigned int n)\n\
    // {\n\
    //   int len = sizeof(int) * 8 - 1;\n\
    //   char *buff = malloc(len);\n\
    //   for(int i = len; i >= 0; i--)\n\
    //   {\n\
    //     int bit = (n >> i & 1) ? 1 : 0;\n\
    //     sprintf(buff, ' ‰s ﹪ d ', buff, bit);\n\
    //   }\n\
    //   return buff;\n\
    // }\n\
    \n\
    // int main()\n\
    // {\n\
    //   int value = 12345678;\n\
    //   char *b = bin(value);\n\
    //   printf(' binary: ﹪ s ', b);\n\
    //   free(b);\n\
    //   return 0;\n\
    // }\n\
    \n\
    // typedef unsigned char byte;\n\
    \n\
    // int convertdectobin(int number) {\n\
    //     int binary = 0;\n\
    //     int remainder = 1, i = 1;\n\
    \n\
    //     // 0b0000 1101\n\
    //     while (number != 0) {\n\
    //         remainder = number ﹪ 2;\n\
    //         number /= 2;\n\
    //         binary += remainder * i;\n\
    //         i = i * 10;\n\
    //     }\n\
    //     printf(' the binary value of ‰d is ﹪ d ', number, binary);\n\
    //     return binary;\n\
    // }\n\
    \n\
    // Decimal (Base 10)	Binary (Base 2)	Hexadecimal (Base 16)\n\
    //           0	        00000011	      0x00\n\
    //           1	        00000001	      0x01\n\
    //           2	        00000010	      0x02\n\
    //           3	        00000011	      0x03\n\
    //           4	        00000100	      0x04\n\
    //           5	        00000101	      0x05\n\
    //           6	        00000110	      0x06\n\
    //           7	        00000111	      0x07\n\
    //           8	        00001000	      0x08\n\
    //           9	        00001001	      0x09\n\
    //           10	      00001010	      0x0A\n\
    //           11	      00001011	      0x0B\n\
    //           12	      00001100	      0x0C\n\
    //           13	      00001101	      0x0D\n\
    //           14	      00001110	      0x0E\n\
    //           15	      00001111	      0x0F\n\
    \n\
    // // To convert a hexadecimal number into decimal, we have to calculate the sum of the powers of 16 of the number.\n\
    // // Example 1.11\n\
    // // Convert hexadecimal number 2AC base(16) into decimal.\n\
    // // Solution 1.11\n\
    // // Calculating the sum of the powers of 16 of the number:\n\
    // // 2AC base(16) = 2 × 16^2 + 10 × 16^1 + 12 × 160 = 512 + 160 + 12 = 684\n\
    // // The required decimal number is 684 base(10).\n\
    \n\
    // // Example 1.12\n\
    // // Convert hexadecimal number EE base(16) into decimal.\n\
    // // Solution 1.12\n\
    // // Calculating the sum of the powers of 16 of the number:\n\
    // // EE base(16)= 14 × 16^1 + 14 × 16^0 = 224 + 14 = 238\n\
    // // The required decimal number is 238 base(10).\n\
    // void to_bin(byte b) {\n\
    //   int binary[8];\n\
    //   for (int n = 0; n < 8; n++)\n\
    //   {\n\
    //     /*\n\
    //       bit a 	bit b 	a & b (a AND b)\n\
    //       0       &	0     =	0\n\
    //       0       &	1     =	0\n\
    //       1       &	0     =	0\n\
    //       1       &	1     =	1\n\
    \n\
    //       64   8,4\n\
    //       0100 1100 - 76 & 0000 0001 = 0000 0000\n\
    //       >> 0\n\
    //       [0]\n\
    //       0010 0110 - 38 & 0000 0001 = 0000 0000\n\
    //       >> 1\n\
    //       [0,0]\n\
    //       0001 0011 - 19 & 0000 0001 = 1 0000 0001\n\
    //       >> 2\n\
    //       0000 1001 - 9 & 0000 0001 = 1 0000 0001\n\
    //       >> 3\n\
    //       0000 0100 - 4 & 0000 0001 = 0 0000 0000\n\
    //       >> 4\n\
    //       0000 0010 - 2 & 0000 0001 = 0 0000 0000\n\
    //       >> 5\n\
    //       0000 0001 - 1 & 0000 0001 = 1 0000 0001\n\
    //       >> 6\n\
    //       0000 0000 - 0 & 0000 0001 = 0 0000 0000\n\
    \n\
    //     */\n\
    //     binary[7 - n] = (b >> n) & 1;\n\
    //   }\n\
    //   // for (int n = 0; n < 8; n++)\n\
    //   // {\n\
    //   //   printf(' ‰d ', binary[n]);\n\
    //   // }\n\
    //   // printf('\n ');\n\
    // }\n\
    \n\
    // //                               A   B   C   D   E       F\n\
    // // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, and 15\n\
    \n\
    // // HEX FUNCTIONS\n\
    // function toHex(d) {\n\
    //   var r = d ﹪ 16;\n\
    //   if (d - r == 0) {\n\
    //     return toChar(r);\n\
    //   }\n\
    //   return toHex((d - r) / 16) + toChar(r);\n\
    // }\n\
    \n\
    // function toChar(n) {\n\
    //   const alpha = ' 0123456789ABCDEF ';\n\
    //   return alpha.charAt(n);\n\
    // }\n\
    // void to_hex(byte b)\n\
    // {\n\
    //   printf(' 0x ‰X ', b);\n\
    // }\n\
    \n\
    // void trailing_zeros(byte b)\n\
    // {\n\
    //   int binary[8];\n\
    //   for (int n = 0; n < 8; n++)\n\
    //   {\n\
    //     binary[7 - n] = (b >> n) & 1;\n\
    //   }\n\
    //   printf(' Binary Representation: ');\n\
    //   for (int n = 0; n < 8; n++)\n\
    //   {\n\
    //     printf(' ﹪ d ', binary[n]);\n\
    //   }\n\
    //   printf('\n ');\n\
    //   int i = 0;\n\
    //   for (int n = 0; n < 8; n++)\n\
    //   {\n\
    //     if (((b >> n) & 1) == 0)\n\
    //     {\n\
    //     i++;\n\
    //     }\n\
    //     else\n\
    //     {\n\
    //       break;\n\
    //     }\n\
    //   }\n\
    //   printf(' Trailing Zeros: ﹪ d ', i);\n\
    // }\n\
    \n\
    // int checkOdd(int n)\n\
    // {\n\
    //   // second version\n\
    //   // n&1 is 1, then odd, else even\n\
    //   return (!(n & 1));\n\
    // }\n\
    // // Returns true if n is even, else odd\n\
    // // X 	Y 	X^Y\n\
    // // 0 	0 	0\n\
    // // 0 	1 	1\n\
    // // 1 	0 	1\n\
    // // 1 	1 	0\n\
    // int checkEven(int n)\n\
    // {\n\
    //     // n^1 is n+1, then even, else odd\n\
    //     // ex:\n\
    //     // 10 - 0000 1010 ^ 0000 0001 = 0000 1011 (11)\n\
    //     // 10+1 = 11\n\
    //     // equal == even\n\
    \n\
    //     // ex2:\n\
    //     // 9 - 0000 1001 ^ 0000 0001 = 0000 1000 (8)\n\
    //     // 9 + 1 = 10\n\
    //     // not equal == odd\n\
    \n\
    //     // ex3:\n\
    //     // 9 - 1000 0000 ^ 0000 0001 = 1000 0001 (129)\n\
    //     // 128 + 1 = 129\n\
    //     // equal == even\n\
    //     if (n ^ 1 == n + 1)\n\
    //     {\n\
    //         return 1; // true\n\
    //     }\n\
    //     else\n\
    //     {\n\
    //         return 0; // false\n\
    //     }\n\
    // }\n\
    \n\
    // void count_one_n_zero(byte b)\n\
    // {\n\
    //   int binary[8];\n\
    //   for (int n = 0; n < 8; n++)\n\
    //   {\n\
    //     binary[7 - n] = (b >> n) & 1;\n\
    //   }\n\
    //   printf(' Binary Representation: ');\n\
    //   for (int n = 0; n < 8; n++)\n\
    //   {\n\
    //     printf(' ﹪ d ', binary[n]);\n\
    //   }\n\
    //   printf('\n ');\n\
    //   int one = 0;\n\
    //   int zero = 0;\n\
    //   for (int n = 0; n < 8; n++)\n\
    //   {\n\
    //     if (((b >> n) & 1) == 0)\n\
    //     {\n\
    //     zero++;\n\
    //     }\n\
    //     else\n\
    //     {\n\
    //       one++;\n\
    //     }\n\
    //   }\n\
    //   printf(' Number of 1s: ﹪ d\n ', one);\n\
    //   printf(' Number of 0s: ﹪ d\n ', zero);\n\
    // }\n\
    \n\
    // void highest_order_bit(byte b)\n\
    // {\n\
    //   int binary[8];\n\
    //   for (int n = 0; n < 8; n++)\n\
    //   {\n\
    //     binary[7 - n] = (b >> n) & 1;\n\
    //   }\n\
    //   printf(' Binary Representation: ');\n\
    //   for (int n = 0; n < 8; n++)\n\
    //   {\n\
    //     printf(' ‰d ', binary[n]);\n\
    //   }\n\
    //   printf('\n ');\n\
    //   int i = 7;\n\
    //   for (int n = 1; n < 9; n++)\n\
    //   {\n\
    //     if (binary[n-1] == 1)\n\
    //     {\n\
    //       i = n;\n\
    //       break;\n\
    //     }\n\
    //   }\n\
    //   printf(' Highest Order Bit: ‰d\n ', i);\n\
    // }\n\
    \n\
    // #include <stdio.h>\n\
    \n\
    // void highest(int);\n\
    // int main()\n\
    // {\n\
    //   int input;\n\
    //   printf(' What 's the number: ');\n\
    //   scanf('‰d', &input);\n\
    //   highest(input);\n\
    //   return 0;\n\
    // }\n\
    \n\
    // void highest(int input)\n\
    // {\n\
    //   int highest;\n\
    //   for (int i = 0; i < 8; i++)\n\
    //   {\n\
    //     if ((input >> i) & 1)\n\
    //     {\n\
    //       highest = i;\n\
    //     }\n\
    //   }\n\
    //   printf('highest: ‰d', highest);\n\
    //   printf('\n0 : ‰d', (7 >> 0) & 1);\n\
    //   printf('\n1 : ‰d', (7 >> 1) & 1);\n\
    //   printf('\n2 : ‰d', (7 >> 2) & 1);\n\
    //   printf('\n3 : ‰d', (7 >> 3) & 1);\n\
    //   printf('\n4 : ‰d', (7 >> 4) & 1);\n\
    // }\n\
    \n");
  }
  else if (strcmp("pyramid", arg) == 0)
  {
    printf("\
    \n\
    // void print_spaces(int n)\n\
    // {\n\
    //   for (int i = 0; i<n; i++)\n\
    //   {\n\
    //     printf(' ');\n\
    //   }\n\
    // }\n\
    \n\
    // void print_row(char c, int n)\n\
    // {\n\
    //   printf(' ‰c', c);\n\
    //   print_spaces(n);\n\
    //   printf(' ‰c', c);\n\
    // }\n\
    \n\
    // void pyramid(char *str, int len)\n\
    // {\n\
    //   printf('len: ‰d\nstring: ‰s\n', len, str);\n\
    //   print_spaces(len*2);\n\
    //   printf(' ‰c\\n', str[0]);\n\
    //   for (int y = 1, space = 2; y<len-1; y++, space+=4)\n\
    //   {\n\
    //     print_spaces((len-y)*2);\n\
    //     char ch = (char) str[y];\n\
    //     print_row(ch, space);\n\
    //     printf('\\n');\n\
    //   }\n\
    //   printf(' ');\n\
    //   for (int i = len; i >= 0; i--) {\n\
    //     printf(' ‰c', str[i]);\n\
    //   }\n\
    //   for (int i = 1; i < len; i++) {\n\
    //     printf(' ‰c', str[i]);\n\
    //   }\n\
    // }\n\
    \n");
  }
  else if (strcmp("leap", arg) == 0)
  {
    printf("\
    \n\
    // January – 31 days\n\
    // February – 28 days in a common year and 29 days in leap years\n\
    // March – 31 days\n\
    // April – 30 days\n\
    // May – 31 days\n\
    // June – 30 days\n\
    // July – 31 days\n\
    // August – 31 days\n\
    // September – 30 days\n\
    // October – 31 days\n\
    // November – 30 days\n\
    // December – 31 days\n\
    \n\
    // #include <stdio.h>\n\
    \n\
    // void day_in_year(int m, int d, int y)\n\
    // {\n\
    //   int leapDay;\n\
    //   if (y ‰100) {\n\
    //     // not a century\n\
    //     leapDay = ((y ‰4) == 0 ? 1 : 0);\n\
    //   }\n\
    //   else\n\
    //   {\n\
    //     // century\n\
    //     leapDay = ((y ‰400) == 0 ? 1 : 0);\n\
    //   }\n\
    //   char *isLeap = leapDay == 1 ? 'yes' : 'no';\n\
    //   int months[12] = {31, 28+leapDay, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};\n\
    //   months[m-1] = d;\n\
    //   int days = 0;\n\
    //   for (int i = 0; i<m; i++)\n\
    //   {\n\
    //     days += months[i];\n\
    //   }\n\
    //   printf('Leap Year: ‰s\nDay: ‰d', isLeap, days);\n\
    // }\n\
    \n");
  }
  else if (strcmp("str", arg) == 0)
  {
    printf("\
    \n\
    // #include <stdio.h>\n\
    // #include <stdlib.h>\n\
    // #include <string.h>\n\
    \n\
    // // swaps where two ptrs point (basically swaps values)\n\
    // // standard swap function (applied to ptrs)\n\
    // void shift_ch(char *pos1, char *pos2)\n\
    // {\n\
    //     char tmp; // temp char while we swap ptrs\n\
    //     tmp = *pos1; // set them to value pos1 points at\n\
    //     *pos1 = *pos2; // set pos1 pointer to pos2 pointer (bothing point at pos2' s value)\n //     *pos2 = tmp; // point the pos2 pointer at the tmp (old value pos1 pointed at)\n\
    // }\n\
    \n\
    // // Function to print permutations of string\n\
    // //                String,    first idx, last idx\n\
    // void _permute_str(char *str, int first, int last)\n\
    // {\n\
    //   int i = first -1; // declaring variable i and setting to first pos -1 (to account for ++ in while loop on first iteration)\n\
    //   if (first == last) // checking for base case\n\
    //   {\n\
    //     printf('‰s ', str); // print a permutation (once first == last, meaning we got base case and start popping off stack)\n\
    //   }\n\
    //   else // not the base case\n\
    //   {\n\
    //     while(i++<last)\n\
    //     {\n\
    //       shift_ch((str+first), (str+i)); // swap two chars\n\
    //       _permute_str(str, first+1, last); // recursively permutate with the starting shift from the next char\n\
    //       shift_ch((str+first), (str+i)); // undo the changes that were made to the string\n\
    //     }\n\
    //   }\n\
    // }\n\
    \n\
    // void permute_str(char *str, int len)\n\
    // {\n\
    //   printf('The permutations of the string are:\n');\n\
    //   _permute_str(str, 0, len-1);\n\
    // }\n\
    \n\
    // void joinstr()\n\
    // {\n\
    //   char *str1 = 'I love';\n\
    //   char *str2 = 'DIT632';\n\
    //   char *full_str = malloc(12);\n\
    //   sprintf(full_str, '‰s ‰s', str1, str2);\n\
    //   printf('‰s', full_str);\n\
    //   printf('\\n');\n\
    //   free(full_str);\n\
    // }\n\
    \n\
    // int isVowel(char ch)\n\
    // {\n\
    //   // upercase check for vowels\n\
    //   return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||\n\
    //   // lowercase check for vowels\n\
    //           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');\n\
    // }\n\
    \n\
    // void count_vowels_and_consonants(char *str)\n\
    // {\n\
    //   int vowels = 0;\n\
    //   int consonants = 0;\n\
    //   while(*str != '\\0')\n\
    //   {\n\
    //     if (isVowel(*str))\n\
    //     {\n\
    //       vowels++;\n\
    //     }\n\
    //     else\n\
    //     {\n\
    //       consonants++;\n\
    //     }\n\
    //     str++;\n\
    //   }\n\
    //   printf('Number of vowels: ‰d\\n', vowels);\n\
    //   printf('Number of consonants: ‰d', consonants);\n\
    // }\n\
    \n\
    // void grades()\n\
    // {\n\
    //   int input[5] = {0};\n\
    //   int n = 5;\n\
    //   while(n-->0)\n\
    //   {\n\
    //     char line[256];\n\
    //     if (fgets(line, sizeof(line), stdin)) {\n\
    //       sscanf(line, '‰d', &input[n]);\n\
    //     }\n\
    //   }\n\
    //   float sum = 0;\n\
    //   for (int i = 0; i < 5; i++)\n\
    //   {\n\
    //     sum+=input[i];\n\
    //   }\n\
    //   sum /= 5.0;\n\
    //   printf('Percentage: ﹪.2f\\n', sum);\n\
    //   char mark;\n\
    //   if (sum > 90.0) {\n\
    //     mark = 'A';\n\
    //   }\n\
    //   else if (sum > 80.0)\n\
    //   {\n\
    //     mark = 'B';\n\
    //   }\n\
    //   else if (sum > 70.0)\n\
    //   {\n\
    //     mark = 'C';\n\
    //   }\n\
    //   else if (sum > 60.0)\n\
    //   {\n\
    //     mark = 'D';\n\
    //   }\n\
    //   else if (sum > 40.0)\n\
    //   {\n\
    //     mark = 'F';\n\
    //   }\n\
    //   else\n\
    //   {\n\
    //     mark = 'F';\n\
    //   }\n\
    //   printf('Grade: ‰c', mark);\n\
    // }\n\
    \n\
    // #include <stdio.h>\n\
    // #include <stdlib.h>\n\
    \n\
    // int anagram(char[], char[]);\n\
    \n\
    // int main(int argc, char const *argv[])\n\
    // {\n\
    //   char a[10], b[10];\n\
    //   // first = malloc(4);\n\
    //   // second = malloc(4);\n\
    //   printf('Test Data:\\n‰s', 'Input the first string: ');\n\
    //   gets(a);\n\
    //   printf('\\nInput the second string: ');\n\
    //   gets(b);\n\
    \n\
    //   int success = anagram(a, b);\n\
    //   if (success)\n\
    //   {\n\
    //     printf('‰s and ‰s are anagrams', a, b);\n\
    //   }\n\
    //   else\n\
    //     printf('‰s and ‰s are not anagrams', a, b);\n\
    //   return 0;\n\
    // }\n\
    \n\
    // int anagram(char a[], char b[])\n\
    // {\n\
    //   int first[26] = {0}, second[26] = {0}, c = 0;\n\
    \n\
    //   // Calculating frequency of characters of the first string\n\
    \n\
    //   while (a[c] != '\\0')\n\
    //   {\n\
    //     first[a[c] - 'a']++;\n\
    //     c++;\n\
    //   }\n\
    //   printf('‰d', first[a[0] - 'a']);\n\
    \n\
    //   c = 0;\n\
    \n\
    //   while (b[c] != '\\0')\n\
    //   {\n\
    //     second[b[c] - 'a']++;\n\
    //     c++;\n\
    //   }\n\
    \n\
    //   // Comparing the frequency of characters\n\
    \n\
    //   for (c = 0; c < 26; c++)\n\
    //     if (first[c] != second[c])\n\
    //       return 0;\n\
    \n\
    //   return 1;\n\
    // }\n\
    \n");
  }
  else if (strcmp("linkedlist", arg) == 0)
  {
    printf("\
    \n\
    // #include <stdio.h>\n\
    // #include <string.h>\n\
    // #include <stdlib.h>\n\
    // #include <stdbool.h>\n\
    // // structure describing one node of the list\n\
    // struct node\n\
    // {\n\
    //   int data;\n\
    //   int key;\n\
    //   struct node *next;\n\
    // };\n\
    \n\
    // // pointing to the beginning of the list and the current node\n\
    // struct node *head = NULL;\n\
    // struct node *current = NULL;\n\
    \n\
    // // is list empty\n\
    // bool isEmpty()\n\
    // {\n\
    //   return head == NULL;\n\
    // }\n\
    \n\
    // int length()\n\
    // {\n\
    //   int length = 0;\n\
    //   struct node *current;\n\
    \n\
    //   //for (current = head; current != NULL; current = current->next)\n\
    //   while (current != NULL)\n\
    //   {\n\
    //     length++;\n\
    //     current = current->next;\n\
    //   }\n\
    \n\
    //   return length;\n\
    // }\n\
    \n\
    // //insert link at the first location\n\
    // void insertFirst(int key, int data)\n\
    // {\n\
    // //create a link\n\
    //   struct node *link = (struct node *) malloc (sizeof (struct node));\n\
    //   link->key = key;\n\
    //   link->data = data;\n\
    //   if (isEmpty ())\n\
    //     {\n\
    //       head = link;\n\
    //       head->next = head;\n\
    //     }\n\
    //   else\n\
    //     {\n\
    // //point it to old first node\n\
    //       link->next = head;\n\
    // //point first to new first node\n\
    //       head = link;\n\
    //     }\n\
    // }\n\
    \n\
    // //delete first item\n\
    // struct node *deleteFirst()\n\
    // {\n\
    // //save reference to first link\n\
    //   struct node *tempLink = head;\n\
    //   if (head->next == head)\n\
    //     {\n\
    //       head = NULL;\n\
    //       return tempLink;\n\
    //     }\n\
    // //mark next to first link as first\n\
    //   head = head->next;\n\
    // //return the deleted link\n\
    //   return tempLink;\n\
    // }\n\
    \n\
    // //display the list\n\
    // void printList()\n\
    // {\n\
    //   struct node *ptr = head;\n\
    //   printf('\\n[ ');\n\
    // //start from the beginning\n\
    //   if (head != NULL)\n\
    //     {\n\
    //       while (ptr->next != ptr)\n\
    // 	{\n\
    // 	  printf('(‰d,‰d) ', ptr->key, ptr->data);\n\
    // 	  ptr = ptr->next;\n\
    // 	}\n\
    //     }\n\
    //   printf(' ]');\n\
    // }\n\
    \n\
    // void linkedlist()\n\
    // {\n\
    //   insertFirst (1, 10);\n\
    //   insertFirst (2, 20);\n\
    //   insertFirst (3, 30);\n\
    //   insertFirst (4, 1);\n\
    //   insertFirst (5, 40);\n\
    //   insertFirst (6, 56);\n\
    //   printf('Original List: ');\n\
    // //print list\n\
    //   printList ();\n\
    //   // TODO: write the code to delete the entire list\n\
    //   while(head != NULL)\n\
    //   {\n\
    //     free(deleteFirst());\n\
    //   }\n\
    //   printf('\\nList after deleting all items: ');\n\
    //   printList ();\n\
    // }\n\
    \n");
  }
  else if (strcmp("misc", arg) == 0)
  {
    printf("\
    \n\
    // #include <ctype.h>\n\
    // #include <stdio.h>\n\
    // #include <stdlib.h>\n\
    \n\
    // // function declarations\n\
    // void convert(char *in); // convert binary to hexidecimal\n\
    // int valid_bin(char *str); // check if input is a valid binary\n\
    // /*\n\
    // * Main function in the program,\n\
    // * @params argc and argv are passed\n\
    // * @return int (exit code)\n\
    // */\n\
    // int main(int argc, char *argv[])\n\
    // {\n\
    //   char buffer[40], *input; // create buffer array to support input for piping. create input pointer for use in convert() function\n\
    //   if (argc == 1)           // if there is no argument\n\
    //   {\n\
    //     input = fgets(buffer, 40, stdin); // get input from stdin (command line)\n\
    //   }\n\
    //   else\n\
    //   {                  // if there is an argument\n\
    //     input = argv[1]; // get input from argument\n\
    //   }\n\
    //   if (valid_bin(input))\n\
    //   {                 // if to check if input is valid binary\n\
    //     convert(input); // if valid call convert function\n\
    //   }\n\
    //   else\n\
    //   {                                     // if not valid binary input\n\
    //     printf('Invalid binary number.\\n'); // error message\n\
    //     return 1;                           // exit program\n\
    //   }                                     // call function to convert binary to hexadecimal\n\
    //   return 0;                             // successful execution return code\n\
    // }\n\
    \n\
    // // method to convert binary number to hex string\n\
    // void convert(char *in)\n\
    // {\n\
    //   int value = (int)strtol(in, NULL, 2); // convert input from a string to an integer to a base 2 to represent binary\n\
    //   char hex[12];                         // create character array for hex representation\n\
    //   sprintf(hex, '‰x\n', value);          // writes values to the hex array\n\
    //   printf(hex);                          // output hex string to console\n\
    // }\n\
    \n\
    // /* function to check if input is a valid binary representation */\n\
    // int valid_bin(char *str)\n\
    // {\n\
    //   while (*str != '\\n' && *str != '\\0')\n\
    //   { // while string hasn't ended (taking fgets into account, as well as arguments)\n\
    //     if (*str != '0' && *str != '1')\n\
    //     {           // checks if the character is not 1 and not 0\n\
    //       return 0; // returns 0 if input is not a 1 or 0\n\
    //     }\n\
    //     str++; // increments to next character in string\n\
    //   }\n\
    //   return 1; // returns when input is a valid number\n\
    // }\n\
    \n\
    // #include <ctype.h>\n\
    // #include <stdio.h>\n\
    // #include <stdlib.h>\n\
    // #include <string.h>\n\
    \n\
    // void help();\n\
    // void convert(int d);\n\
    // int valid_int(char *str);\n\
    // int get_byte(int arg);\n\
    // /*\n\
    // * Main function in the program,\n\
    // * @params argc and argv passed\n\
    // * @return int (exit code)\n\
    // */\n\
    // int main(int argc, char *argv[])\n\
    // {\n\
    //   if (argc == 2)\n\
    //   { // if one argument was provided\n\
    //     if (strcmp('-h', argv[1]) == 0)\n\
    //     {           // check if help flag is passed as argument\n\
    //       help();   // call function to display help to user\n\
    //       return 0; // exit program\n\
    //     }\n\
    //     int result = valid_int(argv[1]); // result calls valid_int() method and 1 is returned if true, 0 if false\n\
    //     if (result)\n\
    //     {                            // if number is valid\n\
    //       int input = atoi(argv[1]); // convert argument to an integer\n\
    //       convert(input);            // call function to convert the decimal input\n\
    //     }\n\
    //     else\n\
    //     {                                                                           // if not a valid number\n\
    //       printf('Argument is not a valid decimal number. Enter '-h' for help.\\n'); // print error message\n\
    //     }\n\
    //   }\n\
    //   else\n\
    //   {\n\
    //     printf('Please provide one arg. Enter '-h' for help.\\n'); // print error message\n\
    //   }\n\
    //   // successful execution return code\n\
    //   return 0;\n\
    // }\n\
    \n\
    // /* function to display help to the user when required */\n\
    // void help()\n\
    // {\n\
    //   printf('Program to convert decimal to binary, and binary to hexadecimal. Enter one argument - a positive decimal number.\nExample: dec2bin 250 | bin2hec \n'); // helpful information when user requires it\n\
    // }\n\
    \n\
    // /* function to convert the decimal value to a binary representation */\n\
    // void convert(int d)\n\
    // {\n\
    //   int size = get_byte(d); // set size to the number of bits returned from get_byte()\n\
    //   int binary[size];       // create an array of integers the size of the required bits\n\
    //   for (int i = 0; i < size; i++)\n\
    //   {                                 // loop over each number in the array of bits\n\
    //     binary[i] = (char)(d >> i) & 1; // we shift the decimal down based on the ith digit of the binary representation and check whether that digit should be a 1 or a 0\n\
    //   }\n\
    //   for (int i = size - 1; i >= 0; i--)\n\
    //   {                          // for each number in the array in reverse order\n\
    //     printf('‰d', binary[i]); // print every element\n\
    //   }\n\
    //   printf('\n'); // next line\n\
    // }\n\
    \n\
    // /* function to check whether the input is a valid positive number. Also fails if number is a floating point number */\n\
    // int valid_int(char *str)\n\
    // {\n\
    //   while (*str != '\\0')\n\
    //   {\n\
    //     if (!isdigit(*str))\n\
    //     {           // isdigit returns 0 if input is not a number, or 1 if it is a number\n\
    //       return 0; // return when not a number\n\
    //     }\n\
    //     str++; // increment to next character\n\
    //   }\n\
    //   return 1; // return when input is a valid number\n\
    // }\n\
    \n\
    // /* function to check the input number in order to find how many bytes are required. */\n\
    // int get_byte(int arg)\n\
    // {\n\
    //   int n = 0; // number of bytes\n\
    //   while (arg != 0)\n\
    //   {            // when a number still exists\n\
    //     arg >>= 8; // bitshift 8 to the right\n\
    //     n++;       // increment the number of bytes required\n\
    //   }\n\
    //   return n * 8; // return the amount of bits\n\
    // }\n\
    \n\
    // #include <stdio.h> // for standard input/output functions\n\
    // #include <stdlib.h> // for atoi\n\
    // void encrypt(int, char **, char* str); // define the function to encrypt\n\
    \n\
    // int main(int argc, char *argv[]) // main function\n\
    // {\n\
    //   // exit if no argument or too many args were provided\n\
    //   if (argc !=2) { // check if we dont have 2 args\n\
    //     printf('Must provide one argument, which is the amount of shifts for the characters'); // error message\n\
    //     return 1; // exit code (error)\n\
    //   }\n\
    //   // arbitrary size array to hold input\n\
    //   char str[256]; // variable to store user input, 256 is arbitrarly chosen\n\
    //   printf('Enter the string to encrypt.\\n'); // print to console to ask for user input\n\
    //   while (scanf('‰s', str) != EOF) // loop continues until user ends the program via the command line\n\
    //   {\n\
    //     encrypt(argc, argv, str); // function to encrypt is executed\n\
    //     printf('Enter the string to encrypt.\\n'); // print to console to ask for user input\n\
    //   }\n\
    // }\n\
    \n\
    // void encrypt(int argc, char *argv[], char *str) // function to encrypt\n\
    // {\n\
    //     int i = 0; // initialising i to use in while loop\n\
    //     char *a = argv[1]; // create pointer to command line argument for encryption amount\n\
    //     int amount = atoi(a); // get the integer from the character pointer\n\
    \n\
    //     //while (scanf('‰s', input) != EOF)\n\
    //       while (str[i] != '\\0') // while loop continues until end of the user's input string\n\
    //       {\n\
    //         if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) // checks if character is valid alphabet letters\n\
    //         {\n\
    //             if (str[i] < 'a' && str[i] > 'Z' - amount || str[i] <= 'z' && str[i] > 'z' - amount) // checks if character's will fall outside of alphabet ASCII numbers after encryption\n\
    //             {\n\
    //                 str[i] -= 26 - amount; // equation to ensure encryption stays in the lowercase of uppercase alphabet range respectively\n\
    //             }\n\
    //             else // else condition\n\
    //             {\n\
    //                 str[i] += amount; // equation for simple encryption using user's argument\n\
    //             }\n\
    //         }\n\
    //         i++; // increment i to check next character in while loop\n\
    //     }\n\
    //     printf('\\nThe encrypted str is: ‰s\\n', str); // print string after encryption\n\
    // }\n\
    \n\
    // #include <stdio.h> // input output\n\
    // #include <stdlib.h> // rand and srand functions\n\
    // #include <time.h> // for the random seed\n\
    \n\
    // // generate random number\n\
    // int rand(void);\n\
    // // function that runs the game loop\n\
    // void guessing();\n\
    // // max number of guesses\n\
    // int MAXNUMBER = 6;\n\
    \n\
    // /*\n\
    // * Main function in the program,\n\
    // * @params argc and argv passed\n\
    // * @return int (exit code)\n\
    // */\n\
    // int main(int argc, char *argv[])\n\
    // {\n\
    //   srand(time(0));    // create a random seed\n\
    //   char answer = 'y'; // initialize the answer string\n\
    \n\
    //   do\n\
    //   {                                                // continue loop until while condition is false\n\
    //     guessing();                                    // run the guessing function\n\
    //     printf('Would you like to play again? y/n\\n'); // print to console\n\
    //     scanf('‰s', &answer);                          // get the answer\n\
    //   } while (answer == 'y');                         // continue loop while answer is 'y'\n\
    \n\
    //   return 0; // exit program\n\
    // }\n\
    \n\
    // /* function to initiate the guessing game */\n\
    // void guessing()\n\
    // {\n\
    //   int count = 0;              // initialize the count of the amount of guesses\n\
    //   int num = rand() ‰100 + 1; // get a random number from the random number generator\n\
    //   char input;                 // create variable to store user input\n\
    //   int guess;                  // create variable to store the guess\n\
    \n\
    //   do\n\
    //   {\n\
    //     printf('‰s', 'Guess the number.\\n'); // print to console\n\
    //     if (scanf('‰d', &guess) == 1 && guess >= 1 && guess <= 100)\n\
    //     {          // check whether input is valid\n\
    //       count++; // increment count of guesses\n\
    //       if (guess == num)\n\
    //       { // check whether user guess is equal to the random number\n\
    //         printf('‰s ‰d ‰s', 'Well done! You guessed', count,\
    //               'times to get the correct answer.\\n'); // print success to console\n\
    //         break;                                        // end\n\
    //       }\n\
    //       else if (guess < num)\n\
    //       {                                                                                             // if guess is lower than the random number\n\
    //         printf('‰s ‰d ‰s', 'Your guess is too low. You have', MAXNUMBER - count, 'guesses left\\n'); // print to console\n\
    //       }\n\
    //       else                                                                                           // if guess is higher than the random number\n\
    //         printf('‰s ‰d ‰s', 'Your guess is too high. You have', MAXNUMBER - count, 'guesses left\\n'); // print to console\n\
    //     }\n\
    //     else\n\
    //     {                   // if input is not valid\n\
    //       scanf('﹪*[^\n]'); // discard that line up to the newline\n\
    //       printf(\n\
    //           'Wrong format. Only numbers between 1-100 (inclusive) accepted.\\n'); // print helpful advice to console\n\
    //       // continue;\n\
    //     }\n\
    //   } while (guess != num && count < MAXNUMBER); // loop until guess is equal to random number\n\
    //   if (count == MAXNUMBER)\n\
    //   {\n\
    //     printf('You ran out of guesses! Try again\\n\\n'); //\n\
    //   }\n\
    // }\n\
    \n\
    // #include <stdio.h> // Header for standard input/output functions\n\
    // #include <stdlib.h> // Header for standard library functions\n\
    // #include <time.h> // Header for date/time operations\n\
    \n\
    // #define MAX 100      // defines the maximum number of the values in the table\n\
    // #define MAXNUMBER 20 // defines the maximum value of random numbers\n\
    \n\
    // // function declarations\n\
    // void create_random(int *tab);\n\
    // // get the frequency of each number\n\
    // void count_frequency(int *tab, int *freq);\n\
    // // draw a historgram representing the num of occurences of each number\n\
    // void draw_histogram(int *freq);\n\
    // // get a random int from 0-MAXNUMBER\n\
    // int rand_int();\n\
    // /**\n\
    // * main function of program. entry point for the program which calls the other\n\
    // * functions.\n\
    // * @return int which is the exit code\n\
    // */\n\
    // int main(void) {\n\
    //   // random seed init\n\
    //   srand(time(0));\n\
    //   // initialize a table to fill with random numbers\n\
    //   int table[MAX];\n\
    //   // initialize a frequency array to count the occurances within table\n\
    //   int frequency[MAXNUMBER];\n\
    //   create_random(table);\n\
    //   // counts the frequency of occurances of each number in table\n\
    //   count_frequency(table, frequency);\n\
    //   // draw a histogram to represent the frequency of the numbers within table\n\
    //   draw_histogram(frequency);\n\
    //   // exit code\n\
    //   return 0;\n\
    // }\n\
    \n\
    // int rand_int() {\n\
    //   // return a random integer between the min and max value\n\
    //   return (rand() ﹪(MAXNUMBER + 1));\n\
    // }\n\
    \n\
    // /* method to fill the table with random numbers */\n\
    // void create_random(int *tab) {\n\
    //   for (int i = 0; i < MAX;\n\
    //       i++) { // loop according to the MAX amount specified in the program\n\
    //     tab[i] = rand_int(); // set the number to a random value using the rand_int() function\n\
    //   }\n\
    // }\n\
    \n\
    // /* method to count the frequency of occurrences\n\
    // of each number in the table of random numbers */\n\
    // void count_frequency(int *tab, int *freq) {\n\
    //   for (int i = 0; i < MAXNUMBER; i++) { // loop over each number in the frequency table\n\
    //     freq[i] = 0; // initialise the frequency to zero\n\
    //   }\n\
    //   for (int i = 0; i < MAX; i++) { // loop over each number in the table of\n\
    //                                   // random numbers to increment the frequency\n\
    //     int val = tab[i];             // find the value of the number\n\
    //     freq[val]++;                  // increment frequency of the number\n\
    //   }\n\
    // }\n\
    \n\
    // /* method to create the histogram that will be displayed as\n\
    // output in the console showing each number and its occurrence. */\n\
    // void draw_histogram(int *freq) {\n\
    //   for (int i = 0; i < MAXNUMBER;\n\
    //       i++) { // loop through each number that could occur according to the\n\
    //               // MAXNUMBER value set in the program\n\
    //     if (freq[i] != 0) { // check if the number occurs in the table of random\n\
    //                         // numbers, if not, continue to next number\n\
    //       printf('‰d ', i); // print the number\n\
    //       for (int j = 0; j < freq[i]; j++) { // for each occurrence of the number\n\
    //         printf('x');                      // print the number's occurrence\n\
    //       }\n\
    //       printf('\\n'); // next line\n\
    //     }\n\
    //   }\n\
    // }\n\
    \n\
    // #include <stdlib.h> // for using atoi\n\
    // #include <stdio.h>  // to print\n\
    \n\
    // typedef unsigned char byte;\n\
    \n\
    // /* function declaration */\n\
    // void print_byte_as_bits(char val);\n\
    // int check_input(char *, int);\n\
    \n\
    // /* main function */\n\
    // int main(int argc, char const *argv[])\n\
    // {\n\
    //   if (argc != 6) // if there are too few arguments\n\
    //   {\n\
    //     printf('Not enough arguments passed. You should pass 5 arguments with a space between each one. For example: '1 1 1 1 1'.\n'); // error message\n\
    //     return 1; // exit the program\n\
    //   }\n\
    //   for (int i = 1; i < 6; i++) // for each argument input\n\
    //   {\n\
    //     if (!check_input(argv[i], i)) // calls function to check the user input\n\
    //     {\n\
    //       printf('There was an error with your arguments. The minimum value for each argument is 0, and the maximum value is: 1, 4, 3, 1, 1, respectively.'); // error message\n\
    //       exit(0);                                                                                                                                            // exit code\n\
    //     }\n\
    //   }\n\
    \n\
    //   byte value = 0;              // set a byte variable and initialise it to 0\n\
    //   value += atoi(argv[1]) << 7; // bitshift the first argument and create an integer to represent the 7th binary char\n\
    //   value += atoi(argv[2]) << 4; // bitshift the second argument and create an integer to represent the 4th-6th binary chars\n\
    //   value += atoi(argv[3]) << 2; // bitshift the third argument and create an integer to represent the 3rd binary char\n\
    //   value += atoi(argv[4]) << 1; // bitshift the second argument and create an integer to represent the 2nd binary char\n\
    //   value += atoi(argv[5]);      // create an integer to represent the 1st binary char\n\
    //   printf('Hex: ‰x\\n', value);  // print the value which will be the hex representation of the input\n\
    //   return 0;                    // exit program\n\
    // }\n\
    \n\
    // /*function to check if input is valid*/\n\
    // int check_input(char *input, int current)\n\
    // {\n\
    //   int value = atoi(input);           // first get the int value of the input\n\
    //   if (value == 0 && input[0] != '0') // if the input is the char 0 it is valid otherwise if atoi returns a 0 it wasnt a valid input\n\
    //   {\n\
    //     return 0; // return not valid\n\
    //   }\n\
    \n\
    //   if (current == 1 || current == 4 || current == 5) // if it's the 1st, 4th, or 5th argument\n\
    //   {\n\
    //     if (value == 1 || value == 0) // value must be 0 or 1\n\
    //     {\n\
    //       return 1; // return success\n\
    //     }\n\
    //   }\n\
    //   else if (current == 2) // if it's the 2nd argument\n\
    //   {\n\
    //     if (value >= 0 && value <= 4) // if the value is between 0 and 7\n\
    //     {\n\
    //       return 1; // return success\n\
    //     }\n\
    //   }\n\
    //   else if (value >= 0 && value <= 3) // if it's the 3rd argument and the value is between 0 and 3\n\
    //   {\n\
    //     return 1; // return success\n\
    //   }\n\
    //   return 0; // exit code\n\
    // }\n\
    \n\
    // #include <stdlib.h> // strtol\n\
    // #include <stdio.h>  // printf\n\
    // #include <string.h> // strlen\n\
    \n\
    // // byte type declaration unsigned char = 8 bits\n\
    // typedef unsigned char byte;\n\
    \n\
    // // function declaration\n\
    // void show_results(byte val);\n\
    \n\
    // // Main function\n\
    // int main(int argc, char *argv[])\n\
    // {\n\
    //     if (argc != 2)            // the program should only accept 1 user provided argument, otherwise exit the program with an error code\n\
    //         return 1;             // error exit code\n\
    //     if (strlen(argv[1]) == 2) // if the stringlength is 2 characters\n\
    //     {\n\
    //         char one = argv[1][0]; // set a char variable to the first character of the string\n\
    //         char two = argv[1][1]; // set a char variable to the second character of the string\n\
    \n\
    //         // if check to see whether input is valid hexadecimal by checking for letters between a and f OR A and F OR 0 and 9\n\
    //         if (!(((one <= 'f' && one >= 'a') && (two <= 'f' && two >= 'a')) || ((one <= 'F' && one >= 'A') && (two <= 'F' && two >= 'A')) || ((one <= '9' && one >= '0') && (two <= '9' && two >= '0'))))\n\
    //         {\n\
    //             printf('Not a valid hexadecimal number\\n'); // error message\n\
    //             return (0); // exit the program\n\
    //         }\n\
    //     }\n\
    //     else if (strlen(argv[1]) > 2) // if the stringlength is more than 2 characters\n\
    //     {\n\
    //         printf('Please enter a hexadecimal with a max of 2 characters\\n'); // error message\n\
    //         return (1); // error exit code\n\
    //     }\n\
    \n\
    //     byte value = (int)strtol(argv[1], NULL, 16); // convert hex to decimal (in the form of a unsigned char byte)\n\
    //     if (strlen(argv[1]) == 1)                    // if the inut is one character\n\
    //     {\n\
    //         // if check to see if the decimal value is lower than the max/min allowed. Also checks when ther is a letter outside of range with the 3rd OR.\n\
    //         if (value > 203 || value < 0 || (value == 0 && argv[1] != 0))\n\
    //         {\n\
    //             printf('Invalid input.\\n'); // error message\n\
    //             return 0; // exit the program\n\
    //         }\n\
    //     }\n\
    //     show_results(value); // display the result\n\
    // }\n\
    \n\
    // // function to display the arguments that were provided to code\n\
    // void show_results(byte val)\n\
    // {\n\
    //     char bits[8];               // array to hold the bits of the dec value\n\
    //     for (int i = 0; i < 8; i++) // decrement so the order is correct\n\
    //     {\n\
    //         // shift based on the position in the byte, ternary for 1 or 0\n\
    //         // cast to char so the ternary works\n\
    //         bits[i] = (char)(val & (1 << i)) ? '1' : '0';\n\
    //     }\n\
    \n\
    //     int gear_pos = 0;           // init gear_pos\n\
    //     int key_pos = 0;            // init key_pos\n\
    //     int bin_rep_gear = 4;       // init bin_rep_gear\n\
    //     int bin_rep_key = 2;        // init bin_rep_key\n\
    //     for (int i = 6; i > 3; i--) // check the 0 _ _ _ 0000 positions in the byte\n\
    //     {\n\
    //         if (bits[i] == '1')           // check if this index is 1\n\
    //             gear_pos += bin_rep_gear; // if it is increment by bin_rep_gear\n\
    //         bin_rep_gear /= 2;            // increment the binary value to represent the current value\n\
    //         if (gear_pos > 4) // if the gear_position is higher than the alllowed maximum\n\
    //         {\n\
    //             printf('There was an error with your input. The gear_pos can have a maximum position of 4.\\n'); // error message\n\
    //             exit(0); // exit the program\n\
    //         }\n\
    //     }\n\
    //     for (int i = 3; i > 1; i--) // check the 0000 _ _ 00 positions in the byte\n\
    //     {\n\
    //         if (bits[i] == '1')         // check if this index is 1\n\
    //             key_pos += bin_rep_key; // if it is increment by bin_rep_key\n\
    //         bin_rep_key /= 2;           // increment the binary value to represent the current value\n\
    //         if (key_pos > 2) // if the key position is higher than the maximum alllowed\n\
    //         {\n\
    //             printf('There was an error with your input. The key_pos can have a maximum position of 2.\\n'); // error message\n\
    //             exit(0); // exit the program\n\
    //         }\n\
    //     }\n\
    //     printf('Name\\t\\tValue\\n');          // Print the headings for the output\n\
    //     printf('engine_on\\t‰c\\n', bits[7]); // print the engine's current state\n\
    //     printf('gear_pos\\t‰d\\n', gear_pos); // print the gear's current state\n\
    //     printf('key_pos\\t\\t‰d\\n', key_pos); // print the key's current state\n\
    //     printf('brake1\\t\\t‰c\\n', bits[1]);  // print the 1st brake's current state\n\
    //     printf('brake2\\t\\t‰c\\n', bits[0]);  // print the 2nd brake's current state\n\
    // }\n\
    \n\
    // #include <stdio.h>  // functions for standard input/output\n\
    // #include <stdlib.h> // for standard library functions (malloc, srand)\n\
    // #include <time.h>   // included for the random seed function\n\
    \n\
    // //#### Constants #####\n\
    // #define MAX 5\n\
    \n\
    // // ##### typedefs  ####\n\
    // typedef struct q // double linked list node\n\
    // {\n\
    //     int number;     // value in this node\n\
    //     struct q *next; // the next node in the list\n\
    //     struct q *prev; // the previous node in the list\n\
    // } REGTYPE;          // so you dont have to use struct q\n\
    \n\
    // // ##### Function declarations   #####\n\
    // REGTYPE *random_list(void);         // declaration of method\n\
    // REGTYPE *add_first(REGTYPE *, int); // declaration of method\n\
    // void *iterate_list(REGTYPE *, REGTYPE *); // declaration of method\n\
    // void *deallocate_list(REGTYPE *, REGTYPE *); // declaration of method\n\
    \n\
    // //###### Main program #######\n\
    // int main(int argc, char *argv[])\n\
    // {\n\
    //     REGTYPE *act_post, *head = NULL; // init the head and act_post pointers\n\
    \n\
    //     srand(time(0));               // random seed\n\
    //     head = random_list();         // call function to create initial list\n\
    //     iterate_list(act_post, head); // iterate over the list and print the items\n\
    \n\
    //     head = add_first(head, 1337); // Test adding the new item as the list's head\n\
    //     iterate_list(act_post, head); // iterate over the list and print the items\n\
    \n\
    //     head = add_first(head, 1234); // Test adding another item as the list's head\n\
    //     iterate_list(act_post, head); // iterate over the list and print the items\n\
    \n\
    //     deallocate_list(act_post, head); // free memory\n\
    //     return 0; // exit code\n\
    // }\n\
    \n\
    // // ==== End of main ======================================\n\
    // /* function to create a random list using the MAX amount of list items */\n\
    // REGTYPE *random_list(void)\n\
    // {\n\
    //     int nr;    // set a variable and initialise it to 0\n\
    //     int i = 0; // set a variable and initialise it to 0\n\
    \n\
    //     REGTYPE *top, *old, *item; // create three pointers to the struct type of REGTYPE\n\
    //     top = NULL;                // set top to null\n\
    //     while (i < MAX)            // while i is not equal to MAX\n\
    //     {\n\
    //         item = (REGTYPE *)malloc(sizeof(REGTYPE)); // create an item struct of type REGTYPE\n\
    //         item->number = rand() ‰100 + 1;           // set the item's number variable to a random integer\n\
    //         item->next = NULL;                         // initialise item's next variable to null\n\
    //         if (top == NULL)                           // the first run of the loop\n\
    //         {\n\
    //             item->prev = NULL; // initialise item's previous variable to null\n\
    //             top = item;        // set top to current item\n\
    //         }\n\
    //         else // for every run of the loop after the first item has been set to the top\n\
    //         {\n\
    //             old = top;                // the old pointer is set as the current top\n\
    //             while (old->next != NULL) // while there are next items in the list\n\
    //             {\n\
    //                 old = old->next; // set old to the next item in the list\n\
    //             }\n\
    //             item->prev = old; // set the current item's previous variable to the old item\n\
    //             old->next = item; // set the end of the list's next to the current item\n\
    //         }\n\
    //         i++; // increment i\n\
    //     }\n\
    //     return (top); // return the top of the list\n\
    // }\n\
    \n\
    // //==========================================================\n\
    // /* function to append an item to the top of the list */\n\
    // REGTYPE *add_first(REGTYPE *temp, int data)\n\
    // {\n\
    //     REGTYPE *item = (REGTYPE *)malloc(sizeof(REGTYPE)); // create a new struct of type REGTYPE\n\
    //     item->number = data; // set item's number variable to the data parameter (a random int)\n\
    //     temp->prev = item; // set temp's previous variable (head passed as parameter) to the current item\n\
    //     item->next = temp; // set item's next variable to the current head (parameter passed as temp)\n\
    //     return item; // return item which is now the list's head\n\
    // }\n\
    \n\
    // //==========================================================\n\
    // /* function to iterate over the list, print list items, and update the active position via pointer */\n\
    // void *iterate_list(REGTYPE *act_post, REGTYPE *head)\n\
    // {\n\
    //     int nr = 0;      // counter\n\
    //     act_post = head; // set the current position to head\n\
    \n\
    //     while (act_post != NULL)      // while the current position is not null\n\
    //     {\n\
    //         printf('\\n Post nr ‰d : ‰d', nr++, act_post->number); // print the nr and value of correspond node, and increment nr\n\
    //         act_post = act_post->next;                            // set the position to the next item in list\n\
    //     }\n\
    //     printf('\\n'); // clean up lines\n\
    // }\n\
    \n\
    // //==========================================================\n\
    // /* function to free the memory from allocated list items */\n\
    // void *deallocate_list(REGTYPE *act_post, REGTYPE *head)\n\
    // {\n\
    //     // reset the position of act_post to head since act_post is at the end of list after first while loop\n\
    //     while ((act_post = head) != NULL) //  while current position is not 0\n\
    //     {\n\
    //         head = act_post->next; // set to next position as you free each this is to make sure that you free everything\n\
    //         free(act_post);        // since the head is pointing to next we can free the previous head without losing the list\n\
    //     }\n\
    // }\n\
    \n\
    // #include <stdio.h>  // for input/output functions\n\
    // #include <stdlib.h> // for standard c functions\n\
    // #include <string.h> // for strlen & strcmp: string functions\n\
    \n\
    // #define FILE_NAME 'ex3.bin'\n\
    // typedef struct // identifier for the struct\n\
    // {\n\
    //   char firstname[20];   // first name chars with array size 20\n\
    //   char famname[20];     // family name chars with array size 20\n\
    //   char pers_number[13]; // personal # array size based on yyyymmddnnnnc\n\
    // } PERSON;               // typedef name\n\
    \n\
    // /* functions declaration */\n\
    // void menu();\n\
    // void new_db();\n\
    // void create();\n\
    // void search();\n\
    // void print_all();\n\
    // void print_person(PERSON);\n\
    \n\
    // /*\n\
    // * Main function in the program,\n\
    // * @params none\n\
    // * @return int (exit code)\n\
    // */\n\
    // int main(int argc, char const *argv[])\n\
    // {\n\
    //   while (1) // while loop to run the menu\n\
    //   {\n\
    //     menu(); // menu function\n\
    //   }\n\
    //   return 0; // exit code\n\
    // }\n\
    \n\
    // /* function to run the menu */\n\
    // void menu()\n\
    // {\n\
    //   printf( // print to console the following lines\n\
    //       '1. Create a new and delete the old file.\\n'\n\
    //       '2. Add a new person to the file.\\n'\n\
    //       '3. Search for a person in the file.\\n'\n\
    //       '4. Print out all in the file.\\n'\n\
    //       '5. Exit the program\\n');\n\
    //   printf('> ');\n\
    //   char choice = getchar(); // get a character from the input\n\
    //   getchar();               // handle the 'Enter' (\\n)\n\
    //   switch (choice)          // choice selections based on user input\n\
    //   {\n\
    //   case '1':                     // if user input is 1\n\
    //     new_db();                   // call new_db function\n\
    //     break;                      // terminate the loop\n\
    //   case '2':                     // if user input is 2\n\
    //     create();                   // call create function\n\
    //     break;                      // terminate the loop\n\
    //   case '3':                     // if user input is 3\n\
    //     search();                   // call the search function\n\
    //     break;                      // terminate the loop\n\
    //   case '4':                     // if user input is 4\n\
    //     print_all();                // call print_all function\n\
    //     break;                      // terminate loop\n\
    //   case '5':                     // if user input is 5\n\
    //     exit(0);                    // exit the program\n\
    //     break;                      // terminate loop\n\
    //   default:                      // if user input is not 1-5\n\
    //     printf('invalid choice\\n'); // prints to console\n\
    //     menu();                     // call menu function\n\
    //     break;                      // terminate loop\n\
    //   }\n\
    // }\n\
    \n\
    // /* function to create a database binary file */\n\
    // void new_db()\n\
    // {\n\
    //   FILE *fp;                                        // file pointer\n\
    //   fp = fopen(FILE_NAME, 'wb+');                    // to create an empty binary file for reading/writing\n\
    //   PERSON dummy = {'Jane', 'Doe', '199909091111'};  // mock data for one entry\n\
    //   fwrite(&dummy, sizeof(dummy), 1, fp);            // writes data to file\n\
    //   PERSON dummy2 = {'Jack', 'Doe', '199909091112'}; // mock data for a second entry\n\
    //   fwrite(&dummy2, sizeof(dummy2), 1, fp);          // writes data to file\n\
    //   fclose(fp);                                      // closes the file\n\
    // }\n\
    \n\
    // // /* function to create an entry in the db */\n\
    // void create()\n\
    // {\n\
    //   FILE *fp;                                                     // file struct and pointer\n\
    //   PERSON person = { NULL, NULL, NULL };                         // init person\n\
    //   fflush(stdin);                                                // discards unconsumed buffered data\n\
    //   fflush(stdout);                                               // discards output buffer\n\
    //   printf('What is the first name? ');                           // prinnts to console\n\
    //   fgets(person.firstname, sizeof(person.firstname), stdin);     // get the first name of the person from stdin\n\
    //   person.firstname[strlen(person.firstname) - 1] = '\\0';        // swap \n for \\0\n\
    //   printf('What is the last name? ');                            // prints to console\n\
    //   fgets(person.famname, sizeof(person.famname), stdin);         // get the last name of the person from stdin\n\
    //   person.famname[strlen(person.famname) - 1] = '\\0';            // swap \n for \\0\n\
    //   printf('What is the personnummer? ');                         // get the personal number of the person from stdin\n\
    //   fgets(person.pers_number, sizeof(person.pers_number), stdin); // prints to console\n\
    //   person.pers_number[strlen(person.pers_number) - 1] = '\\0';    // swap \n for \\0\n\
    //   print_person(person);                                         // Print the person struct\n\
    //   fp = fopen(FILE_NAME, 'rb');                                  // open file in read binary mode to check if file exists\n\
    //   if (fp == NULL) {                                             // check if file pointer is null\n\
    //     new_db();                                                   // create db if file is null\n\
    //     fp = fopen(FILE_NAME, 'ab');                                // open file in append binary mode\n\
    //   } else {                                                      // if file is not null\n\
    //     fclose(fp);                                                 // close the read mode\n\
    //     fp = fopen(FILE_NAME, 'ab');                                // open the file in append mode now that we know the file exists\n\
    //   }\n\
    //   fwrite(&person, sizeof(person), 1, fp);                       // write the person struct to the file\n\
    //   getchar();                                                    // to handle the 'Enter'\n\
    //   fclose(fp);                                                   // closes the file\n\
    // }\n\
    \n\
    // /* function closes the fileto print all persons from within the file */\n\
    // void print_all()\n\
    // {\n\
    //   FILE *fp;                                          // file pointer\n\
    //   PERSON person;                                     // person variable\n\
    //   fp = fopen(FILE_NAME, 'rb');                       // open the file in read binary mode\n\
    //   if (fp == NULL) {\n\
    //     new_db();\n\
    //     fp = fopen(FILE_NAME, 'rb');                                  // open file in append binary mode\n\
    //   }\n\
    //   while (fread(&person, sizeof(person), 1, fp) != 0) // while the file still has content print the person\n\
    //   {\n\
    //     print_person(person); // print the person struct\n\
    //   }\n\
    //   fclose(fp); // closes the file\n\
    // }\n\
    \n\
    // /* function to print a person from within the file */\n\
    // void print_person(PERSON person)\n\
    // {\n\
    //   printf('first name: ‰s\\n', person.firstname);        // prints person's firstname to console\n\
    //   printf('last name: ‰s\\n', person.famname);           // prints person's family name to console\n\
    //   printf('personal number: ‰s\\n', person.pers_number); // prints person's personal # to console\n\
    // }\n\
    \n\
    // /* function to search for a person from within the file */\n\
    // void search()\n\
    // {\n\
    //   FILE *fp;                                          // create file pointer\n\
    //   PERSON person;                                     // create a new struct of type PERSON\n\
    //   char searchterm[20];                               // create a characteer array\n\
    //   char ch = '\\0';                                    // create an end of line character placeholder\n\
    //   fp = fopen(FILE_NAME, 'rb');                       // set fp to the file we want to open which will read binary\n\
    //   if (fp == NULL) {\n\
    //     new_db();\n\
    //     fp = fopen(FILE_NAME, 'rb');                                  // open file in append binary mode\n\
    //   }\n\
    //   printf('1. Search by first name\\n');               // print to console\n\
    //   printf('2. Search by last name\\n');                // print toconsole\n\
    //   ch = getchar();                                    // set ch to the user's input\n\
    //   printf('What is the name: ');                      // print to console\n\
    //   scanf('‰s', searchterm);                           // set the searchterm to user's input\n\
    //   while (fread(&person, sizeof(person), 1, fp) != 0) // while there is a person in the file list\n\
    //   {\n\
    //     if (strcmp(person.firstname, searchterm) == 0 && ch == '1') // if the comparison between the user's searchterm is equal to the person's firstname\n\
    //     {\n\
    //       print_person(person); // call the print function\n\
    //     }\n\
    //     if (strcmp(person.famname, searchterm) == 0 && ch == '2') // if the comparison between the user's searchterm is equal to the person's lastname\n\
    //     {\n\
    //       print_person(person); // call the print function\n\
    //     }\n\
    //   }\n\
    //   getchar();  // handle the 'Enter' (\n) newline cha\n\
    //   fclose(fp); // closes the file\n\
    // }\n\
    // ========================================================================================================================= //\n\
    // checking chars\n\
    // ========================================================================================================================= //\n\
    // #include <ctype.h>\n\
    // #include <stdio.h>\n\
    // #include <stdlib.h>\n\
    // int main()\n\
    // {\n\
    //   // if 0 no if greater then 1 yes\n\
    //   printf('is hex: ‰d\\n', isxdigit('A') > 0);\n\
    //   printf('is alpha: ‰d\\n', isalpha('z') > 0);\n\
    //   printf('is digit: ‰d\\n', isdigit('1') > 0);\n\
    //   return 0;\n\
    // } \n\
    \n");
  }
  else if (strcmp("help", arg) == 0)
  {
    printf("\
    \n\
    Options:\n\
    - types\n\
    - parrallism\n\
    - concurrency\n\
    - amdahl\n\
    - threads\n\
    - libs\n\
    - input\n\
    - math\n\
    - bit\n\
    - pyramid\n\
    - leap\n\
    - str\n\
    - linkedlist\n\
    - misc\n\
    - help\n\
    \n");
  }
  else
  {
    printf("\
    \n\
    Options:\n\
    - types\n\
    - parrallism\n\
    - concurrency\n\
    - amdahl\n\
    - threads\n\
    - libs\n\
    - input\n\
    - math\n\
    - bit\n\
    - pyramid\n\
    - leap\n\
    - str\n\
    - linkedlist\n\
    - misc\n\
    - help\n\
    \n");
  }
  return 0;
}