
>To convert the hex number 0X20 to decimal (or any other hexadecimal number for that matter), >you follow these steps:
>
>Step 1) Multiply the last digit by 1, Multiply the second to last digit by 16, Multiply the >third to the last digit by 16 x 16, Multiply the fourth to the last digit by 16 x 16 x 16, >Multiply the fifth to the last digit by 16 x 16 x 16 x 16 and so on until all the digits are >used.
>
>Step 2) Add up all the products you got from Step 1 to get the answer to 0X20 in decimal.
>
>Here is the math using using the steps above showing you how to convert 0X20 to decimal.
>
>0 x 1 = 0
>2 x 16 = 32
>
>0 + 32 = 32
>
>That is all there is to it. Here is the answer to 0X20 in decimal:
>
>32

# Question 4: Binary trees and memory allocation – 8 points 
> A 2 points): Draw the tree for each step of its creation in the procedure main, starting with line below /*create root*/.
```
/* create root */

      ( B ) (root)
      /   \
   NULL   NULL

/* create two sub-trees */

             ( B ) (root)
           /       \
         /           \
      ( 9 )         (0x20)
      /   \         /    \
   NULL   NULL   NULL    NULL

/* and one more sub-tree */

              ( B ) (root)
            /       \
          /           \
       ( 9 )         (0x20)
      /     \        /    \
   ( 68 )   NULL   ( 1 )  NULL
  /     \         /    \
NULL    NULL    NULL   NULL
```
> B (2 points): This program has a function to create a new node, but no function to delete a node. 
> Please write a function that deletes a node and all its sub-trees only if the node has a specific value (e.g. 1). 
```c
// recursively search the tree for a node that has the value to delete then call the deletetree method
void DeleteNode(Node *root, int val)
{
    if (root == NULL) {               // Base Cases: root is null
       return;                        // escape
    }
    if (root->data == val) {          // this node does contain the value to delete
      deleteTree(root);               // destroy this portion of the tree
      return;                         // escape
    }
    else // only need to go into the else if we arn't deleting the entire tree anyway
    {
      if (root->left) {               // we can keep searching
        DeleteNode(root->left, val);  // recursivesly search
      }
      if (root->right) {              // we can keep searching
        DeleteNode(root->right, val); // recursivesly search
      }
    }
}
// helper method for deleting a tree
// recursively delete a tree from the respective node passed
void deleteTree(Node *root) {
  if (root) {                         // if the node is not null
    deleteTree(root->left);           // go down a level (and add to stack)
    deleteTree(root->right);          // go down a level (and add to stack)
    free(root);                        // we are at the end start freeing and popping off the stack
  }
}
```
> C (2 points): This program is not fail-safe. For example, we can create a node that overwrites another node. 
> Please identify at least 3 different problems in this program and add the fail-safety checks for these problems.

1. A node can overwrite another node.
2. You can point a node backards thus creating a circle
3. You can have a node thats data is NULL and still points to nodes with values
4. Node had two void *pts which means you can basically put whatever you want in them. (either a problem or a feature depending...)

```c
/*
 * This program demonstrates the data structure of a binary tree
 * Your task is specified in the exam
 */
#include <stdio.h>
#include <stdlib.h>

// This is one node of the tree
typedef struct
{
  int data;    // data which is stored in the node
  void *left;  // pointer to the left sub-tree
  void *right; // pointer to the right sub-tree
} Node;

/*
 * This function creates an empty nde
 */
Node *CreateNode(int val)
{
  Node *p; // pointer to the new node

  // create the node
  p = (Node *)malloc(sizeof(Node));

  // store the value
  p->data = val;

  // Left and right child for node
  // will be initialized to null
  p->left = NULL;
  p->right = NULL;

  // return the new node
  return p;
}

/*
 * Main - create a simple tree
 */
int main()
{

  /*create root*/
  Node *root = CreateNode((int)'B');

  // create two sub-trees
  root->left = CreateNode('9');
  root->right = CreateNode(0x20);

  // and one more sub-tree
  ((Node *)root->left)->left = CreateNode(68);
  ((Node *)root->right)->left = CreateNode(1);

  return 0;
}
```