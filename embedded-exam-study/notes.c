// ========================================================================================================================= //
// Data Type                  Memory (bytes)          Range                                Format Specifier
// ========================================================================================================================= //
// short int                  2                       -32,768 to 32,767                    %hd
// unsigned short int         2                       0 to 65,535                          %hu
// unsigned int               4                       0 to 4,294,967,295                   %u
// int                        4                      -2,147,483,648 to 2,147,483,647       %d
// long int                   4                      -2,147,483,648 to 2,147,483,647       %ld
// unsigned long int          4                       0 to 4,294,967,295                   %lu
// long long int              8                       -(2^63) to (2^63)-1                  %lld
// unsigned long long int     8                       0 to 18,446,744,073,709,551,615      %llu
// signed char                1                       -128 to 127                          %c
// unsigned char              1                       0 to 255                             %c
// float                      4                                                            %f
// double                     8                                                            %lf
// long double                16                                                           %Lf

// ========================================================================================================================= //
// Parrallism
// ========================================================================================================================= //
// Parallelism is related to an application where tasks are divided into smaller sub-tasks that are processed 
// seemingly simultaneously or parallel. It is used to increase the throughput and computational speed of 
// the system by using multiple processors. It enables single sequential CPUs to do lot of things “seemingly” simultaneously. 
// Parallelism leads to overlapping of central processing units and input-output tasks in one process with the central 
// processing unit and input-output tasks of another process. Whereas in concurrency the speed is increased by overlapping 
// the input-output activities of one process with CPU process of another process.
// ========================================================================================================================= //
// Concurrency
// ========================================================================================================================= //
// single core cpus can run multiple threads through the use of interrupts
// this allows for context switching between applications
//
// In a multithreaded process on a single processor, the processor can switch execution resources between threads,
// resulting in concurrent execution. Concurrency indicates that more than one thread is making progress,
// but the threads are not actually running simultaneously.

// Concurrency relates to an application that is processing more than one task at the same time. 
// Concurrency is an approach that is used for decreasing the response time of the system by using the single processing unit. 
// Concurrency is creates the illusion of parallelism, however actually the chunks of a task aren’t parallelly processed, 
// but inside the application, there are more than one task is being processed at a time. 
// It doesn’t fully end one task before it begins ensuing. 
// Concurrency is achieved through the interleaving operation of processes on the central processing unit(CPU) or 
// in other words by the context switching. that’s rationale it’s like parallel processing. 
// It increases the amount of work finished at a time. 
// ========================================================================================================================= //
// Amdahl's Law
// ========================================================================================================================= //
//
// After reducing the sequential part of her code to 20% and using 4 cores instead of 1 for the
// rest of the code, Maria’s program ran 3 times faster compared to the original code.
// check with Amdhal’s law... E.g. 1/(0.2+0.8/4)=2.5<3 ->so first sentence if false
//
// Identifies performance gains from adding additional cores to an application
// The application has both serial and parallel components
// S - is serial portion, N - is processing cores
//
// equation:
// speedup <= 1(S + (1-S / N))
// this means that if app is 75% parallel and 25% serial, moving from 1 to 2 cores results in speedup of 1.6 times
// 1(0.25 + (1-0.25 / 0.75)) -> 1(0.25 + (1/0.75)) -> 1(0.25 + 1.33) -> 1(1.58) -> 1.58 = rounded to 1.6
// As N approaches infinity, speedup approaches - 1 / S
// ========================================================================================================================= //
// Amdahl's Law # 2
// ========================================================================================================================= //
// Amdahl’s Law was named after Gene Amdahl, who presented it in 1967.
// In general terms, Amdahl’s Law states that in parallelization,
// if P is the proportion of a system or program that can be made parallel,
// and 1-P is the proportion that remains serial, then the maximum speedup S(N)
// that can be achieved using N processors is:
//
//                 S(N)=1/((1-P)+(P/N))
//
// As N grows the speedup tends to 1/(1-P).
//
// Speedup is limited by the total time needed for the sequential (serial) part of the program.
// For 10 hours of computing, if we can parallelize 9 hours of computing and 1 hour cannot be parallelized,
// then our maximum speedup is limited to 10 times as fast. If computers get faster the speedup itself stays the same.

// #include <stdio.h>
//
// // After reducing the sequential part of her code to 20% and using 4 cores instead of 1 for the
// // rest of the code, Maria’s program ran 3 times faster compared to the original code.
// // check with Amdhal’s law... E.g. 1/(0.2+0.8/4)=2.5<3 ->so first sentence if false

// float amdahl(float, int);

// int main()
// {
//     printf("%f\n", amdahl(0.8, 4));
//     return 0;
// }

// float amdahl(float parrallel, int cores)
// {
//   // S(N)= 1/ ( (1-P) + (P/N) )
//   return ( 1/(  (1-parrallel) + (parrallel/cores) ) );
// }
// ========================================================================================================================= //
// threads
// ========================================================================================================================= //
// Semaphore
// In computer science, a semaphore is a variable or abstract data type
// used to control access to a common resource by multiple threads
// and avoid critical section problems in a concurrent system such as a multitasking operating system.
// Semaphores are a type of synchronization primitives.
// A trivial semaphore is a plain variable that is changed (for example, incremented or decremented, or toggled)
// depending on programmer-defined conditions.

// ========================================================================================================================= //
// C Libraries
// ========================================================================================================================= //
// stdio.h -> input/output
// unistd.h -> POSIX operating system API (sleep)
// assert.h -> void assert(int expression) This is actually a macro and not a function, which can be used to add diagnostics in your C program.

// stdlib.h:
// ---------
// int atoi(const char *str)                -> Converts the string pointed to, by the argument str to an integer (type int).
// void *calloc(size_t nitems, size_t size) -> Allocates the requested memory and returns a pointer to it.
// void *malloc(size_t size)                -> Allocates the requested memory and returns a pointer to it.
// void *realloc(void *ptr, size_t size)    -> Attempts to resize the memory block pointed to by ptr that was previously allocated with a call to malloc or calloc.
// void free(void *ptr)                     -> Deallocates the memory previously allocated by a call to calloc, malloc, or realloc.
// void exit(int status)                    -> Causes the program to terminate normally.
// void srand(unsigned int seed)            -> This function seeds the random number generator used by the function rand.
// int rand(void)                           -> Returns a pseudo-random number in the range of 0 to RAND_MAX.

// void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) -> Performs a binary search.
// void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))  -> Sorts an array.
// int abs(int x)                           -> Returns the absolute value of x.

// math.h:
// ---------
// double exp(double x)                     -> Returns the value of e raised to the xth power.
// double log(double x)                     ->  Returns the natural logarithm (base-e logarithm) of x.
// double log10(double x)                   ->  Returns the common logarithm (base-10 logarithm) of x.
// double pow(double x, double y)           ->  Returns x raised to the power of y
// double sqrt(double x)                    ->  Returns the square root of x.
// double fabs(double x)                    ->  Returns the absolute value of x
// double fmod(double x, double y)          ->  Returns the remainder of x divided by y.

// string.h:
// ---------
// int memcmp(const void *str1, const void *str2, size_t n)     ->  Compares the first n bytes of str1 and str2.
// void *memcpy(void *dest, const void *src, size_t n)          ->  Copies n characters from src to dest.
// size_t strlen(const char *str)                               ->  Computes the length of the string str up to but not including the terminating null character.
// int strcmp(const char *str1, const char *str2)               ->  Compares the string pointed to, by str1 to the string pointed to by str2.
// int strncmp(const char *str1, const char *str2, size_t n)    ->  Compares at most the first n bytes of str1 and str2.
// char *strcpy(char *dest, const char *src)                    ->  Copies the string pointed to, by src to dest.
// char *strtok(char *str, const char *delim)                   ->  Breaks string str into a series of tokens separated by delim.

// ctype.h:
// ---------
// int isalnum()                        -> This function checks whether the passed character is alphanumeric.
// int isalpha(int c)                   -> This function checks whether the passed character is alphabetic.
// int isdigit(int c)                   -> This function checks whether the passed character is decimal digit.
// int islower(int c)                   -> This function checks whether the passed character is lowercase letter.
// int isspace(int c)                   -> This function checks whether the passed character is white-space.
// int isupper(int c)                   -> This function checks whether the passed character is an uppercase letter.
// int isxdigit(int c)                  -> This function checks whether the passed character is a hexadecimal digit.
// int tolower(int c)                   -> This function converts uppercase letters to lowercase.
// int toupper(int c)                   -> This function converts lowercase letters to uppercase.

// errno.h:
// ---------
// extern int errno   -> This is the macro set by system calls and some library functions in the event of an error to indicate what went wrong.

