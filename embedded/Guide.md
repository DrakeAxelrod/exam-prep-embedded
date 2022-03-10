# Embedded

## C

### Structs

```c

typedef struct name {
  int n;
  char *str;
} Identifer;
```

### types

| Data Type              | Memory (bytes) | Range                           | Format Specifier |
| ---------------------- | -------------- | ------------------------------- | ---------------- |
| short int              | 2              | -32,768 to 32,767               | %hd              |
| unsigned short int     | 2              | 0 to 65,535                     | %hu              |
| unsigned int           | 4              | 0 to 4,294,967,295              | %u               |
| int                    | 4              | -2,147,483,648 to 2,147,483,647 | %d               |
| long int               | 4              | -2,147,483,648 to 2,147,483,647 | %ld              |
| unsigned long int      | 4              | 0 to 4,294,967,295              | %lu              |
| long long int          | 8              | -(2^63) to (2^63)-1             | %lld             |
| unsigned long long int | 8              | 0 to 18,446,744,073,709,551,615 | %llu             |
| signed char            | 1              | -128 to 127                     | %c               |
| unsigned char          | 1              | 0 to 255                        | %c               |
| float                  | 4              |                                 | %f               |
| double                 | 8              |                                 | %lf              |
| long double            | 16             |                                 | %Lf              |


# OS Lecture

## A process in Memory
• Multiple parts:
• Stack containing temporary data
• Function parameters, return addresses, local variables, etc.
• Heap containing memory dynamically allocated during run time
• Data section containing global variables
• The program code, also called text section

> One brain...many processes
• Multiple instances (of multiple programs) 
could be run even when CPU had a single 
core. 
• If the “brain” can only run one instruction at 
the time (i.e., one process at the time), how 
is that possible?
Let’s assume our computer has 

> Process Control Block (PCB)
Keeping track of what is going on. Information associated with each process in the OS.
• Process state: running, waiting, etc.
• Program counter: location of next instruction to execute
• CPU registers: contents of all process-centric registers
• CPU scheduling information: priorities, scheduling queue pointers
• Memory-management information: memory allocated to the process
• Accounting information: CPU used, clock time elapsed since 
start, time limits
• I/O status information: I/O devices allocated to process, list of open files

> Process states
What are the possible states of a process? As a process executes, it changes state
• new: The process is being created
• ready: The process is waiting to be assigned to a processor
• running: Instructions are being executed
• waiting: The process is waiting for some event to occur
• terminated: The process has finished execution

>Process scheduling
How does the operating system keep track of the different running processes?

Several processes could be waiting for some I/O and several processes could be ready for execution. 
• Using queues, the OS can organise and decide which process to execute next.
• The OS only needs to look at the PCBs in the ready queue.
• A process can transitions through several states:
• Once in the ready queue, the process is at some point given CPU time.
• There are different ways how to process might return to the ready queue.

> One process, many threads

• Take a word processor for example:
• It is one program, but many tasks run at the same time.
• Process keyboard inputs
• Run spell checker
• Print a document
• Automatically save the file
• ...

## Threads
> Divide et impera...
• One process can contain multiple threads of execution.
• Multiple threads can exist for the same process.
• Consider having multiple program counters per process.
• Multiple threads can run on different cores, if we have more than one core (which is kind of standard today), or you perform “context switching”.
• Multiple locations can execute at once.
• Multiple threads of control.
• Must then have storage for thread details, multiple program counters in PCB.

> Multithreaded Processes Pro and Cons
• + Responsiveness – may allow continued execution if part of process is blocked, especially important for user interfaces.
• + Resource Sharing – threads share resources of process, easier than shared memory or message passing.
• + Economy – cheaper than process creation.
• + Scalability – process can take advantage of multiprocessor architectures.
• - Costs - Parts of the process that are thread-specific (the stack, for instance, with the local variables of the function a thread is executing) need to be duplicated.

> Scheduling strategies
The attributes of a process scheduling policy are a combination of the following:
• Fairness: make sure each process gets its fair share of the CPU.
• Efficiency: keep the CPU as busy as possible
• Response time: minimize the response time for interactive users.
• Turnaround: minimize the time batch users must wait for output
• Throughput: maximize the number of jobs processed per hour

> There are no scheduler implementations that are optimal in each of these attributes. There is always a trade-off. Many of these attributes can be contradictory.

> Types of scheduling strategies
• Preemptive scheduling
• Round-robin
• Priority scheduling
• shortest job first
• critical path
• Real-time
• Earliest deadline
• Fixed priority
• Cooperative / event driven
• Run to completion / non-preemptive

> Multicore Programming
• Multicore or multiprocessor systems put pressure on programmers, challenges include:
• Dividing activities
• Balance
• Data splitting
• Data dependency
• Testing and debugging

> Why is it challenging?
• We have a program: Serial portion S(25% of the program)
- How many times faster?
1 core → 100 cores
```
2x?
4x?
5x?
10x?
50x?
100x?
1000x?
```
*3.88x*

## Amdahl’s Law
• Identifies performance gains from adding additional cores to an application.
• The application has both serial and parallel components
• S is serial portion
• N processing cores

> 𝑠𝑝𝑒𝑒𝑑𝑢𝑝 ≤ (1 (𝑆 + (1−𝑆 /𝑁)))

• That is, if application is 75% parallel / 25% serial, moving from 1 to 2 cores results in speedup of 1.6 times
• As N approaches infinity, speedup approaches 1 / S

Serial portion of an application has disproportionate effect on performance gained by adding additional core

