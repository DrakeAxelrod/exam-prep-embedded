#include "common.h"
#include <stdlib.h>



// void InsertFirst(struct node_t **head_ref, Person *p)
void InsertFirst(struct node_t **head_ref, char *name, char *surname, char *pnr, char *addr, int age)
{

  Person *p = (Person *)malloc(sizeof(Person));
  strcpy(p->sName, name);
  strcpy(p->sSurname, surname);
  strcpy(p->sPnr, pnr);
  strcpy(p->sAddress, addr);
  p->iAge = age;

  struct node_t *n = (struct node_t *)malloc(sizeof(struct node_t));
  n->person = p;
  // point it to old first node
  n->next = *head_ref;
  // point first to new first node
  n->next = *head_ref;
  *head_ref = n;
}

// delete first item
struct node_t *deleteFirst(struct node_t **head_ref)
{
  // save reference to head
  struct node_t *tmp = *head_ref;
  // make next head
  *head_ref = (*head_ref)->next;
  // return the tmp (value that was deleted)
  return tmp;
}

void printPerson(Person *p)
{
  printf("===== Entry =====\n");
  printf("Name: %s %s\n", p->sName, p->sSurname);
  printf("Age: %d\n", p->iAge);
  printf("Personal Number: %s\n", p->sPnr);
  printf("Address: %s\n", p->sAddress);
  printf("=================\n");
}

// display the list
void printList(struct node_t *head)
{
  struct node_t *ptr = head;
  // start from the beginning
  while (ptr != NULL)
  {
    printPerson(ptr->person);
    ptr = ptr->next;
  }
}