// pthread.h: (cc -lpthread file.c)
// ---------
// pthread_t pthread_self(void) used to get the thread id of the current thread.
// int pthread_detach(pthread_t thread) used to detach a thread. A detached thread does not require a thread to join on terminating. The resources of the thread are automatically released after terminating if the thread is detached.
// pthread_cond_t PTHREAD_COND_INITIALIZER
// pthread_mutex_t PTHREAD_MUTEX_INITIALIZER
// pthread_rwlock_t PTHREAD_RWLOCK_INITIALIZER

// int pthread_create(pthread_t *restrict, const pthread_attr_t *restrict, void *(*)(void*), void *restrict);
// ARGS:
// thread: pointer to an unsigned integer value that returns the thread id of the thread created.
// attr: pointer to a structure that is used to define thread attributes like detached state, scheduling policy, stack address, etc. Set to NULL for default thread attributes.
// start_routine: pointer to a subroutine that is executed by the thread. The return type and parameter type of the subroutine must be of type void *. The function has a single attribute but if multiple values need to be passed to the function, a struct must be used.
// arg: pointer to void that contains the arguments to the function defined in the earlier argument

// int pthread_join(pthread_t, void **);
// pthread_mutex_lock(pthread_mutex_t *);
// pthread_mutex_unlock(pthread_mutex_t *);
// pthread_exit(void *);
// ARGS:
// This method accepts a mandatory parameter retval
// which is the pointer to an integer that stores the return status of the thread terminated.
// The scope of this variable must be global so that any thread waiting to join this thread may read the return status.

// ========================================================================================================================= //
// C Reading input
// ========================================================================================================================= //
// char str1[5];
// if(fgets (str1, 5, stdin) != NULL) {
//   /* writing content to stdout */
//   printf("%s", str1);
// }
// fgets is safe (but does not convert)
// sscanf lets your converit the line you got with fgets

// ========================================================================================================================= //
// Math Functions
// ========================================================================================================================= //

// // check whether a num is prime or not
// int isPrime(int n)
// {
//   // return 1 for non-prime number
//   if (n == 0)
//     {
//       return 1;			// if the arg was 0 it is not prime
//     }
//   // for 2 to n/2 check if n modulo i == 0 (basically checking if divisible)
//   for (int i = 2; i <= n / 2; ++i)
//     {
//       // if n is divisible by i, then n is not prime
//       if (n % i == 0)
// 	{
// 	  // return 1 for not prime (was divisible)
// 	  return 1;
// 	}
//     }
//   return 0;			// passed all criteria it is prime
// }

// // recursive fibonacci
// int fib(int n)
// {
//   if (n <= 1) // base case
//   {
//     return n; // return 0 or 1 since those are what n<=1 will catch
//   }
//   return fib(n-2) + fib(n-1); // recursively take the last two numbers in the sequence and sum
// }
// // // memoization fib
// // //                           fib(5)
// // //                     /                \
// // //               fib(4)                fib(3)
// // //             /        \              /       \ 
// // //         fib(3)      fib(2)         fib(2)   fib(1)
// // //         /    \       /    \        /      \
// // //   fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
// // //   /     \
// // // fib(1) fib(0)
// int memo_fib(int n)
// {
//   /* Declare an array to store Fibonacci numbers. */
//   int f[n+2];   // 1 extra to handle case, n = 0
//   int i;
//   /* 0th and 1st number of the series are 0 and 1*/
//   f[0] = 0;
//   f[1] = 1;
//   for (i = 2; i <= n; i++)
//   {
//     /* Add the previous 2 numbers in the series
//       and store it */
//     f[i] = f[i-1] + f[i-2];
//   }
//   return f[n];
// }

// // power of a number
// int pow_of_num(int base, int expn)
// {
// if (expn != 0) // if we arnt 0 yet keep going
//   return (base * pow_of_num(base, expn-1)); // recursively call pow_of_num with expn being 1 less
// else
//   return 1; // once expn hits 0 return 1 (last call)
// }

// int factorial(int n)
// {
//   int i;
//   int base = 1;
//   if (n < 0)
//   {
//     base = 0;
//   }
//   else
//   {
//     for (i = 1; i <= n; ++i)
//     {
//       base *= i;
//     }
//     // printf("Factorial of %d = %l", n, base);
//   }
//   return base;
// }

// // factorial
// int recursive_fact(int n)
// {
// 	if(n==0)
// 	{
// 		return 1;
// 	}
// 	else
// 	{
// 		return n * recursive_fact(n-1);
// 	}
// }

// // FRACTIONS
// void add()
// {
// 	num = ((x1 * y2) + (y1 * x2));
// 	denom = (y1 * y2);
// }

// void subtract()
// {
// 	num = ((x1 * y2) - (y1 * x2));
// 	denom = (y1 * y2);
// }

// void multiply()
// {
// 	num = (x1 * x2);
// 	denom = (y1 * y2);
// }

// void divide()
// {
// 	num = (x1 * y2);
// 	denom = (y1 * x2);
// }

// Fraction add_fractions(Fraction a, Fraction b)
// {
//     Fraction x;
//     a.n *= b.d;
//     b.n *= a.d;

//     x.n = a.n + b.n;
//     x.d = a.d * b.d;

//     return x;
// }

// ========================================================================================================================= //
// Bitwise
// ========================================================================================================================= //
// Constant true is 1 and constant false is 0.

// int a = 60;	      /* 60 = 0011 1100 represents 60 in binary*/
// int b = 13;	      /* 13 = 0000 1101 */
// int c = 0;

// c = a & b;        /* 12 = 0000 1100 */
// c = a | b;        /* 61 = 0011 1101 */
// c = a ^ b;        /* 49 = 0011 0001 */
// c = ~a;           /*-61 = 1100 0011  :Invert all bits */

// // shift operators : zeros are shifted in to replace the discarded bits
// c = a << 2;       /* 240 = 1111 0000 : Shift left 2 bits*/
// c = a >> 2;       /* 15 = 1111 */
// c = a >>> 2;      /* 15 = 0000 1111 : Zero fill right shift*/


// | b1 | b2 | & | | | ^ |
// -----------------------
// | 1  | 0  | 1 | 1 | 0 |
// | 1  | 0  | 0 | 1 | 1 |
// | 0  | 1  | 0 | 1 | 1 |
// | 0  | 0  | 0 | 0 | 0 |

// | b | ~ |
// ---------
// | 1 | 0 |
// | 0 | 1 |

// void outputBinary(uint32_t x)
// {
//   char binary[35];
//   for (int i = 0; i < 35; i++)
//   {
//     if (i == 8 || i == 17 || i == 26)
//     { // loop over each number in the array of bits
//       binary[i] = '.';
//     }
//     else
//     {
//       // we shift the decimal down based on the ith digit 
//       // of the binary representation and check whether that digit should be a 1 or a 0
//       binary[i] = (char)(x >> i) & 1;
//     }
//   }
//   for (int i = 35 - 1; i >= 0; i--) // for each number in the array in reverse order
//   {
//     if (i == 8 || i == 17 || i == 26)
//     {
//       printf("%c", binary[i]);
//     }
//     else
//       printf("i:%d, %d ", i, binary[i]); // print every element
//   }
//   printf("\n"); // next line
// }

// #include <stdio.h>
// #include <stdlib.h>

// char *bin(unsigned int n)
// {
//   int len = sizeof(int) * 8 - 1;
//   char *buff = malloc(len);
//   for(int i = len; i >= 0; i--)
//   {
//     int bit = (n >> i & 1) ? 1 : 0;
//     sprintf(buff, "%s%d", buff, bit);
//   }
//   return buff;
// }

// int main()
// {
//   int value = 12345678;
//   char *b = bin(value);
//   printf("binary: %s", b);
//   free(b);
//   return 0;
// }

// typedef unsigned char byte;

// int convertdectobin(int number) {
//     int binary = 0;
//     int remainder = 1, i = 1;

//     // 0b0000 1101
//     while (number != 0) {
//         remainder = number % 2;
//         number /= 2;
//         binary += remainder * i;
//         i = i * 10;
//     }
//     printf("the binary value of %d is %d", number, binary);
//     return binary;
// }

// Decimal (Base 10)	Binary (Base 2)	Hexadecimal (Base 16)
//           0	        00000011	      0x00
//           1	        00000001	      0x01
//           2	        00000010	      0x02
//           3	        00000011	      0x03
//           4	        00000100	      0x04
//           5	        00000101	      0x05
//           6	        00000110	      0x06
//           7	        00000111	      0x07
//           8	        00001000	      0x08
//           9	        00001001	      0x09
//           10	      00001010	      0x0A
//           11	      00001011	      0x0B
//           12	      00001100	      0x0C
//           13	      00001101	      0x0D
//           14	      00001110	      0x0E
//           15	      00001111	      0x0F

// // To convert a hexadecimal number into decimal, we have to calculate the sum of the powers of 16 of the number.
// // Example 1.11
// // Convert hexadecimal number 2AC base(16) into decimal.
// // Solution 1.11
// // Calculating the sum of the powers of 16 of the number:
// // 2AC base(16) = 2 × 16^2 + 10 × 16^1 + 12 × 160 = 512 + 160 + 12 = 684
// // The required decimal number is 684 base(10).

