#include "common.h"

void InsertFirst(struct node_t **head_ref, Person *p)
{
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
