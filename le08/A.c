#include <stdlib.h>
#include <stdio.h>

struct node
{
  struct node *right;
  struct node *left;
  struct node *parent;
  int key;
};
typedef struct node *Node;
#define NIL NULL

Node root;

// Node treeMinimum(Node x)
// {
// }

// Node treeMaximum(Node x)
// {
// }

// Node treeSearch(Node u, int k)
// {
// }

// Node treeSuccessor(Node x)
// {
// }

// void treeDelete(Node z)
// {
//   Node y; // node to be deleted
//   Node x; // child of y
// }

void insert(int k)
{
  Node y = NIL;
  Node x = root;
  Node z;

  z = malloc(sizeof(struct node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  // find parent
  while (x != NIL)
  {
    y = x;
    x = k < x->key ? x->left : x->right;
  }
  z->parent = y;

  // insert to left or right of the parent
  if (y == NIL)
    root = z;
  else if (z->key < y->key)
    y->left = z;
  else
    y->right = z;
}

void inOrder(Node u)
{
  if (u->left != NIL)
    inOrder(u->left);

  printf(" %d", u->key);

  if (u->right != NIL)
    inOrder(u->right);
}

void preOrder(Node u)
{
  printf(" %d", u->key);

  if (u->left != NIL)
    preOrder(u->left);

  if (u->right != NIL)
    preOrder(u->right);
}

int main()
{
  int n, i, x;
  char com[20];
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    scanf("%s", com);
    // if (com[0] == 'f')
    // {
    //   scanf("%d", &x);
    //   Node t = treeSearch(root, x);
    //   if (t != NIL)
    //     printf("yes\n");
    //   else
    //     printf("no\n");
    // }
    if (com[0] == 'i')
    {
      scanf("%d", &x);
      insert(x);
    }
    else if (com[0] == 'p')
    {
      inOrder(root);
      printf("\n");
      preOrder(root);
      printf("\n");
    }
    // else if (com[0] == 'd')
    // {
    //   scanf("%d", &x);
    //   treeDelete(treeSearch(root, x));
    // }
  }

  return 0;
}