// // Example 1.12
// // Convert hexadecimal number EE base(16) into decimal.
// // Solution 1.12
// // Calculating the sum of the powers of 16 of the number:
// // EE base(16)= 14 × 16^1 + 14 × 16^0 = 224 + 14 = 238
// // The required decimal number is 238 base(10).
// void to_bin(byte b) {
//   int binary[8];
//   for (int n = 0; n < 8; n++)
//   {
//     /*
//       bit a 	bit b 	a & b (a AND b)
//       0       &	0     =	0
//       0       &	1     =	0
//       1       &	0     =	0
//       1       &	1     =	1

//       64   8,4
//       0100 1100 - 76 & 0000 0001 = 0000 0000
//       >> 0
//       [0]
//       0010 0110 - 38 & 0000 0001 = 0000 0000
//       >> 1
//       [0,0]
//       0001 0011 - 19 & 0000 0001 = 1 0000 0001
//       >> 2
//       0000 1001 - 9 & 0000 0001 = 1 0000 0001
//       >> 3
//       0000 0100 - 4 & 0000 0001 = 0 0000 0000
//       >> 4
//       0000 0010 - 2 & 0000 0001 = 0 0000 0000
//       >> 5
//       0000 0001 - 1 & 0000 0001 = 1 0000 0001
//       >> 6
//       0000 0000 - 0 & 0000 0001 = 0 0000 0000

//     */
//     binary[7 - n] = (b >> n) & 1;
//   }
//   // for (int n = 0; n < 8; n++)
//   // {
//   //   printf("%d", binary[n]);
//   // }
//   // printf("\n");
// }

// //                               A   B   C   D   E       F
// // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, and 15

// // HEX FUNCTIONS
// function toHex(d) {
//   var r = d % 16;
//   if (d - r == 0) {
//     return toChar(r);
//   }
//   return toHex((d - r) / 16) + toChar(r);
// }

// function toChar(n) {
//   const alpha = "0123456789ABCDEF";
//   return alpha.charAt(n);
// }
// void to_hex(byte b)
// {
//   printf("0x%X", b);
// }

// void trailing_zeros(byte b)
// {
//   int binary[8];
//   for (int n = 0; n < 8; n++)
//   {
//     binary[7 - n] = (b >> n) & 1;
//   }
//   printf("Binary Representation: ");
//   for (int n = 0; n < 8; n++)
//   {
//     printf("%d", binary[n]);
//   }
//   printf("\n");
//   int i = 0;
//   for (int n = 0; n < 8; n++)
//   {
//     if (((b >> n) & 1) == 0)
//     {
//     i++;
//     }
//     else
//     {
//       break;
//     }
//   }
//   printf("Trailing Zeros: %d", i);
// }

// int checkOdd(int n)
// {
//   // second version
//   // n&1 is 1, then odd, else even
//   return (!(n & 1));
// }
// // Returns true if n is even, else odd
// // X 	Y 	X^Y
// // 0 	0 	0
// // 0 	1 	1
// // 1 	0 	1
// // 1 	1 	0
// int checkEven(int n)
// {
//     // n^1 is n+1, then even, else odd
//     // ex:
//     // 10 - 0000 1010 ^ 0000 0001 = 0000 1011 (11)
//     // 10+1 = 11
//     // equal == even

//     // ex2:
//     // 9 - 0000 1001 ^ 0000 0001 = 0000 1000 (8)
//     // 9 + 1 = 10
//     // not equal == odd

//     // ex3:
//     // 9 - 1000 0000 ^ 0000 0001 = 1000 0001 (129)
//     // 128 + 1 = 129
//     // equal == even
//     if (n ^ 1 == n + 1)
//     {
//         return 1; // true
//     }
//     else
//     {
//         return 0; // false
//     }
// }

// void count_one_n_zero(byte b)
// {
//   int binary[8];
//   for (int n = 0; n < 8; n++)
//   {
//     binary[7 - n] = (b >> n) & 1;
//   }
//   printf("Binary Representation: ");
//   for (int n = 0; n < 8; n++)
//   {
//     printf("%d", binary[n]);
//   }
//   printf("\n");
//   int one = 0;
//   int zero = 0;
//   for (int n = 0; n < 8; n++)
//   {
//     if (((b >> n) & 1) == 0)
//     {
//     zero++;
//     }
//     else
//     {
//       one++;
//     }
//   }
//   printf("Number of 1s: %d\n", one);
//   printf("Number of 0s: %d\n", zero);
// }

// void highest_order_bit(byte b)
// {
//   int binary[8];
//   for (int n = 0; n < 8; n++)
//   {
//     binary[7 - n] = (b >> n) & 1;
//   }
//   printf("Binary Representation: ");
//   for (int n = 0; n < 8; n++)
//   {
//     printf("%d", binary[n]);
//   }
//   printf("\n");
//   int i = 7;
//   for (int n = 1; n < 9; n++)
//   {
//     if (binary[n-1] == 1)
//     {
//       i = n;
//       break;
//     }
//   }
//   printf("Highest Order Bit: %d\n", i);
// }

// #include <stdio.h>

// void highest(int);
// int main()
// {
//   int input;
//   printf("What's the number: ");
//   scanf("%d", &input);
//   highest(input);
//   return 0;
// }

// void highest(int input)
// {
//   int highest;
//   for (int i = 0; i < 8; i++)
//   {
//     if ((input >> i) & 1)
//     {
//       highest = i;
//     }
//   }
//   printf("highest: %d", highest);
//   printf("\n0 : %d", (7 >> 0) & 1);
//   printf("\n1 : %d", (7 >> 1) & 1);
//   printf("\n2 : %d", (7 >> 2) & 1);
//   printf("\n3 : %d", (7 >> 3) & 1);
//   printf("\n4 : %d", (7 >> 4) & 1);
// }

// ========================================================================================================================= //
// Thread Function
// ========================================================================================================================= //

// #include <pthread.h> // thread lib
// #include <stdlib.h> // standard lib for malloc
// #include <stdio.h> // for printf and sprintf
// #include <string.h> // for strcmp

// #include "common.h" // common header file

// // function declarations
// void *worker(void *);

// // mutex init (to lock and unlock threads)
// pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
// int completed = 0; // number of completed tasks
// int n_args;        // number of provided args

// // main function
// int thread_prime(int argc, char *argv[])
// {
//   n_args = argc - 1;         // args -1 accounting for argv[0] being the file name
//   char *tasks[n_args];       // init results of tasks
//   pthread_t threads[n_args]; // array of threads corresponding to argc-1
//   int th_code;               // thread return code

//   // loop through and create the threads
//   for (int i = 1; i < argc; i++)
//   {
//     // create thread
//     th_code = pthread_create(&threads[i], NULL, worker, (void *)argv[i]);
//     if (th_code < 0) // check if error
//     {
//       // print err and code if unable to make thread
//       printf("Error: unable to create thread, %d\n", th_code);
//       // exit with error code 1
//       exit(1);
//     }
//   }
//   // loop through and join the threads
//   for (int i = 1; i < argc; i++)
//   {

//     void *return_val; // return value holder
//     // join thread
//     th_code = pthread_join(threads[i], &return_val);
//     if (th_code < 0) // check if error
//     {
//       // print err and code if unable to join thread
//       printf("Error: unable to create thread, %d\n", th_code);
//       // exit with error code 1
//       exit(1);
//     }

//     char *str = malloc(100);
//     sprintf(str, "%d - %s\n", atoi(argv[i]), (char *)return_val);
//     tasks[i] = str;
//   }
//   int i; // declare i
//   // loop through and print the results
//   for (i = 0; i <= n_args; i++)
//   {
//     printf("%s", tasks[i]); // print result
//   }
//   pthread_exit(NULL); // exit main thread
// }

// // threads job function
// void *worker(void *argument)
// {
//   pthread_mutex_lock(&lock);                   // lock the thread

//   char *return_val = malloc(sizeof(argument)); // allocate space for return_value
//   char *arg;                                   // char pointer for argument (still void pointer)
//   arg = (char *)argument;                      // cast void pointer to char * so we can access arg
//   int v = atoi(arg);                           // change string to int
//   if (isPrime(v) == 0)                         // if the result of isPrime is 0 its prime
//   {
//     strcpy(return_val, "Prime"); // put Prime in return_val
//   }
//   else // if the result of isPrime is 1 its not prime
//   {
//     strcpy(return_val, "Not Prime"); // put Not Prime in return_val
//   }
//   completed++; // incremented completed tasks
//   printf("%d out of %d numbers checked\n", completed, n_args);
//   pthread_mutex_unlock(&lock); // unlock the thread
//   pthread_exit(return_val);    // close thread
// }

