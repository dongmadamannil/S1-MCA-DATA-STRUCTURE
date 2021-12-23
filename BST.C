#include <stdio.h>
#include <stdlib.h>
struct node
{
  int d;
  struct node *llink, *rlink;
};
struct node *create(int d)
{
  struct node *newnode;
  newnode = ((struct node *)malloc(sizeof(struct node)));
  newnode->d = d;
  newnode->llink = NULL;
  newnode->rlink = NULL;
  return (newnode);
}
void inorder(struct node *ptr)
{
  if (ptr != NULL)
  {
    inorder(ptr->llink);
    printf("%d\n", ptr->d);
    inorder(ptr->rlink);
  }
}
void preorder(struct node *ptr)
{
  if (ptr != NULL)
  {
    printf("%d\n", ptr->d);
    preorder(ptr->llink);
    preorder(ptr->rlink);
  }
}

void postorder(struct node *ptr)
{
  if (ptr != NULL)
  {
    postorder(ptr->llink);
    postorder(ptr->rlink);
    printf("%d\n", ptr->d);
  }
}
int search_el(int key, struct node *ptr)
{
  int k = 0;
  if (ptr != NULL)
  {
    k = search_el(key, ptr->llink);
    if (ptr->d == key)
    {
      return 1;
    }
    k = search_el(key, ptr->rlink);
  }
  return k;
}
struct node *search_elem(int key, struct node *ptr) //findd data of given position
{
  struct node *k = NULL;
  if (ptr != NULL)
  {
    k = search_elem(key, ptr->llink);
    if (ptr->d == key)
    {
      return ptr;
    }
    k = search_elem(key, ptr->rlink);
  }
  return k;
}
int larget(struct node *ptr)
{ //largest
  while (ptr->rlink != NULL)
  {
    ptr = ptr->rlink;
  }
  return ptr->d;
}
int sml(struct node *ptr)
{ //smallest
  while (ptr->llink != NULL)
  {
    ptr = ptr->llink;
  }
  return ptr->d;
}
int inorder_sc(struct node *ptr, int key)
{
  struct node *tmp, *mn;
  mn = search_elem(key, ptr);
  if (mn == NULL)
  {
    return 0;
  }
  else
  {
    if (mn->rlink != NULL)
    {
      mn = mn->rlink;
      while (mn->llink != NULL)
      {
        mn = mn->llink;
      }
      return mn->d;
    }
    else
    {
      while (ptr->d != mn->d)
      {
        if (mn->d < ptr->d)
        {
          tmp = ptr;
          ptr = ptr->llink;
        }
        else
          ptr = ptr->rlink;
      }
      return tmp->d;
    }
  }
}
int main()
{
  struct node *root = NULL;
  struct node *temp, *newnode, *ptr;
  int c, elem, i, p, flag = 0;
  char ch;
  while (1)
  {
    printf("\nBinary search tree\n1.Creation\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search an element\n6.Find max\n7.Find min\n8.inorder successor\n9.Exit\nEnter your choice:");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
      do
      {
        printf("Enter the element to be inserted:");
        scanf("%d", &elem);
        newnode = create(elem);
        if (root == NULL)
          root = newnode;
        else
        {
          ptr = root;
          while ((ptr != NULL) && (flag == 0))
          {
            if (elem < ptr->d)
            {
              temp = ptr;
              ptr = ptr->llink;
            }
            else if (elem > ptr->d)
            {
              temp = ptr;
              ptr = ptr->rlink;
            }
            else
            {
              flag = 1;
              printf("Item already exist\n");
            }
          }
          if ((ptr == NULL) && (flag == 0))
          {
            if (temp->d > elem)
              temp->llink = newnode;
            else
              temp->rlink = newnode;
          }
        }
        flag = 0;
        printf("Do you want to continue(y/n)?");
        getchar();
        scanf("%c", &ch);
      } while (ch == 'y' || ch == 'Y');
      printf("BST is created\n");
      break;
    case 2:
      if (root != NULL)
      {
        inorder(root);
      }
      else
        printf("Empty\n");
      break;
    case 3:
      if (root != NULL)
      {
        preorder(root);
      }
      else
        printf("Empty\n");
      break;
    case 4:
      if (root != NULL)
      {
        postorder(root);
      }
      else
        printf("Empty\n");
      break;
    case 5:
      printf("Enter the element to search");
      scanf("%d", &elem);
      if (search_el(elem, root) == 0)
        printf("\n\nelemenst no found\n");
      else
        printf("\n\nElement found\n");
      break;
    case 6:
      printf("\n\nlargest data is %d\n", larget(root));
      break;
    case 7:
      printf("\n\nsmallest data is %d\n", sml(root));
      break;
    case 8:
      printf("Enter an elemenst");
      scanf("%d", &elem);
      elem = inorder_sc(root, elem);
      if (elem == 0)
      {
        printf("element not found");
      }
      else
      {
        printf("successor is %d", elem);
      }
      break;
    case 9:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}

//re-work on searching ,becouse its time complexity is high,understand its bst
