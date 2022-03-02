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
  p = malloc(sizeof(Node)); // modified (doesnt need to be a Node *ptr)

  // store the value
  p->data = val;

  // Left and right child for node
  // will be initialized to null
  p->left = NULL;
  p->right = NULL;

  // return the new node
  return p;
}



// =================== added =================== //

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(Node *root, int space)
{
  // Base case
  if (root == NULL) {
    return;
  }

  // Increase distance between levels
  space += 10;

  // Process right child first
  print2DUtil(root->right, space);

  // Print current node after space
  // count
  printf("\n");
  for (int i = 10; i < space; i++)
    printf(" ");
  printf("%d\n", root->data);

  // Process left child
  print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Node *root)
{
  // Pass initial space count as 0
  print2DUtil(root, 0);
}


void DeleteNode(Node *root, int val)
{
  if (root == NULL)
  {         // Base Cases: root is null
    return; // escape
  }
  if (root->data == val)
  {                   // this node does contain the value to delete
    deleteTree(root); // destroy this portion of the tree
    return;           // escape
  }
  else // only need to go into the else if we arn't deleting the entire tree anyway
  {
    if (root->left)
    {                              // we can keep searching
      DeleteNode(root->left, val); // recursivesly search
    }
    if (root->right)
    {                               // we can keep searching
      DeleteNode(root->right, val); // recursivesly search
    }
  }
}
// helper method for deleting a tree
// recursively delete a tree from the respective node passed
void deleteTree(Node *root)
{
  if (root == NULL) {
    return;
  }
    // if the node is not null
    deleteTree(root->right);    // go down a level (and add to stack)
    deleteTree(root->left);     // go down a level (and add to stack)
    free(root);                 // we are at the end start freeing and popping off the stack
}
// ============================================= //

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
  // root->left = CreateNode(7);
  // root->right = CreateNode(7);
  // and one more sub-tree
  ((Node *)root->left)->left = CreateNode(68);
  ((Node *)root->right)->left = CreateNode(1);
  print2D(root);
  deleteTree(root);
  printf("Current State of Tree\n");
  if (root) {
    free(root);
  }
  print2D(root);
  printf("Exiting program.\n");
  return 0;
}