// /*
// Question 3: Multithreaded elevator – 8 points
// Create a multithreaded elevator program. The main thread should be responsible for the interaction
// between the user and the elevator. The child thread should control the elevator’s movement.
// The elevator should move between 0 and MAX floors (MAX is defined by you, should be between 10
// and 20). The travel time between each floor is 1 second. When the elevator reaches the desired
// floor, a message is printed on the console. When the elevator moves between the floors, a message
// with the elevator’s position should be printed to the console when passing a floor and once in￾between every floor.
// The user can choose the floor where he/she wants to travel only when the elevator is waiting at one
// of the floors. When the user chooses a new floor while the elevator is in motion (moving to the
// destination floor), an error message should be printed.
// The user can always choose to print the status of the elevator. The output of the status should be:
// waiting_for_user or moving. */
// #include <stdio.h>
// #include <pthread.h>
// #include <unistd.h>
// #include <stdlib.h> //header imported to use the random function and malloc
// #include <time.h>   //header imported to use the random function

// #define MAX 20

// void *elevator(void *param);
// void *movement(void *);
// int acquireFloor(int min, int m);
// void clear_stdin();

// pthread_mutex_t movingSem = PTHREAD_MUTEX_INITIALIZER;
// int currentFloor = 0;
// int destination = 0;
// int moving = 0;

// int main()
// {
//   pthread_t thread;
//   if (pthread_create(&thread, NULL, movement, NULL))
//   {
//     printf("error creating thread\n");
//     return -1;
//   }

//   printf("-1 : print status \n 0-%d: to select a floor\n\n", MAX);

//   while (1)
//   {
//     int input = acquireFloor(-1, MAX); // prints user prompt for input to console

//     pthread_mutex_lock(&movingSem);
//     if (input == -1)
//     {
//       if (moving)
//       {
//         printf("status: Moving");
//       }
//       else
//         printf("status: waiting for user input");
//     }
//     else
//     {
//       if (moving == 1)
//       {
//         printf("the elevator is already moving");
//       }
//       else
//       {
//         moving = 1;
//         destination = input;
//       }
//     }
//     pthread_mutex_unlock(&movingSem);
//   }
//   pthread_join(thread, NULL);
// }

// void *movement(void *param)
// {
//   while (1)
//   {
//     pthread_mutex_lock(&movingSem);
//     if (moving)
//     {
//       printf("\nCurrent floor:%d", currentFloor);
//       if (destination > currentFloor)
//       {
//         currentFloor++;
//       }
//       else if (destination < currentFloor)
//       {
//         currentFloor--;
//       }
//       else
//       {
//         printf("Arrived\n");
//         moving = 0;
//       }
//     }
//     pthread_mutex_unlock(&movingSem);
//     sleep(1);
//   }

//   pthread_exit(NULL);
// }

// // the following function is from my group (2), IT WAS ALSO ORIGINALLY WRITTEN BY ME IN ONE OF THE LABS (one of the first labs, i don't remember which).
// // what it does it's just safely acquire a value between min and max, if this is considered plagmarism, a scanf does the same as this function it's does not check the values though
// int acquireFloor(int min, int m)
// {

//   int inputVal; // acquired val

//   char endLine;       // to check if the value insered is actually an integer
//   int wrongInput = 0; // a 'boolean' value to keep track of the (wrong) user input

//   do
//   {
//     // the input is not yet wrong
//     wrongInput = 0;
//     // asking the user to insert a value

//     // acquiring the user answer inputVal, and also acquiring a new line character to make sure an integer is insered
//     if (scanf("%d%c", &inputVal, &endLine) != 2 || endLine != '\n')
//     {
//       // clean the input buffer after reading the input
//       clear_stdin();
//       // printing an error message to the user
//       perror("\n**ERROR: unexpected value in input**\n");
//       // the value insered is not correct, so wrongInput=1;
//       wrongInput = 1;
//     }

//     // the user is asked to insert a coordinate value untill it's a value between min and max (and it's a number, the last condition in the do-while guard checks this)
//   } while ((inputVal > m || inputVal < min) || wrongInput == 1);

//   // returning the value read
//   return inputVal;
// }
// // to clear the stdin buffer since fflush on unix doesn't work
// void clear_stdin()
// {
//   //'moving' forward the pointer related with the stdin buffer, until \n
//   while (getchar() != '\n')
//   {
//     ;
//   }
// }

// ========================================================================================================================= //
// Pyramid Function
// ========================================================================================================================= //

// void print_spaces(int n)
// {
//   for (int i = 0; i<n; i++)
//   {
//     printf(" ");
//   }
// }

// void print_row(char c, int n)
// {
//   printf(" %c", c);
//   print_spaces(n);
//   printf(" %c", c);
// }

// void pyramid(char *str, int len)
// {
//   printf("len: %d\nstring: %s\n", len, str);
//   print_spaces(len*2);
//   printf(" %c\n", str[0]);
//   for (int y = 1, space = 2; y<len-1; y++, space+=4)
//   {
//     print_spaces((len-y)*2);
//     char ch = (char) str[y];
//     print_row(ch, space);
//     printf("\n");
//   }
//   printf(" ");
//   for (int i = len; i >= 0; i--) {
//     printf(" %c", str[i]);
//   }
//   for (int i = 1; i < len; i++) {
//     printf(" %c", str[i]);
//   }
// }

// // ========================================================================================================================= //
// // Read Input Function
// // ========================================================================================================================= //

// #include <stdio.h>

// void getInputToInt()
// {
//   char line[256];
//   int i;
//   if (fgets(line, sizeof(line), stdin)) {
//     if (1 == sscanf(line, "%d", &i)) {
//       /* i can be safely used */
//       printf("%d", i);
//     }
//   }
// }

// // still better to use fgets
// #define LINE 80
// int read_input()
// {
//   char buffer[LINE+1];
//   int i;
//   int ch;

//   printf( "Please enter string\n" );

//   /* Keep reading until either:
//     1. the length of LINE is exceeded  or
//     2. the input character is EOF  or
//     3. the input character is a new-line character
//   */

//   for ( i = 0; ( i  < LINE ) && (( ch = getchar()) != EOF) && ( ch !='\n' ); ++i )
//   {
//     buffer[i] = ch;
//   }

//   buffer[i] = '\0';  /* a string should always end with '\0' ! */
//   printf( "The string is %s\n", buffer );
//   return 0;
// }

// int main( )
// {
//   char c;
//   int i,l;

//   fprintf(stdout, "Enter the string length: ");
//   fscanf(stdin,"%d", &l);
//   fprintf(stdout, "Enter a value :");

//   for (i=0; i<=l; i++)
//   {
//     c=getc(stdin);
//     putc(c,stdout);
//   }
//   fprintf(stdout, "\n");
//   return 0;
// }

// // ========================================================================================================================= //
// // Leap Year Function
// // ========================================================================================================================= //

// // January – 31 days
// // February – 28 days in a common year and 29 days in leap years
// // March – 31 days
// // April – 30 days
// // May – 31 days
// // June – 30 days
// // July – 31 days
// // August – 31 days
// // September – 30 days
// // October – 31 days
// // November – 30 days
// // December – 31 days

// #include <stdio.h>

// void day_in_year(int m, int d, int y)
// {
//   int leapDay;
//   if (y % 100) {
//     // not a century
//     leapDay = ((y % 4) == 0 ? 1 : 0);
//   }
//   else
//   {
//     // century
//     leapDay = ((y % 400) == 0 ? 1 : 0);
//   }
//   char *isLeap = leapDay == 1 ? "yes" : "no";
//   int months[12] = {31, 28+leapDay, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//   months[m-1] = d;
//   int days = 0;
//   for (int i = 0; i<m; i++)
//   {
//     days += months[i];
//   }
//   printf("Leap Year: %s\nDay: %d", isLeap, days);
// }

// ========================================================================================================================= //
// Sum Pointer Function
// ========================================================================================================================= //

// #include <stdio.h>

// void sum_ptr(int *a, int *b)
// {
//   printf("%d", *a + *b);
// }

// ========================================================================================================================= //
// String Functions
// ========================================================================================================================= //

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // swaps where two ptrs point (basically swaps values)
// // standard swap function (applied to ptrs)
// void shift_ch(char *pos1, char *pos2)
// {
//     char tmp; // temp char while we swap ptrs
//     tmp = *pos1; // set them to value pos1 points at
//     *pos1 = *pos2; // set pos1 pointer to pos2 pointer (bothing point at pos2's value)
//     *pos2 = tmp; // point the pos2 pointer at the tmp (old value pos1 pointed at)
// }

