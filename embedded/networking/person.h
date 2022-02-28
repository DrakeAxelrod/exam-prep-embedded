#ifndef PERSON_H_  // if then define
#define PERSON_H_  // define the header

#define MAX 20 // max number of chars

struct person
{
  char name[MAX];    // Person’s given name
  char surname[MAX]; // Person’s surname
  char pnr[MAX];     // Person’s social security number
  char address[MAX]; // Person’s city of residence
  int age;           // Person’s age
};

#endif // end if