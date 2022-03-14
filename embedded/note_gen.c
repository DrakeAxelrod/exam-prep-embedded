#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("provide argument");
    exit(0);
  }
  char *arg = argv[1];
  if (strcmp("types", arg) == 0)
  {
    printf(
        "\
Data Type                  Memory (bytes)          Range                                Format Specifier\n\
========================================================================================================================= //\n\
short int                  2                       -32,768 to 32,767                    \% hd\n\
unsigned short int         2                       0 to 65,535                          \% hu\n\
unsigned int               4                       0 to 4,294,967,295                   \% u\n\
int                        4                      -2,147,483,648 to 2,147,483,647       \% d\n\
long int                   4                      -2,147,483,648 to 2,147,483,647       \% ld\n\
unsigned long int          4                       0 to 4,294,967,295                   \% lu\n\
long long int              8                       -(2^63) to (2^63)-1                  \% lld\n\
unsigned long long int     8                       0 to 18,446,744,073,709,551,615      \% llu\n\
signed char                1                       -128 to 127                          \% c\n\
unsigned char              1                       0 to 255                             \% c\n\
float                      4                                                            \% f\n\
double                     8                                                            \% lf\n\
long double                16                                                           \% Lf\n\
\n");
  }
  else if (strcmp("amdahl", arg) == 0)
  {
    printf(
        "\
========================================================================================================================= //\n\
Amdahl's Law\n\
========================================================================================================================= //\n\
\n\
After reducing the sequential part of her code to 20\% and using 4 cores instead of 1 for the\n\
rest of the code, Maria’s program ran 3 times faster compared to the original code.\n\
check with Amdhal’s law... E.g. 1/(0.2+0.8/4)=2.5<3 ->so first sentence if false\n\
\n\
Identifies performance gains from adding additional cores to an application\n\
The application has both serial and parallel components\n\
S - is serial portion, N - is processing cores\n\
\n\
equation:\n\
speedup <= 1(S + (1-S / N))\n\
this means that if app is 75\% parallel and 25\% serial, moving from 1 to 2 cores results in speedup of 1.6 times\n\
1(0.25 + (1-0.25 / 0.75)) -> 1(0.25 + (1/0.75)) -> 1(0.25 + 1.33) -> 1(1.58) -> 1.58 = rounded to 1.6\n\
As N approaches infinity, speedup approaches - 1 / S\n\
========================================================================================================================= //\n\
Amdahl's Law # 2\n\
========================================================================================================================= //\n\
Amdahl’s Law was named after Gene Amdahl, who presented it in 1967.\n\
In general terms, Amdahl’s Law states that in parallelization,\n\
if P is the proportion of a system or program that can be made parallel,\n\
and 1-P is the proportion that remains serial, then the maximum speedup S(N)\n\
that can be achieved using N processors is:\n\
\n\
                 S(N)=1/((1-P)+(P/N))\n\
\n\
As N grows the speedup tends to 1/(1-P).\n\
\n\
Speedup is limited by the total time needed for the sequential (serial) part of the program.\n\
For 10 hours of computing, if we can parallelize 9 hours of computing and 1 hour cannot be parallelized,\n\
then our maximum speedup is limited to 10 times as fast. If computers get faster the speedup itself stays the same.\n\
\n");
  }
  else if (strcmp("parrallism", arg) == 0)
  {
    printf(
        "\n\
Parrallism\n\
========================================================================================================================= //\n\
Parallelism is related to an application where tasks are divided into smaller sub-tasks that are processed \n\
seemingly simultaneously or parallel. It is used to increase the throughput and computational speed of \n\
the system by using multiple processors. It enables single sequential CPUs to do lot of things “seemingly” simultaneously. \n\
Parallelism leads to overlapping of central processing units and input-output tasks in one process with the central \n\
processing unit and input-output tasks of another process. Whereas in concurrency the speed is increased by overlapping \n\
the input-output activities of one process with CPU process of another process.  \n\
\n");
  }
  else if (strcmp("concurrency", arg) == 0)
  {
    printf(
        "\n\
Concurrency\n\
========================================================================================================================= //\n\
single core cpus can run multiple threads through the use of interrupts\n\
this allows for context switching between applications\n\
//\n\
In a multithreaded process on a single processor, the processor can switch execution resources between threads,\n\
resulting in concurrent execution. Concurrency indicates that more than one thread is making progress,\n\
but the threads are not actually running simultaneously.\n\
\n\
Concurrency relates to an application that is processing more than one task at the same time. \n\
Concurrency is an approach that is used for decreasing the response time of the system by using the single processing unit. \n\
Concurrency is creates the illusion of parallelism, however actually the chunks of a task aren’t parallelly processed, \n\
but inside the application, there are more than one task is being processed at a time. \n\
It doesn’t fully end one task before it begins ensuing. \n\
Concurrency is achieved through the interleaving operation of processes on the central processing unit(CPU) or  \n\
in other words by the context switching. that’s rationale it’s like parallel processing.  \n\
It increases the amount of work finished at a time.  \n\
\n");
  }
  else if (strcmp("threads", arg) == 0)
  {
    printf("\n\
threads\n\
========================================================================================================================= //\n\
Semaphore\n\
In computer science, a semaphore is a variable or abstract data type\n\
used to control access to a common resource by multiple threads\n\
and avoid critical section problems in a concurrent system such as a multitasking operating system.\n\
Semaphores are a type of synchronization primitives.\n\
A trivial semaphore is a plain variable that is changed (for example, incremented or decremented, or toggled)\n\
depending on programmer-defined conditions.\n\
\n ");
  }
  else if (strcmp("libs", arg) == 0)
  {
    printf("\n\
C Libraries\n\
========================================================================================================================= //\n\
stdio.h -> input/output\n\
unistd.h -> POSIX operating system API (sleep)\n\
assert.h -> void assert(int expression) This is actually a macro and not a function, which can be used to add diagnostics in your C program.\n\
\n\
stdlib.h:\n\
---------\n\
int atoi(const char *str)                -> Converts the string pointed to, by the argument str to an integer (type int).\n\
void *calloc(size_t nitems, size_t size) -> Allocates the requested memory and returns a pointer to it.\n\
void *malloc(size_t size)                -> Allocates the requested memory and returns a pointer to it.\n\
void *realloc(void *ptr, size_t size)    -> Attempts to resize the memory block pointed to by ptr that was previously allocated with a call to malloc or calloc.\n\
void free(void *ptr)                     -> Deallocates the memory previously allocated by a call to calloc, malloc, or realloc.\n\
void exit(int status)                    -> Causes the program to terminate normally.\n\
void srand(unsigned int seed)            -> This function seeds the random number generator used by the function rand.\n\
int rand(void)                           -> Returns a pseudo-random number in the range of 0 to RAND_MAX.\n\
\n\
void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) -> Performs a binary search.\n\
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))  -> Sorts an array.\n\
int abs(int x)                           -> Returns the absolute value of x.\n\
\n\
math.h:\n\
---------\n\
double exp(double x)                     -> Returns the value of e raised to the xth power.\n\
double log(double x)                     ->  Returns the natural logarithm (base-e logarithm) of x.\n\
double log10(double x)                   ->  Returns the common logarithm (base-10 logarithm) of x.\n\
double pow(double x, double y)           ->  Returns x raised to the power of y\n\
double sqrt(double x)                    ->  Returns the square root of x.\n\
double fabs(double x)                    ->  Returns the absolute value of x\n\
double fmod(double x, double y)          ->  Returns the remainder of x divided by y.\n\
\n\
string.h:\n\
---------\n\
int memcmp(const void *str1, const void *str2, size_t n)     ->  Compares the first n bytes of str1 and str2.\n\
void *memcpy(void *dest, const void *src, size_t n)          ->  Copies n characters from src to dest.\n\
size_t strlen(const char *str)                               ->  Computes the length of the string str up to but not including the terminating null character.\n\
int strcmp(const char *str1, const char *str2)               ->  Compares the string pointed to, by str1 to the string pointed to by str2.\n\
int strncmp(const char *str1, const char *str2, size_t n)    ->  Compares at most the first n bytes of str1 and str2.\n\
char *strcpy(char *dest, const char *src)                    ->  Copies the string pointed to, by src to dest.\n\
char *strtok(char *str, const char *delim)                   ->  Breaks string str into a series of tokens separated by delim.\n\
\n\
ctype.h:\n\
---------\n\
int isalnum()                        -> This function checks whether the passed character is alphanumeric.\n\
int isalpha(int c)                   -> This function checks whether the passed character is alphabetic.\n\
int isdigit(int c)                   -> This function checks whether the passed character is decimal digit.\n\
int islower(int c)                   -> This function checks whether the passed character is lowercase letter.\n\
int isspace(int c)                   -> This function checks whether the passed character is white-space.\n\
int isupper(int c)                   -> This function checks whether the passed character is an uppercase letter.\n\
int isxdigit(int c)                  -> This function checks whether the passed character is a hexadecimal digit.\n\
int tolower(int c)                   -> This function converts uppercase letters to lowercase.\n\
int toupper(int c)                   -> This function converts lowercase letters to uppercase.\n\
\n\
errno.h:\n\
---------\n\
extern int errno   -> This is the macro set by system calls and some library functions in the event of an error to indicate what went wrong.\n\
\n\
pthread.h: (cc -lpthread file.c)\n\
---------\n\
pthread_t pthread_self(void) used to get the thread id of the current thread.\n\
int pthread_detach(pthread_t thread) used to detach a thread. A detached thread does not require a thread to join on terminating. The resources of the thread are automatically released after terminating if the thread is detached.\n\
pthread_cond_t PTHREAD_COND_INITIALIZER\n\
pthread_mutex_t PTHREAD_MUTEX_INITIALIZER\n\
pthread_rwlock_t PTHREAD_RWLOCK_INITIALIZER\n\
\n\
int pthread_create(pthread_t *restrict, const pthread_attr_t *restrict, void *(*)(void*), void *restrict);\n\
ARGS:\n\
thread: pointer to an unsigned integer value that returns the thread id of the thread created.\n\
attr: pointer to a structure that is used to define thread attributes like detached state, scheduling policy, stack address, etc. Set to NULL for default thread attributes.\n\
start_routine: pointer to a subroutine that is executed by the thread. The return type and parameter type of the subroutine must be of type void *. The function has a single attribute but if multiple values need to be passed to the function, a struct must be used.\n\
arg: pointer to void that contains the arguments to the function defined in the earlier argument\n\
\n\
int pthread_join(pthread_t, void **);\n\
pthread_mutex_lock(pthread_mutex_t *);\n\
pthread_mutex_unlock(pthread_mutex_t *);\n\
pthread_exit(void *);\n\
ARGS:\n\
This method accepts a mandatory parameter retval\n\
which is the pointer to an integer that stores the return status of the thread terminated.\n\
The scope of this variable must be global so that any thread waiting to join this thread may read the return status.\n\
\n");
  }
  else if (strcmp("input", arg) == 0)
  {
    printf("\n\
C Reading input\n\
========================================================================================================================= //\n\
char str1[5];\n\
if(fgets (str1, 5, stdin) != NULL) {\n\
  writing content to stdout\n\
  printf('\%s', str1);\n\
}\n\
fgets is safe (but does not convert)\n\
sscanf lets your converit the line you got with fgets\n\
\n ");
  }
  else if (strcmp("math", arg) == 0)
  {
    printf("\n\
Math Functions\n\
=========================================================================================================================\n\
\n\
check whether a num is prime or not\n\
int isPrime(int n)\n\
{\n\
  return 1 for non-prime number\n\
  if (n == 0)\n\
  {\n\
    return 1;			if the arg was 0 it is not prime\n\
  }\n\
  for 2 to n/2 check if n modulo i == 0 (basically checking if divisible)\n\
  for (int i = 2; i <= n / 2; ++i)\n\
  {\n\
    if n is divisible by i, then n is not prime\n\
    if (n \% i == 0)\n\
    {\n\
      return 1 for not prime (was divisible)\n\
      return 1;\n\
    }\n\
  }\n\
  return 0;			passed all criteria it is prime\n\
}\n\
\n\
recursive fibonacci\n\
int fib(int n)\n\
{\n\
  if (n <= 1) base case\n\
  {\n\
    return n; return 0 or 1 since those are what n<=1 will catch\n\
  }\n\
  return fib(n-2) + fib(n-1); recursively take the last two numbers in the sequence and sum\n\
}\n\
memoization fib\n\
                          fib(5)\n\
                    /                \\n\
              fib(4)                fib(3)\n\
            /        \\              /       \\ \n\
        fib(3)      fib(2)         fib(2)   fib(1)\n\
        /    \\       /    \\        /      \\n\
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)\n\
  /     \\\n\
fib(1) fib(0)\n\
int memo_fib(int n)\n\
{\n\
  /* Declare an array to store Fibonacci numbers. */\n\
   int f[n+2];   1 extra to handle case, n = 0\n\
  int i;\n\
  /* 0th and 1st number of the series are 0 and 1*/\n\
  f[0] = 0;\n\
  f[1] = 1;\n\
  for (i = 2; i <= n; i++)\n\
  {\n\
    /* Add the previous 2 numbers in the series\n\
      and store it */\n\
    f[i] = f[i-1] + f[i-2];\n\
  }\n\
  return f[n];\n\
}\n\
\n\
power of a number\n\
int pow_of_num(int base, int expn)\n\
{\n\
  if (expn != 0) if we arnt 0 yet keep going\n\
    return (base * pow_of_num(base, expn-1)); recursively call pow_of_num with expn being 1 less\n\
  else\n\
    return 1; once expn hits 0 return 1 (last call)\n\
}\n\
\n\
int factorial(int n)\n\
{\n\
  int i;\n\
  int base = 1;\n\
  if (n < 0)\n\
  {\n\
    base = 0;\n\
  }\n\
  else\n\
  {\n\
    for (i = 1; i <= n; ++i)\n\
    {\n\
      base *= i;\n\
    }\n\
    printf('Factorial of \%d = %l', n, base);\n\
  }\n\
  return base;\n\
}\n\
\n\
factorial\n\
int recursive_fact(int n)\n\
{\n\
	if(n==0)\n\
	{\n\
		return 1;\n\
  }\n\
	else\n\
	{\n\
		return n * recursive_fact(n-1);\n\
  }\n\
}\n\
\n\
FRACTIONS\n\
void add()\n\
{\n\
	num = ((x1 * y2) + (y1 * x2));\n\
	denom = (y1 * y2);\n\
}\n\
\n\
void subtract()\n\
{\n\
	num = ((x1 * y2) - (y1 * x2));\n\
	denom = (y1 * y2);\n\
}\n\
\n\
void multiply()\n\
{\n\
	num = (x1 * x2);\n\
	denom = (y1 * y2);\n\
}\n\
\n\
void divide()\n\
{\n\
	num = (x1 * y2);\n\
	denom = (y1 * x2);\n\
}\n\
\n\
Fraction add_fractions(Fraction a, Fraction b)\n\
{\n\
    Fraction x;\n\
    a.n *= b.d;\n\
    b.n *= a.d;\n\
\n\
    x.n = a.n + b.n;\n\
    x.d = a.d * b.d;\n\
\n\
    return x;\n\
}\n\
\n ");
  }
  else if (strcmp("bit", arg) == 0)
  {
    printf("\n\
Bitwise\n\
=========================================================================================================================\n\
Constant true is 1 and constant false is 0.\n\
\n\
int a = 60;	      /* 60 = 0011 1100 represents 60 in binary*/\n\
int b = 13;	      /* 13 = 0000 1101 */\n\
int c = 0;\n\
\n\
c = a & b;        /* 12 = 0000 1100 */\n\
c = a | b;        /* 61 = 0011 1101 */\n\
c = a ^ b;        /* 49 = 0011 0001 */\n\
c = ~a;           /*-61 = 1100 0011  :Invert all bits */\n\
\n\
shift operators : zeros are shifted in to replace the discarded bits\n\
c = a << 2;       /* 240 = 1111 0000 : Shift left 2 bits*/\n\
c = a >> 2;       /* 15 = 1111 */\n\
c = a >>> 2;      /* 15 = 0000 1111 : Zero fill right shift*/\n\
\n\
\n\
| b1 | b2 | & | | | ^ |\n\
-----------------------\n\
| 1  | 0  | 1 | 1 | 0 |\n\
| 1  | 0  | 0 | 1 | 1 |\n\
| 0  | 1  | 0 | 1 | 1 |\n\
| 0  | 0  | 0 | 0 | 0 |\n\
\n\
| b | ~ |\n\
---------\n\
| 1 | 0 |\n\
| 0 | 1 |\n\
\n\
void outputBinary(uint32_t x)\n\
{\n\
  char binary[35];\n\
  for (int i = 0; i < 35; i++)\n\
  {\n\
    if (i == 8 || i == 17 || i == 26)\n\
    { loop over each number in the array of bits\n\
      binary[i] = '.';\n\
    }\n\
    else\n\
    {\n\
      we shift the decimal down based on the ith digit \n\
      of the binary representation and check whether that digit should be a 1 or a 0\n\
      binary[i] = (char)(x >> i) & 1;\n\
    }\n\
  }\n\
  for (int i = 35 - 1; i >= 0; i--) for each number in the array in reverse order\n\
  {\n\
    if (i == 8 || i == 17 || i == 26)\n\
    {\n\
      printf('\%c', binary[i]);\n\
    }\n\
    else\n\
      printf('i:\%d, \%d ', i, binary[i]); print every element\n\
  }\n\
  printf('\n'); next line\n\
}\n\
\n\
#include <stdio.h>\n\
#include <stdlib.h>\n\
\n\
char *bin(unsigned int n)\n\
{\n\
  int len = sizeof(int) * 8 - 1;\n\
  char *buff = malloc(len);\n\
  for(int i = len; i >= 0; i--)\n\
  {\n\
    int bit = (n >> i & 1) ? 1 : 0;\n\
    sprintf(buff, '\%s\%d', buff, bit);\n\
  }\n\
  return buff;\n\
}\n\
\n\
int main()\n\
{\n\
  int value = 12345678;\n\
  char *b = bin(value);\n\
  printf('binary: \%s', b);\n\
  free(b);\n\
  return 0;\n\
}\n\
\n\
typedef unsigned char byte;\n\
\n\
int convertdectobin(int number) {\n\
    int binary = 0;\n\
    int remainder = 1, i = 1;\n\
\n\
    0b0000 1101\n\
    while (number != 0) {\n\
        remainder = number \% 2;\n\
        number /= 2;\n\
        binary += remainder * i;\n\
        i = i * 10;\n\
    }\n\
    printf('the binary value of \%d is \%d', number, binary);\n\
    return binary;\n\
}\n\
\n\
Decimal (Base 10)	Binary (Base 2)	Hexadecimal (Base 16)\n\
          0	        00000011	      0x00\n\
          1	        00000001	      0x01\n\
          2	        00000010	      0x02\n\
          3	        00000011	      0x03\n\
          4	        00000100	      0x04\n\
          5	        00000101	      0x05\n\
          6	        00000110	      0x06\n\
          7	        00000111	      0x07\n\
          8	        00001000	      0x08\n\
          9	        00001001	      0x09\n\
          10	      00001010	      0x0A\n\
          11	      00001011	      0x0B\n\
          12	      00001100	      0x0C\n\
          13	      00001101	      0x0D\n\
          14	      00001110	      0x0E\n\
          15	      00001111	      0x0F\n\
\n\
To convert a hexadecimal number into decimal, we have to calculate the sum of the powers of 16 of the number.\n\
Example 1.11\n\
Convert hexadecimal number 2AC base(16) into decimal.\n\
Solution 1.11\n\
Calculating the sum of the powers of 16 of the number:\n\
2AC base(16) = 2 × 16^2 + 10 × 16^1 + 12 × 160 = 512 + 160 + 12 = 684\n\
The required decimal number is 684 base(10).\n\
\n\
Example 1.12\n\
Convert hexadecimal number EE base(16) into decimal.\n\
Solution 1.12\n\
Calculating the sum of the powers of 16 of the number:\n\
EE base(16)= 14 × 16^1 + 14 × 16^0 = 224 + 14 = 238\n\
The required decimal number is 238 base(10).\n\
void to_bin(byte b) {\n\
  int binary[8];\n\
  for (int n = 0; n < 8; n++)\n\
  {\n\
    /*\n\
      bit a 	bit b 	a & b (a AND b)\n\
      0       &	0     =	0\n\
      0       &	1     =	0\n\
      1       &	0     =	0\n\
      1       &	1     =	1\n\
\n\
      64   8,4\n\
      0100 1100 - 76 & 0000 0001 = 0000 0000\n\
      >> 0\n\
      [0]\n\
      0010 0110 - 38 & 0000 0001 = 0000 0000\n\
      >> 1\n\
      [0,0]\n\
      0001 0011 - 19 & 0000 0001 = 1 0000 0001\n\
      >> 2\n\
      0000 1001 - 9 & 0000 0001 = 1 0000 0001\n\
      >> 3\n\
      0000 0100 - 4 & 0000 0001 = 0 0000 0000\n\
      >> 4\n\
      0000 0010 - 2 & 0000 0001 = 0 0000 0000\n\
      >> 5\n\
      0000 0001 - 1 & 0000 0001 = 1 0000 0001\n\
      >> 6\n\
      0000 0000 - 0 & 0000 0001 = 0 0000 0000\n\
\n\
    */\n\
    binary[7 - n] = (b >> n) & 1;\n\
  }\n\
  for (int n = 0; n < 8; n++)\n\
  {\n\
    printf('\%d', binary[n]);\n\
  }\n\
  printf('\\n');\n\
}\n\
\n\
                              A   B   C   D   E       F\n\
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, and 15\n\
\n\
HEX FUNCTIONS\n\
function toHex(d) {\n\
  var r = d \% 16;\n\
  if (d - r == 0) {\n\
    return toChar(r);\n\
  }\n\
  return toHex((d - r) / 16) + toChar(r);\n\
}\n\
\n\
function toChar(n) {\n\
  const alpha = '0123456789ABCDEF';\n\
  return alpha.charAt(n);\n\
}\n\
void to_hex(byte b)\n\
{\n\
  printf('0x\%X', b);\n\
}\n\
\n\
void trailing_zeros(byte b)\n\
{\n\
  int binary[8];\n\
  for (int n = 0; n < 8; n++)\n\
  {\n\
    binary[7 - n] = (b >> n) & 1;\n\
  }\n\
  printf('Binary Representation: ');\n\
  for (int n = 0; n < 8; n++)\n\
  {\n\
    printf('\%d', binary[n]);\n\
  }\n\
  printf('\n');\n\
  int i = 0;\n\
  for (int n = 0; n < 8; n++)\n\
  {\n\
    if (((b >> n) & 1) == 0)\n\
    {\n\
    i++;\n\
    }\n\
    else\n\
    {\n\
      break;\n\
    }\n\
  }\n\
  printf('Trailing Zeros: \%d', i);\n\
}\n\
\n\
int checkOdd(int n)\n\
{\n\
  second version\n\
  n&1 is 1, then odd, else even\n\
  return (!(n & 1));\n\
}\n\
Returns true if n is even, else odd\n\
X 	Y 	X^Y\n\
0 	0 	0\n\
0 	1 	1\n\
1 	0 	1\n\
1 	1 	0\n\
int checkEven(int n)\n\
{\n\
    n^1 is n+1, then even, else odd\n\
ex:\n\
10 - 0000 1010 ^ 0000 0001 = 0000 1011 (11)\n\
10+1 = 11\n\
equal == even\n\
\n\
ex2:\n\
9 - 0000 1001 ^ 0000 0001 = 0000 1000 (8)\n\
9 + 1 = 10\n\
not equal == odd\n\
\n\
ex3:\n\
9 - 1000 0000 ^ 0000 0001 = 1000 0001 (129)\n\
128 + 1 = 129\n\
equal == even\n\
if (n ^ 1 == n + 1)\n\
{\n\
    return 1; true\n\
}\n\
else\n\
{\n\
    return 0; false\n\
}\n\
}\n\
\n\
void count_one_n_zero(byte b)\n\
{\n\
  int binary[8];\n\
  for (int n = 0; n < 8; n++)\n\
  {\n\
    binary[7 - n] = (b >> n) & 1;\n\
  }\n\
  printf('Binary Representation: ');\n\
  for (int n = 0; n < 8; n++)\n\
  {\n\
     printf('\%d', binary[n]);\n\
  }\n\
  printf('\\n');\n\
  int one = 0;\n\
  int zero = 0;\n\
  for (int n = 0; n < 8; n++)\n\
  {\n\
    if (((b >> n) & 1) == 0)\n\
    {\n\
    zero++;\n\
    }\n\
    else\n\
    {\n\
      one++;\n\
    }\n\
  }\n\
  printf('Number of 1s: \%d\\n', one);\n\
  printf('Number of 0s: \%d\\n', zero);\n\
}\n\
\n\
void highest_order_bit(byte b)\n\
{\n\
  int binary[8];\n\
  for (int n = 0; n < 8; n++)\n\
  {\n\
    binary[7 - n] = (b >> n) & 1;\n\
  }\n\
  printf('Binary Representation: ');\n\
  for (int n = 0; n < 8; n++)\n\
  {\n\
    printf('\%d', binary[n]);\n\
  }\n\
  printf('\\n');\n\
  int i = 7;\n\
  for (int n = 1; n < 9; n++)\n\
  {\n\
    if (binary[n-1] == 1)\n\
    {\n\
      i = n;\n\
      break;\n\
    }\n\
  }\n\
  }\n\
  printf('Highest Order Bit: \%d\\n', i);\n\
  }\n\
}\n\
\n\
\n\
#include <stdio.h>\n\
\n\
void highest(int);\n\
int main()\n\
{\n\
  int input;\n\
  printf('What's the number: ');\n\
  scanf('\%d', &input);\n\
  highest(input);\n\
  return 0;\n\
}\n\
\n\
void highest(int input)\n\
{\n\
  int highest;\n\
  for (int i = 0; i < 8; i++)\n\
  {\n\
    if ((input >> i) & 1)\n\
    {\n\
      highest = i;\n\
    }\n\
  }\n\
  printf('highest: \%d', highest);\n\
  printf('\\n0 : \%d', (7 >> 0) & 1);\n\
  printf('\\n1 : \%d', (7 >> 1) & 1);\n\
  printf('\\n2 : \%d', (7 >> 2) & 1);\n\
  printf('\\n3 : \%d', (7 >> 3) & 1);\n\
  printf('\\n4 : \%d', (7 >> 4) & 1);\n\
}\n\
\n ");
  }
  else if (strcmp("pthreads", arg) == 0)
  {
    printf("\n\
Thread Function
========================================================================================================================= //

#include <pthread.h> thread lib
#include <stdlib.h> standard lib for malloc
#include <stdio.h> for printf and sprintf
#include <string.h> for strcmp

#include 'common.h' common header file

function declarations
void *worker(void *);

mutex init (to lock and unlock threads)
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int completed = 0; number of completed tasks
int n_args;        number of provided args

main function
int thread_prime(int argc, char *argv[])
{
  n_args = argc - 1;         args -1 accounting for argv[0] being the file name
  char *tasks[n_args];       init results of tasks
  pthread_t threads[n_args]; array of threads corresponding to argc-1
  int th_code;               thread return code

  loop through and create the threads
  for (int i = 1; i < argc; i++)
  {
    create thread
    th_code = pthread_create(&threads[i], NULL, worker, (void *)argv[i]);
    if (th_code < 0) check if error
    {
      print err and code if unable to make thread
      printf('Error: unable to create thread, %d\n', th_code);
      exit with error code 1
      exit(1);
    }
  }
  loop through and join the threads
  for (int i = 1; i < argc; i++)
  {

    void *return_val; return value holder
    join thread
    th_code = pthread_join(threads[i], &return_val);
    if (th_code < 0) check if error
    {
      print err and code if unable to join thread
      printf('Error: unable to create thread, %d\n', th_code);
      exit with error code 1
      exit(1);
    }

    char *str = malloc(100);
    sprintf(str, '%d - %s\n', atoi(argv[i]), (char *)return_val);
    tasks[i] = str;
  }
  int i; declare i
  loop through and print the results
  for (i = 0; i <= n_args; i++)
  {
    printf('%s', tasks[i]); print result
  }
  pthread_exit(NULL); exit main thread
}

threads job function
void *worker(void *argument)
{
  pthread_mutex_lock(&lock);                   lock the thread

  char *return_val = malloc(sizeof(argument)); allocate space for return_value
  char *arg;                                   char pointer for argument (still void pointer)
  arg = (char *)argument;                      cast void pointer to char * so we can access arg
  int v = atoi(arg);                           change string to int
  if (isPrime(v) == 0)                         if the result of isPrime is 0 its prime
  {
    strcpy(return_val, 'Prime'); put Prime in return_val
  }
  else if the result of isPrime is 1 its not prime
  {
    strcpy(return_val, 'Not Prime'); put Not Prime in return_val
  }
  completed++; incremented completed tasks
  printf('%d out of %d numbers checked\n', completed, n_args);
  pthread_mutex_unlock(&lock); unlock the thread
  pthread_exit(return_val);    close thread
}

/*
Question 3: Multithreaded elevator – 8 points
Create a multithreaded elevator program. The main thread should be responsible for the interaction
between the user and the elevator. The child thread should control the elevator’s movement.
The elevator should move between 0 and MAX floors (MAX is defined by you, should be between 10
and 20). The travel time between each floor is 1 second. When the elevator reaches the desired
floor, a message is printed on the console. When the elevator moves between the floors, a message
with the elevator’s position should be printed to the console when passing a floor and once in￾between every floor.
The user can choose the floor where he/she wants to travel only when the elevator is waiting at one
of the floors. When the user chooses a new floor while the elevator is in motion (moving to the
destination floor), an error message should be printed.
The user can always choose to print the status of the elevator. The output of the status should be:
waiting_for_user or moving. */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> //header imported to use the random function and malloc
#include <time.h>   //header imported to use the random function

#define MAX 20

void *elevator(void *param);
void *movement(void *);
int acquireFloor(int min, int m);
void clear_stdin();

pthread_mutex_t movingSem = PTHREAD_MUTEX_INITIALIZER;
int currentFloor = 0;
int destination = 0;
int moving = 0;

int main()
{
  pthread_t thread;
  if (pthread_create(&thread, NULL, movement, NULL))
  {
    printf('error creating thread\n');
    return -1;
  }

  printf('-1 : print status \n 0-%d: to select a floor\n\n', MAX);

  while (1)
  {
    int input = acquireFloor(-1, MAX); prints user prompt for input to console

    pthread_mutex_lock(&movingSem);
    if (input == -1)
    {
      if (moving)
      {
        printf('status: Moving');
      }
      else
        printf('status: waiting for user input');
    }
    else
    {
      if (moving == 1)
      {
        printf('the elevator is already moving');
      }
      else
      {
        moving = 1;
        destination = input;
      }
    }
    pthread_mutex_unlock(&movingSem);
  }
  pthread_join(thread, NULL);
}

void *movement(void *param)
{
  while (1)
  {
    pthread_mutex_lock(&movingSem);
    if (moving)
    {
      printf('\nCurrent floor:%d', currentFloor);
      if (destination > currentFloor)
      {
        currentFloor++;
      }
      else if (destination < currentFloor)
      {
        currentFloor--;
      }
      else
      {
        printf('Arrived\n');
        moving = 0;
      }
    }
    pthread_mutex_unlock(&movingSem);
    sleep(1);
  }

  pthread_exit(NULL);
}

the following function is from my group (2), IT WAS ALSO ORIGINALLY WRITTEN BY ME IN ONE OF THE LABS (one of the first labs, i don't remember which).
what it does it's just safely acquire a value between min and max, if this is considered plagmarism, a scanf does the same as this function it's does not check the values though
int acquireFloor(int min, int m)
{

  int inputVal; acquired val

  char endLine;       to check if the value insered is actually an integer
  int wrongInput = 0; a 'boolean' value to keep track of the (wrong) user input

  do
  {
    the input is not yet wrong
    wrongInput = 0;
    asking the user to insert a value

    acquiring the user answer inputVal, and also acquiring a new line character to make sure an integer is insered
    if (scanf('%d%c', &inputVal, &endLine) != 2 || endLine != '\n')
    {
      clean the input buffer after reading the input
      clear_stdin();
      printing an error message to the user
      perror('\n**ERROR: unexpected value in input**\n');
      the value insered is not correct, so wrongInput=1;
      wrongInput = 1;
    }

    the user is asked to insert a coordinate value untill it's a value between min and max (and it's a number, the last condition in the do-while guard checks this)
  } while ((inputVal > m || inputVal < min) || wrongInput == 1);

  returning the value read
  return inputVal;
}
to clear the stdin buffer since fflush on unix doesn't work
void clear_stdin()
{
  //'moving' forward the pointer related with the stdin buffer, until \n
  while (getchar() != '\n')
  {
    ;
  }
}
\n ');
  }
  else if (strcmp('threads', arg) == 0)
  {
    printf('\n\

\n ');
  }
  else if (strcmp('threads', arg) == 0)
  {
    printf('\n\

\n ");
  }
  return 0;
  }