// // Function to print permutations of string
// //                String,    first idx, last idx
// void _permute_str(char *str, int first, int last)
// {
//   int i = first -1; // declaring variable i and setting to first pos -1 (to account for ++ in while loop on first iteration)
//   if (first == last) // checking for base case
//   {
//     printf("%s ", str); // print a permutation (once first == last, meaning we got base case and start popping off stack)
//   }
//   else // not the base case
//   {
//     while(i++<last)
//     {
//       shift_ch((str+first), (str+i)); // swap two chars
//       _permute_str(str, first+1, last); // recursively permutate with the starting shift from the next char
//       shift_ch((str+first), (str+i)); // undo the changes that were made to the string
//     }
//   }
// }

// void permute_str(char *str, int len)
// {
//   printf("The permutations of the string are:\n");
//   _permute_str(str, 0, len-1);
// }

// void joinstr()
// {
//   char *str1 = "I love";
//   char *str2 = "DIT632";
//   char *full_str = malloc(12);
//   sprintf(full_str, "%s %s", str1, str2);
//   printf("%s", full_str);
//   printf("\n");
//   free(full_str);
// }

// int isVowel(char ch)
// {
//   // upercase check for vowels
//   return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
//   // lowercase check for vowels
//           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
// }

// void count_vowels_and_consonants(char *str)
// {
//   int vowels = 0;
//   int consonants = 0;
//   while(*str != '\0')
//   {
//     if (isVowel(*str))
//     {
//       vowels++;
//     }
//     else
//     {
//       consonants++;
//     }
//     str++;
//   }
//   printf("Number of vowels: %d\n", vowels);
//   printf("Number of consonants: %d", consonants);
// }

// void grades()
// {
//   int input[5] = {0};
//   int n = 5;
//   while(n-->0)
//   {
//     char line[256];
//     if (fgets(line, sizeof(line), stdin)) {
//       sscanf(line, "%d", &input[n]);
//     }
//   }
//   float sum = 0;
//   for (int i = 0; i < 5; i++)
//   {
//     sum+=input[i];
//   }
//   sum /= 5.0;
//   printf("Percentage: %.2f\n", sum);
//   char mark;
//   if (sum > 90.0) {
//     mark = 'A';
//   }
//   else if (sum > 80.0)
//   {
//     mark = 'B';
//   }
//   else if (sum > 70.0)
//   {
//     mark = 'C';
//   }
//   else if (sum > 60.0)
//   {
//     mark = 'D';
//   }
//   else if (sum > 40.0)
//   {
//     mark = 'F';
//   }
//   else
//   {
//     mark = 'F';
//   }
//   printf("Grade: %c", mark);
// }

// #include <stdio.h>
// #include <stdlib.h>

// int anagram(char[], char[]);

// int main(int argc, char const *argv[])
// {
//   char a[10], b[10];
//   // first = malloc(4);
//   // second = malloc(4);
//   printf("Test Data:\n%s", "Input the first string: ");
//   gets(a);
//   printf("\nInput the second string: ");
//   gets(b);

//   int success = anagram(a, b);
//   if (success)
//   {
//     printf("%s and %s are anagrams", a, b);
//   }
//   else
//     printf("%s and %s are not anagrams", a, b);
//   return 0;
// }

// int anagram(char a[], char b[])
// {
//   int first[26] = {0}, second[26] = {0}, c = 0;

//   // Calculating frequency of characters of the first string

//   while (a[c] != '\0')
//   {
//     first[a[c] - 'a']++;
//     c++;
//   }
//   printf("%d", first[a[0] - 'a']);

//   c = 0;

//   while (b[c] != '\0')
//   {
//     second[b[c] - 'a']++;
//     c++;
//   }

//   // Comparing the frequency of characters

//   for (c = 0; c < 26; c++)
//     if (first[c] != second[c])
//       return 0;

//   return 1;
// }

// // ========================================================================================================================= //
// // Linkedlist
// // ========================================================================================================================= //

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdbool.h>
// // structure describing one node of the list
// struct node
// {
//   int data;
//   int key;
//   struct node *next;
// };

// // pointing to the beginning of the list and the current node
// struct node *head = NULL;
// struct node *current = NULL;

// // is list empty
// bool isEmpty()
// {
//   return head == NULL;
// }

// int length()
// {
//   int length = 0;
//   struct node *current;

//   //for (current = head; current != NULL; current = current->next)
//   while (current != NULL)
//   {
//     length++;
//     current = current->next;
//   }

//   return length;
// }

// //insert link at the first location
// void insertFirst(int key, int data)
// {
// //create a link
//   struct node *link = (struct node *) malloc (sizeof (struct node));
//   link->key = key;
//   link->data = data;
//   if (isEmpty ())
//     {
//       head = link;
//       head->next = head;
//     }
//   else
//     {
// //point it to old first node
//       link->next = head;
// //point first to new first node
//       head = link;
//     }
// }

// //delete first item
// struct node *deleteFirst()
// {
// //save reference to first link
//   struct node *tempLink = head;
//   if (head->next == head)
//     {
//       head = NULL;
//       return tempLink;
//     }
// //mark next to first link as first
//   head = head->next;
// //return the deleted link
//   return tempLink;
// }

// //display the list
// void printList()
// {
//   struct node *ptr = head;
//   printf("\n[ ");
// //start from the beginning
//   if (head != NULL)
//     {
//       while (ptr->next != ptr)
// 	{
// 	  printf("(%d,%d) ", ptr->key, ptr->data);
// 	  ptr = ptr->next;
// 	}
//     }
//   printf(" ]");
// }

// void linkedlist()
// {
//   insertFirst (1, 10);
//   insertFirst (2, 20);
//   insertFirst (3, 30);
//   insertFirst (4, 1);
//   insertFirst (5, 40);
//   insertFirst (6, 56);
//   printf("Original List: ");
// //print list
//   printList ();
//   // TODO: write the code to delete the entire list
//   while(head != NULL)
//   {
//     free(deleteFirst());
//   }
//   printf("\nList after deleting all items: ");
//   printList ();
// }

// ========================================================================================================================= //
// ========================================================================================================================= //
// ========================================================================================================================= //
// ========================================================================================================================= //
// ========================================================================================================================= //
// ========================================================================================================================= //

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>

// // function declarations
// void convert(char *in); // convert binary to hexidecimal
// int valid_bin(char *str); // check if input is a valid binary
// /*
// * Main function in the program,
// * @params argc and argv are passed
// * @return int (exit code)
// */
// int main(int argc, char *argv[])
// {
//   char buffer[40], *input; // create buffer array to support input for piping. create input pointer for use in convert() function
//   if (argc == 1)           // if there is no argument
//   {
//     input = fgets(buffer, 40, stdin); // get input from stdin (command line)
//   }
//   else
//   {                  // if there is an argument
//     input = argv[1]; // get input from argument
//   }
//   if (valid_bin(input))
//   {                 // if to check if input is valid binary
//     convert(input); // if valid call convert function
//   }
//   else
//   {                                     // if not valid binary input
//     printf("Invalid binary number.\n"); // error message
//     return 1;                           // exit program
//   }                                     // call function to convert binary to hexadecimal
//   return 0;                             // successful execution return code
// }

// // method to convert binary number to hex string
// void convert(char *in)
// {
//   int value = (int)strtol(in, NULL, 2); // convert input from a string to an integer to a base 2 to represent binary
//   char hex[12];                         // create character array for hex representation
//   sprintf(hex, "%x\n", value);          // writes values to the hex array
//   printf(hex);                          // output hex string to console
// }

// /* function to check if input is a valid binary representation */
// int valid_bin(char *str)
// {
//   while (*str != '\n' && *str != '\0')
//   { // while string hasn't ended (taking fgets into account, as well as arguments)
//     if (*str != '0' && *str != '1')
//     {           // checks if the character is not 1 and not 0
//       return 0; // returns 0 if input is not a 1 or 0
//     }
//     str++; // increments to next character in string
//   }
//   return 1; // returns when input is a valid number
// }

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void help();
// void convert(int d);
// int valid_int(char *str);
// int get_byte(int arg);
// /*
// * Main function in the program,
// * @params argc and argv passed
// * @return int (exit code)
// */
// int main(int argc, char *argv[])
// {
//   if (argc == 2)
//   { // if one argument was provided
//     if (strcmp("-h", argv[1]) == 0)
//     {           // check if help flag is passed as argument
//       help();   // call function to display help to user
//       return 0; // exit program
//     }
//     int result = valid_int(argv[1]); // result calls valid_int() method and 1 is returned if true, 0 if false
//     if (result)
//     {                            // if number is valid
//       int input = atoi(argv[1]); // convert argument to an integer
//       convert(input);            // call function to convert the decimal input
//     }
//     else
//     {                                                                           // if not a valid number
//       printf("Argument is not a valid decimal number. Enter '-h' for help.\n"); // print error message
//     }
//   }
//   else
//   {
//     printf("Please provide one arg. Enter '-h' for help.\n"); // print error message
//   }
//   // successful execution return code
//   return 0;
// }

