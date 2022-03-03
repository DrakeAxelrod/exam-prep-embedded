#ifndef COMMON_H_ // header if
#define COMMON_H_ // define the header

typedef struct
{
  int iAge;
  char name[20];
  char address[20];
} struct_person;

#define MAX 20
typedef struct
{
  char sName[MAX];    // Person’s given name
  char sSurname[MAX]; // Person’s surname
  char sPnr[MAX];     // Person’s social security number
  char sAddress[MAX]; // Person’s city of residence
  int iAge;           // Person’s age
} Person;

typedef struct node_t
{
  struct node_t *next;    // pointer to the next node in the list.
  Person *person; // Data Payload (person)
};

void InsertFirst(struct node_t **, Person*);

#endif