## pthreads
> What is pthreads?
• POSIX threads, is a standardised (IEEE Std 1003.1b-1993) parallel execution model (i.e., indepedent from language and OS).
• Pthreads defines a set of C language tpyes, functions and constants. They can be included through the pthreads.h library.
• There are four categories of procedures:
1. Thread management (create, join, terminate, etc.),
2. Mutexes (i.e., locks and resource management),
3. Condition variables (i.e., monitors),
4. Synchronisation

```c
// summing 0 ... n
#include <pthread.h>
#include <stdio.h>

int sum; // this data is shared by the thread(s)
void* runner(void *params); // threads call this function

int main(int argc, char *argv[])
{
  pthread_t tid; // thread identifier
  pthread_att_t attr // set of thread attributes
  if (argc !=2)
  {
    fprintf(stderr, "usage: a.out <integer value>\n");
    return -1;
  }
  it(atoi(argv[1] < 0))
  {
    fprintf(stderr, "%d must be >= o\n", atoi(argv[1]));
    return -1;
  }
  // get the default attributes
  pthread_attr_init(&attr);
  // create the thread
  pthread_create(&tid, &attr, runner, argv[1]);
  // wait for the thread to exit
  pthread_join(tid, NULL);
  printf("sum = %d\n", sum);
}

// the thread will begin control in this function
void *runner(void *param)
{
  int i, upper = aoi(param);
  sum = 0;

  for (i = 1; i <= upper; i++)
  {
    sum += i;
  }

  pthread_exit(0);
}
```

## Dining Philosophers Problem
• N philosophers (P) are seated on a round table.
• There are N forks (F), which are placed around the table in a fashion that each philosopher has access to a fork to her/his right and left.
• To eat, a philosopher needs two forks
• Philosopher can have the following states:
• Thinking (happy and not eating)
• Eating
• Starving (after some thinking the philosopher gets hungry)

> Logical / virtual vs. physical address space
We can (usually) run a process independently of other processes that are already executing. How is it possible that there’s always enough free space in memory to load a program?

> Paging
Where is my (physical) memory?
• Mechanism that allows for the physical address space of a process to be non-contiguous
• Used in most modern Operating Systems (from mainframes to smartphones)
• Requires cooperation between OS and hardware

## Paging
> From logical address to physical address
• page/frame size is power of 2 → 2^n
• size of logical space is power of 2 → 2^m
Logical address (binary)
101101 001110110
 m-n       n
 page    offset

Page size = 22 = 4 (n=2)
Size of logical space = 24 = 16 (m=4)

01      11
page    offset
1       3

Frame 6 offset 3
→ 6x4 + 3 = 27

Cooking Recipe for converting logical address to physical address
1. Convert logical address to binary.
2. First m-n digits tell us the position of the frame number in the page table.
3. Last n digits is the offset.
4. Physical address is the sum of the frame number multiplied with page size and the offset.

## Virtual memory
> There are programs on disk that occupy more space than the main memory I have, how is it possible for me to run them? How is it possible to run them together with other processes?

• What would happen if the OS does not load page 3 into the physical memory?
• Is that always a problem?
• Maybe we can wait with loading page 3 into frame 7 until the process actually tries to access page 3.

> The trade-offs
• What are the costs / trade-offs / complications when executing partially-loaded 
programs:
• Need a mechanism to check if a page is in the frame or not
• Because of this mechanism, sometimes accessing a page might require more time than expected
• ... and more ...

> Valid-invalid bit
• What are the costs / trade-offs / complications when executing partially-loaded 
programs:
• With each page table entry a valid–invalid bit is associated (v => in-memory – memory resident, i => not-in-memory)
• Initially valid–invalid bit is set to i on all entries
• Example of a page table snapshot:
• During address translation, if valid–invalid bit in page table entry is i => page fault

> Page table with invalid bits set
Not all is where it seems to be...
• A process with 8 pages is partially loaded into memory.
• Page 0 is in frame 4 of the physical memory.
• Page 1 however is not yet loaded into memory.
• Accessing page 1 will cause a page fault.
===>page fault<===

> Handling page faults
It’s not a bug...it’s a feature!
20
1. If there is a (first) reference to an invalid page that page will trap towards the operating system: 
===>page fault<=== 

The following must happen:
Context switch from current process to the operating system.
2. Operating system looks at another table to decide:
  a) Invalid reference => abort 
  b) Just not in memory
3. Find free frame
4. Swap page into frame via scheduled disk operation
  2. Reset tables to indicate page now in memory Set validation bit = v
5. Restart the instruction that caused the page fault

> Malloc(), and let there be magic free memory...
• Lucky for you (as developer), you don’t have to worry about the details too much.
• malloc() in C negotiates memory allocation with the OS for you.

> Reading / writing blocks
We can’t do that all the time...

If we pay this price for each byte, we have a problem.

Because of this, the OS and the disk stipulate a minimum communication unit, the block, of a given size (e.g., 4 Kb)

> Block Size
Again there is trade-off...
Which is the appropriate size of a block?

Large block
+ : Less blocks to read (➔ faster 
reading)
- : More wasted space if files are small
Small block
+ : Less space wasted
- : More blocks to read (➔slower reading)

## Space allocation
> Contiguous allocation - Fragmentation
Keeping track of where the files are...

The operating system keeps track of which blocks are occupied by each file.

Three usual approaches:
1. Contiguous allocation
2. Linked-list allocation
3. Index -nodes

### +
• Need to maintain 2 numbers per file (first address, number of blocks).
• Read performance (single scan).
### -
- Fragmentation.
- New file size required in advance.

> Contiguous allocation - Fragmentation

|A|B|C|FREE|
|-|-|-| -- |

> Linked-list allocation
### +
• If loading Index-nodes only for opened files → Less memory needed.
• Memory needed proportional to the maximum number of open files.
### -
• Complex if file grows beyond number of addresses.

# I/O System