// /* function to display help to the user when required */
// void help()
// {
//   printf("Program to convert decimal to binary, and binary to hexadecimal. Enter one argument - a positive decimal number.\nExample: dec2bin 250 | bin2hec \n"); // helpful information when user requires it
// }

// /* function to convert the decimal value to a binary representation */
// void convert(int d)
// {
//   int size = get_byte(d); // set size to the number of bits returned from get_byte()
//   int binary[size];       // create an array of integers the size of the required bits
//   for (int i = 0; i < size; i++)
//   {                                 // loop over each number in the array of bits
//     binary[i] = (char)(d >> i) & 1; // we shift the decimal down based on the ith digit of the binary representation and check whether that digit should be a 1 or a 0
//   }
//   for (int i = size - 1; i >= 0; i--)
//   {                          // for each number in the array in reverse order
//     printf("%d", binary[i]); // print every element
//   }
//   printf("\n"); // next line
// }

// /* function to check whether the input is a valid positive number. Also fails if number is a floating point number */
// int valid_int(char *str)
// {
//   while (*str != '\0')
//   {
//     if (!isdigit(*str))
//     {           // isdigit returns 0 if input is not a number, or 1 if it is a number
//       return 0; // return when not a number
//     }
//     str++; // increment to next character
//   }
//   return 1; // return when input is a valid number
// }

// /* function to check the input number in order to find how many bytes are required. */
// int get_byte(int arg)
// {
//   int n = 0; // number of bytes
//   while (arg != 0)
//   {            // when a number still exists
//     arg >>= 8; // bitshift 8 to the right
//     n++;       // increment the number of bytes required
//   }
//   return n * 8; // return the amount of bits
// }

// #include <stdio.h> // for standard input/output functions
// #include <stdlib.h> // for atoi
// void encrypt(int, char **, char* str); // define the function to encrypt

// int main(int argc, char *argv[]) // main function
// {
//   // exit if no argument or too many args were provided
//   if (argc !=2) { // check if we dont have 2 args
//     printf("Must provide one argument, which is the amount of shifts for the characters"); // error message
//     return 1; // exit code (error)
//   }
//   // arbitrary size array to hold input
//   char str[256]; // variable to store user input, 256 is arbitrarly chosen
//   printf("Enter the string to encrypt.\n"); // print to console to ask for user input
//   while (scanf("%s", str) != EOF) // loop continues until user ends the program via the command line
//   {
//     encrypt(argc, argv, str); // function to encrypt is executed
//     printf("Enter the string to encrypt.\n"); // print to console to ask for user input
//   }
// }

// void encrypt(int argc, char *argv[], char *str) // function to encrypt
// {
//     int i = 0; // initialising i to use in while loop
//     char *a = argv[1]; // create pointer to command line argument for encryption amount
//     int amount = atoi(a); // get the integer from the character pointer

//     //while (scanf("%s", input) != EOF)
//       while (str[i] != '\0') // while loop continues until end of the user's input string
//       {
//         if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) // checks if character is valid alphabet letters
//         {
//             if (str[i] < 'a' && str[i] > 'Z' - amount || str[i] <= 'z' && str[i] > 'z' - amount) // checks if character's will fall outside of alphabet ASCII numbers after encryption
//             {
//                 str[i] -= 26 - amount; // equation to ensure encryption stays in the lowercase of uppercase alphabet range respectively
//             }
//             else // else condition
//             {
//                 str[i] += amount; // equation for simple encryption using user's argument
//             }
//         }
//         i++; // increment i to check next character in while loop
//     }
//     printf("\nThe encrypted str is: %s\n", str); // print string after encryption
// }

// #include <stdio.h> // input output
// #include <stdlib.h> // rand and srand functions
// #include <time.h> // for the random seed

// // generate random number
// int rand(void);
// // function that runs the game loop
// void guessing();
// // max number of guesses
// int MAXNUMBER = 6;

// /*
// * Main function in the program,
// * @params argc and argv passed
// * @return int (exit code)
// */
// int main(int argc, char *argv[])
// {
//   srand(time(0));    // create a random seed
//   char answer = 'y'; // initialize the answer string

//   do
//   {                                                // continue loop until while condition is false
//     guessing();                                    // run the guessing function
//     printf("Would you like to play again? y/n\n"); // print to console
//     scanf("%s", &answer);                          // get the answer
//   } while (answer == 'y');                         // continue loop while answer is 'y'

//   return 0; // exit program
// }

// /* function to initiate the guessing game */
// void guessing()
// {
//   int count = 0;              // initialize the count of the amount of guesses
//   int num = rand() % 100 + 1; // get a random number from the random number generator
//   char input;                 // create variable to store user input
//   int guess;                  // create variable to store the guess

//   do
//   {
//     printf("%s", "Guess the number.\n"); // print to console
//     if (scanf("%d", &guess) == 1 && guess >= 1 && guess <= 100)
//     {          // check whether input is valid
//       count++; // increment count of guesses
//       if (guess == num)
//       { // check whether user guess is equal to the random number
//         printf("%s %d %s", "Well done! You guessed", count,
//               "times to get the correct answer.\n"); // print success to console
//         break;                                        // end
//       }
//       else if (guess < num)
//       {                                                                                             // if guess is lower than the random number
//         printf("%s %d %s", "Your guess is too low. You have", MAXNUMBER - count, "guesses left\n"); // print to console
//       }
//       else                                                                                           // if guess is higher than the random number
//         printf("%s %d %s", "Your guess is too high. You have", MAXNUMBER - count, "guesses left\n"); // print to console
//     }
//     else
//     {                   // if input is not valid
//       scanf("%*[^\n]"); // discard that line up to the newline
//       printf(
//           "Wrong format. Only numbers between 1-100 (inclusive) accepted.\n"); // print helpful advice to console
//       // continue;
//     }
//   } while (guess != num && count < MAXNUMBER); // loop until guess is equal to random number
//   if (count == MAXNUMBER)
//   {
//     printf("You ran out of guesses! Try again\n\n"); //
//   }
// }

// #include <stdio.h> // Header for standard input/output functions
// #include <stdlib.h> // Header for standard library functions
// #include <time.h> // Header for date/time operations

// #define MAX 100      // defines the maximum number of the values in the table
// #define MAXNUMBER 20 // defines the maximum value of random numbers

// // function declarations
// void create_random(int *tab);
// // get the frequency of each number
// void count_frequency(int *tab, int *freq);
// // draw a historgram representing the num of occurences of each number
// void draw_histogram(int *freq);
// // get a random int from 0-MAXNUMBER
// int rand_int();
// /**
// * main function of program. entry point for the program which calls the other
// * functions.
// * @return int which is the exit code
// */
// int main(void) {
//   // random seed init
//   srand(time(0));
//   // initialize a table to fill with random numbers
//   int table[MAX];
//   // initialize a frequency array to count the occurances within table
//   int frequency[MAXNUMBER];
//   create_random(table);
//   // counts the frequency of occurances of each number in table
//   count_frequency(table, frequency);
//   // draw a histogram to represent the frequency of the numbers within table
//   draw_histogram(frequency);
//   // exit code
//   return 0;
// }

// int rand_int() {
//   // return a random integer between the min and max value
//   return (rand() % (MAXNUMBER + 1));
// }

// /* method to fill the table with random numbers */
// void create_random(int *tab) {
//   for (int i = 0; i < MAX;
//       i++) { // loop according to the MAX amount specified in the program
//     tab[i] = rand_int(); // set the number to a random value using the rand_int() function
//   }
// }

// /* method to count the frequency of occurrences
// of each number in the table of random numbers */
// void count_frequency(int *tab, int *freq) {
//   for (int i = 0; i < MAXNUMBER; i++) { // loop over each number in the frequency table
//     freq[i] = 0; // initialise the frequency to zero
//   }
//   for (int i = 0; i < MAX; i++) { // loop over each number in the table of
//                                   // random numbers to increment the frequency
//     int val = tab[i];             // find the value of the number
//     freq[val]++;                  // increment frequency of the number
//   }
// }

// /* method to create the histogram that will be displayed as
// output in the console showing each number and its occurrence. */
// void draw_histogram(int *freq) {
//   for (int i = 0; i < MAXNUMBER;
//       i++) { // loop through each number that could occur according to the
//               // MAXNUMBER value set in the program
//     if (freq[i] != 0) { // check if the number occurs in the table of random
//                         // numbers, if not, continue to next number
//       printf("%d ", i); // print the number
//       for (int j = 0; j < freq[i]; j++) { // for each occurrence of the number
//         printf("x");                      // print the number's occurrence
//       }
//       printf("\n"); // next line
//     }
//   }
// }

// #include <stdlib.h> // for using atoi
// #include <stdio.h>  // to print

// typedef unsigned char byte;

// /* function declaration */
// void print_byte_as_bits(char val);
// int check_input(char *, int);

