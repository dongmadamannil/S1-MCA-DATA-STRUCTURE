// binary search tree

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *root;

void insert();
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
void main()
{
  int choice;
  while (1)
  {
    printf("\n 1.insert \n 2.inorder traversal \n 3.preorder traveral \n 4.postorder traversal \n enter the choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      insert();
      break;
    case 2:
      inorder(root);
      break;
    case 3:
      preorder(root);
      break;
    case 4:
      postorder(root);
      break;
    default:
      printf("\n enter a valid choice:");
    }
  }
}

void insert()
{
  int i, n, item;
  struct node *tmp, *q;
  printf("\n enter the number of nodes to be inserted in the bst:");
  scanf("%d", &n);

  for (i = 0; i < n; ++i)
  {
    printf("\n enter the item to be inserted:");
    scanf("%d", &item);
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = item;
    tmp->left = NULL;
    tmp->right = NULL;
    if (root==NULL)
    {
      root = tmp;
    }
    else
    {
      q = root;
      while (1)
      {
        if (tmp->data > q->data)
        {
          if (q->right == NULL)
          {
            q->right = tmp;
            break;
          }
          else
          {
            q = q->right;
          }
        }
        else
        {
          if (q->left == NULL)
          {
            q->left = tmp;
            break;
          }
          else
          {
            q = q->left;
          }
        }
      }
    }
  }
}

void preorder(struct node *t)
{
  if (t != NULL)
  {
    printf("\t%d", t->data);
    preorder(t->left);
    preorder(t->right);
  }
}

void inorder(struct node *t)
{
  if (t != NULL)
  {

    inorder(t->left);
    printf("\t%d", t->data);
    inorder(t->right);
  }
}

void postorder(struct node *t)
{
  if (t != NULL)
  {
    postorder(t->left);
    postorder(t->right);
    printf("\t%d", t->data);
  }
}