// /* main function */
// int main(int argc, char const *argv[])
// {
//   if (argc != 6) // if there are too few arguments
//   {
//     printf("Not enough arguments passed. You should pass 5 arguments with a space between each one. For example: '1 1 1 1 1'.\n"); // error message
//     return 1;                                                                                                                      // return                                                                                                               // exit the program
//   }
//   for (int i = 1; i < 6; i++) // for each argument input
//   {
//     if (!check_input(argv[i], i)) // calls function to check the user input
//     {
//       printf("There was an error with your arguments. The minimum value for each argument is 0, and the maximum value is: 1, 4, 3, 1, 1, respectively."); // error message
//       exit(0);                                                                                                                                            // exit code
//     }
//   }

//   byte value = 0;              // set a byte variable and initialise it to 0
//   value += atoi(argv[1]) << 7; // bitshift the first argument and create an integer to represent the 7th binary char
//   value += atoi(argv[2]) << 4; // bitshift the second argument and create an integer to represent the 4th-6th binary chars
//   value += atoi(argv[3]) << 2; // bitshift the third argument and create an integer to represent the 3rd binary char
//   value += atoi(argv[4]) << 1; // bitshift the second argument and create an integer to represent the 2nd binary char
//   value += atoi(argv[5]);      // create an integer to represent the 1st binary char
//   printf("Hex: %x\n", value);  // print the value which will be the hex representation of the input
//   return 0;                    // exit program
// }

// /*function to check if input is valid*/
// int check_input(char *input, int current)
// {
//   int value = atoi(input);           // first get the int value of the input
//   if (value == 0 && input[0] != '0') // if the input is the char 0 it is valid otherwise if atoi returns a 0 it wasnt a valid input
//   {
//     return 0; // return not valid
//   }

//   if (current == 1 || current == 4 || current == 5) // if it's the 1st, 4th, or 5th argument
//   {
//     if (value == 1 || value == 0) // value must be 0 or 1
//     {
//       return 1; // return success
//     }
//   }
//   else if (current == 2) // if it's the 2nd argument
//   {
//     if (value >= 0 && value <= 4) // if the value is between 0 and 7
//     {
//       return 1; // return success
//     }
//   }
//   else if (value >= 0 && value <= 3) // if it's the 3rd argument and the value is between 0 and 3
//   {
//     return 1; // return success
//   }
//   return 0; // exit code
// }

// #include <stdlib.h> // strtol
// #include <stdio.h>  // printf
// #include <string.h> // strlen

// // byte type declaration unsigned char = 8 bits
// typedef unsigned char byte;

// // function declaration
// void show_results(byte val);

// // Main function
// int main(int argc, char *argv[])
// {
//     if (argc != 2)            // the program should only accept 1 user provided argument, otherwise exit the program with an error code
//         return 1;             // error exit code
//     if (strlen(argv[1]) == 2) // if the stringlength is 2 characters
//     {
//         char one = argv[1][0]; // set a char variable to the first character of the string
//         char two = argv[1][1]; // set a char variable to the second character of the string

//         // if check to see whether input is valid hexadecimal by checking for letters between a and f OR A and F OR 0 and 9
//         if (!(((one <= 'f' && one >= 'a') && (two <= 'f' && two >= 'a')) || ((one <= 'F' && one >= 'A') && (two <= 'F' && two >= 'A')) || ((one <= '9' && one >= '0') && (two <= '9' && two >= '0'))))
//         {
//             printf("Not a valid hexadecimal number\n"); // error message
//             return (0); // exit the program
//         }
//     }
//     else if (strlen(argv[1]) > 2) // if the stringlength is more than 2 characters
//     {
//         printf("Please enter a hexadecimal with a max of 2 characters\n"); // error message
//         return (1); // error exit code
//     }

//     byte value = (int)strtol(argv[1], NULL, 16); // convert hex to decimal (in the form of a unsigned char byte)
//     if (strlen(argv[1]) == 1)                    // if the inut is one character
//     {
//         // if check to see if the decimal value is lower than the max/min allowed. Also checks when ther is a letter outside of range with the 3rd OR.
//         if (value > 203 || value < 0 || (value == 0 && argv[1] != 0))
//         {
//             printf("Invalid input.\n"); // error message
//             return 0; // exit the program
//         }
//     }
//     show_results(value); // display the result
// }

// // function to display the arguments that were provided to code
// void show_results(byte val)
// {
//     char bits[8];               // array to hold the bits of the dec value
//     for (int i = 0; i < 8; i++) // decrement so the order is correct
//     {
//         // shift based on the position in the byte, ternary for 1 or 0
//         // cast to char so the ternary works
//         bits[i] = (char)(val & (1 << i)) ? '1' : '0';
//     }

//     int gear_pos = 0;           // init gear_pos
//     int key_pos = 0;            // init key_pos
//     int bin_rep_gear = 4;       // init bin_rep_gear
//     int bin_rep_key = 2;        // init bin_rep_key
//     for (int i = 6; i > 3; i--) // check the 0 _ _ _ 0000 positions in the byte
//     {
//         if (bits[i] == '1')           // check if this index is 1
//             gear_pos += bin_rep_gear; // if it is increment by bin_rep_gear
//         bin_rep_gear /= 2;            // increment the binary value to represent the current value
//         if (gear_pos > 4) // if the gear_position is higher than the alllowed maximum
//         {
//             printf("There was an error with your input. The gear_pos can have a maximum position of 4.\n"); // error message
//             exit(0); // exit the program
//         }
//     }
//     for (int i = 3; i > 1; i--) // check the 0000 _ _ 00 positions in the byte
//     {
//         if (bits[i] == '1')         // check if this index is 1
//             key_pos += bin_rep_key; // if it is increment by bin_rep_key
//         bin_rep_key /= 2;           // increment the binary value to represent the current value
//         if (key_pos > 2) // if the key position is higher than the maximum alllowed
//         {
//             printf("There was an error with your input. The key_pos can have a maximum position of 2.\n"); // error message
//             exit(0); // exit the program
//         }
//     }
//     printf("Name\t\tValue\n");          // Print the headings for the output
//     printf("engine_on\t%c\n", bits[7]); // print the engine's current state
//     printf("gear_pos\t%d\n", gear_pos); // print the gear's current state
//     printf("key_pos\t\t%d\n", key_pos); // print the key's current state
//     printf("brake1\t\t%c\n", bits[1]);  // print the 1st brake's current state
//     printf("brake2\t\t%c\n", bits[0]);  // print the 2nd brake's current state
// }

// #include <stdio.h>  // functions for standard input/output
// #include <stdlib.h> // for standard library functions (malloc, srand)
// #include <time.h>   // included for the random seed function

// //#### Constants #####
// #define MAX 5

// // ##### typedefs  ####
// typedef struct q // double linked list node
// {
//     int number;     // value in this node
//     struct q *next; // the next node in the list
//     struct q *prev; // the previous node in the list
// } REGTYPE;          // so you dont have to use struct q

// // ##### Function declarations   #####
// REGTYPE *random_list(void);         // declaration of method
// REGTYPE *add_first(REGTYPE *, int); // declaration of method
// void *iterate_list(REGTYPE *, REGTYPE *); // declaration of method
// void *deallocate_list(REGTYPE *, REGTYPE *); // declaration of method

// //###### Main program #######
// int main(int argc, char *argv[])
// {
//     REGTYPE *act_post, *head = NULL; // init the head and act_post pointers

//     srand(time(0));               // random seed
//     head = random_list();         // call function to create initial list
//     iterate_list(act_post, head); // iterate over the list and print the items

//     head = add_first(head, 1337); // Test adding the new item as the list's head
//     iterate_list(act_post, head); // iterate over the list and print the items

//     head = add_first(head, 1234); // Test adding another item as the list's head
//     iterate_list(act_post, head); // iterate over the list and print the items

//     deallocate_list(act_post, head); // free memory
//     return 0; // exit code
// }

// // ==== End of main ======================================
// /* function to create a random list using the MAX amount of list items */
// REGTYPE *random_list(void)
// {
//     int nr;    // set a variable and initialise it to 0
//     int i = 0; // set a variable and initialise it to 0

//     REGTYPE *top, *old, *item; // create three pointers to the struct type of REGTYPE
//     top = NULL;                // set top to null
//     while (i < MAX)            // while i is not equal to MAX
//     {
//         item = (REGTYPE *)malloc(sizeof(REGTYPE)); // create an item struct of type REGTYPE
//         item->number = rand() % 100 + 1;           // set the item's number variable to a random integer
//         item->next = NULL;                         // initialise item's next variable to null
//         if (top == NULL)                           // the first run of the loop
//         {
//             item->prev = NULL; // initialise item's previous variable to null
//             top = item;        // set top to current item
//         }
//         else // for every run of the loop after the first item has been set to the top
//         {
//             old = top;                // the old pointer is set as the current top
//             while (old->next != NULL) // while there are next items in the list
//             {
//                 old = old->next; // set old to the next item in the list
//             }
//             item->prev = old; // set the current item's previous variable to the old item
//             old->next = item; // set the end of the list's next to the current item
//         }
//         i++; // increment i
//     }
//     return (top); // return the top of the list
// }

// //==========================================================
// /* function to append an item to the top of the list */
// REGTYPE *add_first(REGTYPE *temp, int data)
// {
//     REGTYPE *item = (REGTYPE *)malloc(sizeof(REGTYPE)); // create a new struct of type REGTYPE
//     item->number = data; // set item's number variable to the data parameter (a random int)
//     temp->prev = item; // set temp's previous variable (head passed as parameter) to the current item
//     item->next = temp; // set item's next variable to the current head (parameter passed as temp)
//     return item; // return item which is now the list's head
// }

// //==========================================================
// /* function to iterate over the list, print list items, and update the active position via pointer */
// void *iterate_list(REGTYPE *act_post, REGTYPE *head)
// {
//     int nr = 0;      // counter
//     act_post = head; // set the current position to head

//     while (act_post != NULL)      // while the current position is not null
//     {
//         printf("\n Post nr %d : %d", nr++, act_post->number); // print the nr and value of correspond node, and increment nr
//         act_post = act_post->next;                            // set the position to the next item in list
//     }
//     printf("\n"); // clean up lines
// }

// //==========================================================
// /* function to free the memory from allocated list items */
// void *deallocate_list(REGTYPE *act_post, REGTYPE *head)
// {
//     // reset the position of act_post to head since act_post is at the end of list after first while loop
//     while ((act_post = head) != NULL) //  while current position is not 0
//     {
//         head = act_post->next; // set to next position as you free each this is to make sure that you free everything
//         free(act_post);        // since the head is pointing to next we can free the previous head without losing the list
//     }
// }

// #include <stdio.h>  // for input/output functions
// #include <stdlib.h> // for standard c functions
// #include <string.h> // for strlen & strcmp: string functions

// #define FILE_NAME "ex3.bin"
// typedef struct // identifier for the struct
// {
//   char firstname[20];   // first name chars with array size 20
//   char famname[20];     // family name chars with array size 20
//   char pers_number[13]; // personal # array size based on yyyymmddnnnnc
// } PERSON;               // typedef name

// /* functions declaration */
// void menu();
// void new_db();
// void create();
// void search();
// void print_all();
// void print_person(PERSON);

// /*
// * Main function in the program,
// * @params none
// * @return int (exit code)
// */
// int main(int argc, char const *argv[])
// {
//   while (1) // while loop to run the menu
//   {
//     menu(); // menu function
//   }
//   return 0; // exit code
// }

// /* function to run the menu */
// void menu()
// {
//   printf( // print to console the following lines
//       "1. Create a new and delete the old file.\n"
//       "2. Add a new person to the file.\n"
//       "3. Search for a person in the file.\n"
//       "4. Print out all in the file.\n"
//       "5. Exit the program\n");
//   printf("> ");
//   char choice = getchar(); // get a character from the input
//   getchar();               // handle the 'Enter' (\n)
//   switch (choice)          // choice selections based on user input
//   {
//   case '1':                     // if user input is 1
//     new_db();                   // call new_db function
//     break;                      // terminate the loop
//   case '2':                     // if user input is 2
//     create();                   // call create function
//     break;                      // terminate the loop
//   case '3':                     // if user input is 3
//     search();                   // call the search function
//     break;                      // terminate the loop
//   case '4':                     // if user input is 4
//     print_all();                // call print_all function
//     break;                      // terminate loop
//   case '5':                     // if user input is 5
//     exit(0);                    // exit the program
//     break;                      // terminate loop
//   default:                      // if user input is not 1-5
//     printf("invalid choice\n"); // prints to console
//     menu();                     // call menu function
//     break;                      // terminate loop
//   }
// }

// /* function to create a database binary file */
// void new_db()
// {
//   FILE *fp;                                        // file pointer
//   fp = fopen(FILE_NAME, "wb+");                    // to create an empty binary file for reading/writing
//   PERSON dummy = {"Jane", "Doe", "199909091111"};  // mock data for one entry
//   fwrite(&dummy, sizeof(dummy), 1, fp);            // writes data to file
//   PERSON dummy2 = {"Jack", "Doe", "199909091112"}; // mock data for a second entry
//   fwrite(&dummy2, sizeof(dummy2), 1, fp);          // writes data to file
//   fclose(fp);                                      // closes the file
// }

// // /* function to create an entry in the db */
// void create()
// {
//   FILE *fp;                                                     // file struct and pointer
//   PERSON person = { NULL, NULL, NULL };                         // init person
//   fflush(stdin);                                                // discards unconsumed buffered data
//   fflush(stdout);                                               // discards output buffer
//   printf("What is the first name? ");                           // prinnts to console
//   fgets(person.firstname, sizeof(person.firstname), stdin);     // get the first name of the person from stdin
//   person.firstname[strlen(person.firstname) - 1] = '\0';        // swap \n for \0
//   printf("What is the last name? ");                            // prints to console
//   fgets(person.famname, sizeof(person.famname), stdin);         // get the last name of the person from stdin
//   person.famname[strlen(person.famname) - 1] = '\0';            // swap \n for \0
//   printf("What is the personnummer? ");                         // get the personal number of the person from stdin
//   fgets(person.pers_number, sizeof(person.pers_number), stdin); // prints to console
//   person.pers_number[strlen(person.pers_number) - 1] = '\0';    // swap \n for \0
//   print_person(person);                                         // Print the person struct
//   fp = fopen(FILE_NAME, "rb");                                  // open file in read binary mode to check if file exists
//   if (fp == NULL) {                                             // check if file pointer is null
//     new_db();                                                   // create db if file is null
//     fp = fopen(FILE_NAME, "ab");                                // open file in append binary mode
//   } else {                                                      // if file is not null
//     fclose(fp);                                                 // close the read mode
//     fp = fopen(FILE_NAME, "ab");                                // open the file in append mode now that we know the file exists
//   }
//   fwrite(&person, sizeof(person), 1, fp);                       // write the person struct to the file
//   getchar();                                                    // to handle the 'Enter'
//   fclose(fp);                                                   // closes the file
// }

// /* function closes the fileto print all persons from within the file */
// void print_all()
// {
//   FILE *fp;                                          // file pointer
//   PERSON person;                                     // person variable
//   fp = fopen(FILE_NAME, "rb");                       // open the file in read binary mode
//   if (fp == NULL) {
//     new_db();
//     fp = fopen(FILE_NAME, "rb");                                  // open file in append binary mode
//   }
//   while (fread(&person, sizeof(person), 1, fp) != 0) // while the file still has content print the person
//   {
//     print_person(person); // print the person struct
//   }
//   fclose(fp); // closes the file
// }

// /* function to print a person from within the file */
// void print_person(PERSON person)
// {
//   printf("first name: %s\n", person.firstname);        // prints person's firstname to console
//   printf("last name: %s\n", person.famname);           // prints person's family name to console
//   printf("personal number: %s\n", person.pers_number); // prints person's personal # to console
// }

// /* function to search for a person from within the file */
// void search()
// {
//   FILE *fp;                                          // create file pointer
//   PERSON person;                                     // create a new struct of type PERSON
//   char searchterm[20];                               // create a characteer array
//   char ch = '\0';                                    // create an end of line character placeholder
//   fp = fopen(FILE_NAME, "rb");                       // set fp to the file we want to open which will read binary
//   if (fp == NULL) {
//     new_db();
//     fp = fopen(FILE_NAME, "rb");                                  // open file in append binary mode
//   }
//   printf("1. Search by first name\n");               // print to console
//   printf("2. Search by last name\n");                // print toconsole
//   ch = getchar();                                    // set ch to the user's input
//   printf("What is the name: ");                      // print to console
//   scanf("%s", searchterm);                           // set the searchterm to user's input
//   while (fread(&person, sizeof(person), 1, fp) != 0) // while there is a person in the file list
//   {
//     if (strcmp(person.firstname, searchterm) == 0 && ch == '1') // if the comparison between the user's searchterm is equal to the person's firstname
//     {
//       print_person(person); // call the print function
//     }
//     if (strcmp(person.famname, searchterm) == 0 && ch == '2') // if the comparison between the user's searchterm is equal to the person's lastname
//     {
//       print_person(person); // call the print function
//     }
//   }
//   getchar();  // handle the 'Enter' (\n) newline cha
//   fclose(fp); // closes the file
// }
// ========================================================================================================================= //
// checking chars
// ========================================================================================================================= //
// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//   // if 0 no if greater then 1 yes
//   printf("is hex: %d\n", isxdigit('A') > 0);
//   printf("is alpha: %d\n", isalpha('z') > 0);
//   printf("is digit: %d\n", isdigit('1') > 0);
//   return 0;
// }
